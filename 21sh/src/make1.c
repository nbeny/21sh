/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:15:06 by nbeny             #+#    #+#             */
/*   Updated: 2017/12/06 15:15:08 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

t_env	*make_numeric_and(t_term *term, t_exec *exe, t_env *e)
{
	char	*str;

	str = NULL;
	if (exe->red != NULL)
	{
		save_fd(exe);
		e = make_redirection(term, exe, e);
	}
	if (exe->error != NULL)
		return (e);
	if (ft_isbultin(exe, e))
		e = make_bultin(exe, e);
	else if (!ft_strncmp(exe->cmd[0], "./", 2) ||\
				!ft_strncmp(exe->cmd[0], "/", 1))
		ft_execute_fd(exe, e);
	else if ((str = ft_path_istrue(exe->cmd, e)))
		ft_execute_path_fd(str, exe, e);
	else
	{
		ft_printf(2, "command not found: %s\n", exe->cmd[0]);
		exe->error = ft_strdup("\0");
	}
	if (exe->red != NULL)
		reload_fd(exe);
	return (e);
}

t_env	*make_pipe(t_term *term, t_exec *exe, t_env *e)
{
	t_exec	*s;
	char	*str;
	t_nb	nb;

	str = NULL;
	s = exe;
	s = ft_do_pipe(term, s, &nb, e);
	return (e);
}
