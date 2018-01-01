/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:17:35 by nbeny             #+#    #+#             */
/*   Updated: 2017/12/06 15:17:36 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	free_cmd_str(char **cmd)
{
	int		i;

	i = 0;
	while (cmd[i])
	{
		ft_strdel(&cmd[i]);
		i++;
	}
	free(cmd);
	cmd = NULL;
}

void	free_list_cmd_str(t_cmd *c)
{
	t_cmd	*s;
	t_cmd	*f;

	s = c;
	while (s)
	{
		f = s;
		ft_strdel(&(s->str));
		s = s->next;
		free(f);
		f = NULL;
	}
}

t_cmd	*add_cmd_str(t_cmd *c, char *str)
{
	t_cmd	*s;

	s = c;
	if (c != NULL)
	{
		while (s->next != NULL)
			s = s->next;
		if (!(s->next = (t_cmd *)malloc(sizeof(t_cmd))))
			return (NULL);
		s = s->next;
		s->str = NULL;
		s->next = NULL;
		s->str = ft_strdup(str);
	}
	else
	{
		if (!(c = (t_cmd *)malloc(sizeof(t_cmd))))
			return (NULL);
		c->str = NULL;
		c->next = NULL;
		c->str = ft_strdup(str);
	}
	return (c);
}

char	**ft_list_to_tab_cmd(t_cmd *e)
{
	char	**tstr;
	t_cmd	*s;
	int		i;

	s = e;
	if (e == NULL)
		return (NULL);
	i = ft_listsize_cmd(e);
	if (!(tstr = (char **)malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	i = 0;
	while (s != NULL)
	{
		tstr[i] = ft_strdup(s->str);
		i++;
		s = s->next;
	}
	tstr[i] = NULL;
	return (tstr);
}

t_cmd	*ft_tab_to_list_cmd(char **env)
{
	t_cmd	*e;
	t_cmd	*s;
	int		i;

	i = 1;
	if (env == NULL || env[0] == NULL)
		return (NULL);
	if (!(e = (t_cmd *)malloc(sizeof(t_cmd))))
		return (NULL);
	e->str = ft_strdup(env[0]);
	s = e;
	while (env[i] != NULL)
	{
		if (!(s->next = (t_cmd *)malloc(sizeof(t_cmd))))
			return (NULL);
		s = s->next;
		s->str = ft_strdup(env[i]);
		i++;
	}
	s->next = NULL;
	return (e);
}
