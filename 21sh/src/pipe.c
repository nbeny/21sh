/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:16:32 by nbeny             #+#    #+#             */
/*   Updated: 2017/12/06 15:16:33 by nbeny            ###   ########.fr       */
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

int				ft_do_last_pipe(t_term *term, t_exec *toto, t_nb *nb, t_env *e)
{
	int		pid3;
	int		status;
    char	*s;
    char	**env;

	status = 0;
	s = ft_path_istrue(toto->cmd, e);
    env = ft_list_to_tab(e);
	pid3 = fork();
	if (pid3 == 0)
	{
		close(nb->sout);
		reload_fd(toto);
		dup2(nb->sin, 0);
        e = make_redirection_right(term, toto, e);
		toto = ft_close_fd(toto);
		close(nb->sin);
		if ((status = execve(s, toto->cmd, env)) == -1)
			toto->error = ft_strdup("21sh: execve failed\n");
		exit(status);
	}
	close(nb->sout);
	close(nb->sin);
	ft_free_tabstr(env);
	ft_strdel(&s);
	waitpid(pid3, &status, WCONTINUED);
	return (status);
}

t_nb			*ft_do_first_pipe(t_term *term, t_exec *toto, t_nb *nb, t_env *e)
{
	int		status;
	pid_t	pid1;
	int		pipefd[2];
    char	*s;
    char	**env;

	e = make_redirection_left(term, toto, e);
	s = ft_path_istrue(toto->cmd, e);
	env = ft_list_to_tab(e);
	status = 0;
	pipe(pipefd);
	pid1 = fork();
	nb->sin = 0;
	nb->sout = 1;
	if (pid1 == 0)
	{
		close(pipefd[0]);
		reload_fd(toto);
		dup2(pipefd[1], 1);
		e = make_redirection_right(term, toto, e);
		toto = ft_close_fd(toto);
		close(pipefd[1]);
		if ((status = execve(s, toto->cmd, env)) == -1)
			toto->error = ft_strdup("21sh: execve failed\n");
		signal(SIGINT, sig_exe);
		exit(status);
	}
	ft_strdel(&s);
	ft_free_tabstr(env);
	nb->sout = pipefd[1];
	nb->sin = pipefd[0];
	nb->pid1 = pid1;
	nb->status = status;
	return (nb);
}

t_nb			*ft_do_mid_pipe(t_term *term, t_exec *toto, t_nb *nb, t_env *e)
{
	pid_t			pid2;
	int				status;
	int				pipefd2[2];
	char			*s;
	char			**env;

	env = ft_list_to_tab(e);
	s = ft_path_istrue(toto->cmd, e);
	pipe(pipefd2);
	pid2 = fork();
	if (pid2 == 0)
	{
		close(nb->sout);
		reload_fd(toto);
		dup2(nb->sin, 0);
		close(nb->sin);
		close(pipefd2[0]);
		dup2(pipefd2[1], 1);
		e = make_redirection_right(term, toto, e);
		toto = ft_close_fd(toto);
		close(pipefd2[1]);
		if ((status = execve(s, toto->cmd, env)) == -1)
			toto->error = ft_strdup("21sh: execve failed\n");
		exit(status);
	}
	close(nb->sout);
	close(nb->sin);
	nb->sin = pipefd2[0];
	nb->sout = pipefd2[1];
	ft_free_tabstr(env);
	ft_strdel(&s);
	return (nb);
}

t_exec			*ft_do_pipe(t_term *term, t_exec *toto, t_nb *nb, t_env *e)
{
	int		status;

	nb = ft_do_first_pipe(term, toto, nb, e);
	toto = toto->next;
	while (toto && toto->mask != NULL && !ft_strncmp(toto->mask, "|\0", 2))
	{
		if (toto->error)
			break ;
		term->flash++;
		e = make_redirection_left(term, toto, e);
		if (!toto->next || ft_strncmp(toto->next->mask, "|\0", 2) ||\
			toto->pipe == 1)
		{
			status = ft_do_last_pipe(term, toto, nb, e);
			waitpid(nb->pid1, &(nb->status), WCONTINUED);
			wait(NULL);
			return (toto);
		}
		else
			nb = ft_do_mid_pipe(term, toto, nb, e);
		toto = toto->next;
	}
	wait(NULL);
	return (toto);
}
