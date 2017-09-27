#include "parser.h"
#include "minishell.h"

int		ft_listsize_quot(t_quot *quot)
{
	t_quot	*s;
	int		i;

	i = 0;
	s = quot;
	if (s != NULL)
	{
		while (s != NULL)
		{
			i++;
			s = s->next;
		}
	}
	return (i);
}

char	**ft_cmd_building(t_term *term, t_exec *exe)
{
	char		**tstr;
	t_quot		*s;
	int			i;

	s = exe->quot;
	tstr = NULL;
	if (s != NULL)
	{
		i = ft_listsize_quot(s);
//		ft_printf(0, "{bob%ibob}", i);fflush(stdout);
		if (!(tstr = (char **)malloc(sizeof(char *) * (i + 1))))
			return (NULL);
		i = 0;
		while (s != NULL)
		{
			tstr[i] = ft_strdup(s->arg);
			i++;
			s = s->next;
		}
		tstr[i] = NULL;
	}
	else
	{
		if (!(tstr = (char **)malloc(sizeof(char *) * (1))))
			return (NULL);
		tstr[0] = NULL;
	}
//	ft_printf(0, "{%s}", tstr[0]);
	return (tstr);
}

t_quot	*ft_add_arg(t_term *term)
{
	t_quot	*new;

	if (!(new = (t_quot *)malloc(sizeof(t_quot))))
		return (NULL);
	new->arg = ft_strsub(term->line, term->p[0], term->p[1]);
	new->next = NULL;
	return (new);
}

t_exec	*ft_build_quot(t_term *term, t_exec *exe)
{
	t_quot	*p;

	p = exe->quot;
	if (p != NULL)
	{
		while (p->next != NULL)
			p = p->next;
		p->next = ft_add_arg(term);
	}
	else
		exe->quot = ft_add_arg(term);
	return (exe);
}
/*
t_quot	*ft_parse_in_arg(char *line)
{
	
}
*/
