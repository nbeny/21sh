/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 10:11:24 by nbeny             #+#    #+#             */
/*   Updated: 2017/05/20 10:11:25 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

char	*ft_path_istrue(char **cmd, t_env *e)
{
	t_env	*s;
	char	*tmp;
	char	*test;
	char	**path;
	int		i;

	i = 0;
	test = NULL;
	s = ft_moove_env(e, "PATH\0", 5);
	if (s != NULL)
	{
		path = ft_strsplit(s->value, ':');
		tmp = ft_strjoin("/", cmd[0]);
		while (path[i] != NULL)
		{
			test = ft_strjoin(path[i], tmp);
			if (!access(test, X_OK))
				break ;
			ft_strdel(&test);
			i++;
		}
		ft_free_tabstr(path);
		ft_strdel(&tmp);
	}
	return (test);
}

void	ft_execute_path(char *str, char **cmd, t_env *e)
{
	pid_t	pid;
	pid_t	w;
	int		status;
	char	**env;

	pid = fork();
//	ft_printf(2, "exepath %i\n", pid);
	signal(SIGINT, sig_exe);
	env = ft_list_to_tab(e);
	if (pid == -1)
		exit(EXIT_FAILURE);
	else if (pid == 0 && !access(str, X_OK))
	{
//		ft_printf(2, "%s, %s, %s\n", str, cmd[0], env[0]);
		status = execve(str, cmd, env);
		if (kill(pid, SIGINT) == -1)
			exit(status);
		exit(status);
	}
	else
	{
		w = waitpid(pid, &status, WCONTINUED);
		if (w == -1)
			exit(EXIT_FAILURE);
	}
	ft_free_tabstr(env);
	ft_strdel(&str);
}

void	ft_execute(char **cmd, t_env *e)
{
	pid_t	pid;
	pid_t	w;
	int		status;
	char	**env;
	char	*s;

	pid = fork();
//	ft_printf(2, "execute\n");
	signal(SIGINT, sig_exe);
	s = ft_string_return(e, cmd);
	env = ft_list_to_tab(e);
	if (pid == -1)
		exit(EXIT_FAILURE);
	if (pid == 0 && !access(s, X_OK))
	{
//		ft_printf(2, "%s, %s, %s\n", s, cmd[0], env[0]);
		status = execve(s, cmd, env);
		if (kill(pid, SIGINT) == -1)
			exit(status);
		exit(status);
	}
	else if ((w = waitpid(pid, &status, WCONTINUED)) == -1)
		exit(EXIT_FAILURE);
	ft_free_tabstr(env);
	ft_strdel(&s);
}

void	ft_exit(t_exec *exe, t_env *e)
{
//	ft_free_env(e);
	ft_free_tabstr(exe->cmd);
	free(exe);
	exe = NULL;
 	exit(EXIT_SUCCESS);
}

t_env	*ft_make_cmd(t_exec *exe, t_env *e)
{
	t_exec	*s;

	s = exe;
	while (s != NULL && s->cmd[0] != NULL)
	{
		if (s->cmd[0] == NULL)
			return (e);
		if (!ft_strncmp(s->cmd[0], "exit\0", 5))
			ft_exit(s, e);
		else if (!ft_strncmp(s->cmd[0], "env\0", 4))
			ft_env(s, e);
		else if (!ft_strncmp(s->cmd[0], "setenv\0", 7))
			e = ft_setenv(s, e);
		else if (!ft_strncmp(s->cmd[0], "unsetenv\0", 9))
			e = ft_unsetenv(s, e);
		else if (!ft_strncmp(s->cmd[0], "cd\0", 3))
			e = ft_cd(s, e);
		else if (!ft_strncmp(s->cmd[0], "echo\0", 5))
			ft_echo(s, e);
		else
			ft_error_and_make_exe(s, e);
		s = s->next;
	}
	return (e);
}
