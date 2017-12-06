/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:14:01 by nbeny             #+#    #+#             */
/*   Updated: 2017/12/06 15:14:02 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

static t_exec	*ft_close_fd(t_exec *e)
{
	if (e->fd.ffd0)
		close(0);
	if (e->fd.ffd1)
		close(1);
	if (e->fd.ffd2)
		close(2);
	return (e);
}

void			ft_execute_fd(t_exec *exe, t_env *e)
{
	pid_t		pid;
	pid_t		w;
	int			status;
	char		**env;
	char		*s;

	pid = fork();
	signal(SIGINT, sig_exe);
	s = ft_string_return(e, exe->cmd);
	env = ft_list_to_tab(e);
	if (pid == -1)
		exit(EXIT_FAILURE);
	else if (pid == 0)
	{
		exe = ft_close_fd(exe);
		status = execve(s, exe->cmd, env);
		if (kill(pid, SIGINT) == -1)
			exit(status);
		exit(status);
	}
	if ((w = waitpid(pid, &status, WCONTINUED)) == -1)
		exit(EXIT_FAILURE);
	ft_free_tabstr(env);
	ft_strdel(&s);
}

void			ft_execute_path_fd(char *str, t_exec *exe, t_env *e)
{
	pid_t		pid;
	pid_t		w;
	int			status;
	char		**env;

	pid = fork();
	signal(SIGINT, sig_exe);
	env = ft_list_to_tab(e);
	if (pid == -1)
		exit(EXIT_FAILURE);
	else if (pid == 0 && !access(str, X_OK))
	{
		exe = ft_close_fd(exe);
		status = execve(str, exe->cmd, env);
		if (kill(pid, SIGINT) == -1)
			exit(status);
		exit(status);
	}
	if ((w = waitpid(pid, &status, WCONTINUED)) == -1)
		exit(EXIT_FAILURE);
	ft_free_tabstr(env);
	ft_strdel(&str);
}
