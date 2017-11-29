/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 10:11:29 by nbeny             #+#    #+#             */
/*   Updated: 2017/05/20 10:11:32 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void	ft_free_exe(t_exec *exe)
{
	t_exec	*s;
	t_exec	*f;

	s = exe;
	if (exe != NULL)
		while (s != NULL)
		{
			f = s;
			if (s->cmd)
				ft_free_tabstr(s->cmd);
//			if (s->c)
//				ft_free_c(s->c);
			if (s->quot)
				ft_free_quot(s->quot);
			if (s->red)
				ft_free_red(s->red);
			s = s->next;
			free(f);
			exe = NULL;
		}
}

void	ft_free_c(t_cmd *c)
{
	t_cmd	*s;
	t_cmd	*f;

	s = c;
	if (c != NULL)
	{
		while (s != NULL)
		{
			f = s;
			ft_strdel(&(s->str));
			s = s->next;
			free(f);
			f = NULL;
		}
	}
}

void	ft_free_env(t_env *e)
{
	t_env *s;
	t_env *f;

	s = e;
	if (e != NULL)
	{
		while (s != NULL)
		{
			f = s;
			ft_strdel(&(s->name));
			ft_strdel(&(s->value));
			s = s->next;
			free(f);
			f = NULL;
		}
	}
}

t_env	*ft_free_oneenv(t_env *e, t_env *s, t_env *b)
{
	t_env	*n;

	n = s->next;
	if (b->next == NULL)
	{
		if (s != NULL && e != NULL)
		{
			ft_strdel(&(s->name));
			ft_strdel(&(s->value));
			e = e->next;
			free(s);
			s = NULL;
		}
	}
	if (s != NULL && b != NULL)
	{
		ft_strdel(&(s->name));
		ft_strdel(&(s->value));
		b->next = n;
		free(s);
		s = NULL;
	}
	return (e);
}

void	ft_free_tabstr(char **tstr)
{
	int		i;

	i = 0;
	if (tstr != NULL)
	{
		if (tstr[i] != NULL)
			while (tstr[i] != NULL)
			{
				ft_strdel(&tstr[i]);
				tstr[i] = NULL;
				i++;
			}
		free(tstr);
		tstr = NULL;
	}
}
