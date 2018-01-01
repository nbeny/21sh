/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 10:11:16 by nbeny             #+#    #+#             */
/*   Updated: 2017/05/20 10:11:18 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_env	*ft_moove_env(t_env *e, char *str, int i)
{
	t_env	*s;

	s = e;
	if (e != NULL)
	{
		while (s != NULL)
		{
			if (!ft_strncmp(s->name, str, i))
				return (s);
			s = s->next;
		}
	}
	return (NULL);
}

t_env	*ft_env_opt_i(t_env *e, int size)
{
	t_env	*s;
	t_env	*b;
	t_env	*f;
	int		i[2];

	s = e;
	b = e;
	f = e;
	i[0] = 0;
	i[1] = ft_listsize(e);
	if (e && size != 0)
	{
		while (s->next != NULL && i[0]++ != (i[1] - size))
			s = s->next;
		i[0] = 0;
		while (b->next != NULL && i[0]++ != (i[1] - size - 1))
			b = b->next;
		b->next = NULL;
		ft_free_env(s);
	}
	s = NULL;
	return (s);
}

t_env	*ft_add_env(t_exec *exe, t_env *e, int i, int size)
{
	char	*str;

	str = ft_strsub(exe->cmd[i], 0, (size - 1));
	e = ft_list_push_back(e, str, &(exe->cmd)[i][size]);
	ft_strdel(&str);
	exe->i[2] += 1;
	return (e);
}

t_env	*ft_create_elem(char *name, char *value)
{
	t_env *env;

	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	if (name == NULL)
		env->name = ft_strdup("\0");
	else
		env->name = ft_strdup(name);
	if (value == NULL)
		env->value = ft_strdup("\0");
	else
		env->value = ft_strdup(value);
	env->next = NULL;
	return (env);
}

t_env	*ft_list_push_back(t_env *begin_list, char *name, char *value)
{
	t_env	*tmp;
	t_env	*elem;

	elem = ft_create_elem(name, value);
	if (begin_list)
	{
		tmp = begin_list;
		while (tmp->next && tmp->next->name != NULL)
			tmp = tmp->next;
		tmp->next = elem;
	}
	else
		return (elem);
	return (begin_list);
}
