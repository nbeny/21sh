/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:16:13 by nbeny             #+#    #+#             */
/*   Updated: 2017/12/06 15:16:14 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

char	*get_mask(int a, int b, int c, int d)
{
	char *s;

	if (!(s = (char *)malloc(sizeof(char) * 5)))
		return (NULL);
	s[0] = a;
	s[1] = b;
	s[2] = c;
	s[3] = d;
	s[4] = '\0';
	return (s);
}

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
	if (s != NULL)
	{
		i = ft_listsize_quot(s);
		if (!(tstr = (char **)malloc(sizeof(char *) * (i + 1))))
			return (NULL);
		i = 0;
		while (s != NULL)
		{
			tstr[i++] = ft_strdup(s->arg);
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
