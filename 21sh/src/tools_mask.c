#include "21sh.h"

char	*ft_add_path(char *path, char *file)
{
	char	*new;
	char	*tmp;

	tmp = ft_strjoin(path, "/");
	new = ft_strjoin(tmp, file);
	ft_strdel(&tmp);
	return (new);
}

t_env	*boucle_numeric_or(t_term *term, t_exec *exe, t_env *e)
{
	t_exec	*s;

	s = exe;
	while (s && s->mask && s->mask[0] == '|' && \
		s->mask[1] == '|')
	{
		e = make_numeric_or(term, s, e);
		if (s->error != NULL)
			while (s && s->mask && s->mask[0] == '|' && \
				s->mask[1] == '|')
			{
				s = s->next;
			}
	}
	return (e);
}

t_env	*boucle_numeric_and(t_term *term, t_exec *exe, t_env *e)
{
	t_exec	*s;

	s = exe;
	while ((s && !ft_strncmp(s->mask, "&&\0", 3)))
	{
		e = make_numeric_and(term, s, e);
		if (s->error != NULL)
		{
			ft_strdel(&(s->error));
			while (s && !ft_strncmp(s->mask, "&&\0", 3))
				s = s->next;
		}
	}
	return (e);
}

t_env	*boucle_pipe(t_term *term, t_exec *exe, t_env *e)
{
	t_exec	*s;

	s = exe;
	while (s && s->mask && s->mask[0] == '|' && \
		s->mask[1] == '\0')
	{
		e = make_pipe(term, s, e);
		ft_printf(2, "%s\n", s->error);
		if (s->error == NULL)
			while (s && s->mask && s->mask[0] == '|' && \
				s->mask[1] == '\0')
			{
				s = s->next;
			}
	}
	return (e);
}
