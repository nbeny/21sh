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

#include "shell.h"

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
	t_dopp	dop;

	init_last_pipe(&dop, toto, e);
	if (dop.pid2 == 0)
	{
		close(nb->sout);
		reload_fd(toto);
		dup2(nb->sin, 0);
		e = make_redirection_right(term, toto, e);
		toto = ft_close_fd(toto);
		close(nb->sin);
		dop.status = execve(dop.s, toto->cmd, dop.env);
		ft_putendl_error(toto->cmd[0]);
		exit(dop.status);
	}
	close(nb->sout);
	close(nb->sin);
	ft_free_tabstr(dop.env);
	ft_strdel(&(dop.s));
	waitpid(dop.pid2, &(dop.status), WCONTINUED);
	return (dop.status);
}

t_nb			*ft_do_first_pipe(t_term *term, t_exec *toto,\
										t_nb *nb, t_env *e)
{
	t_dopp	dop;

	init_first_pipe(&dop, term, toto, e);
	nb->sin = 0;
	nb->sout = 1;
	if (dop.pid2 == 0)
	{
		close(dop.pipefd2[0]);
		reload_fd(toto);
		dup2(dop.pipefd2[1], 1);
		e = make_redirection_right(term, toto, e);
		toto = ft_close_fd(toto);
		close(dop.pipefd2[1]);
		dop.status = execve(dop.s, toto->cmd, dop.env);
		ft_putendl_error(toto->cmd[0]);
		signal(SIGINT, sig_exe);
		exit(dop.status);
	}
	ft_strdel(&(dop.s));
	ft_free_tabstr(dop.env);
	nb->sout = dop.pipefd2[1];
	nb->sin = dop.pipefd2[0];
	nb->pid1 = dop.pid2;
	nb->status = dop.status;
	return (nb);
}

t_nb			*ft_do_mid_pipe(t_term *term, t_exec *toto, t_nb *nb, t_env *e)
{
	t_dopp	dop;

	init_mid_pipe(&dop, toto, e);
	if (dop.pid2 == 0)
	{
		close(nb->sout);
		reload_fd(toto);
		dup2(nb->sin, 0);
		close(nb->sin);
		close(dop.pipefd2[0]);
		dup2(dop.pipefd2[1], 1);
		e = make_redirection_right(term, toto, e);
		toto = ft_close_fd(toto);
		close(dop.pipefd2[1]);
		dop.status = execve(dop.s, toto->cmd, dop.env);
		ft_putendl_error(toto->cmd[0]);
		exit(dop.status);
	}
	close(nb->sout);
	close(nb->sin);
	nb->sin = dop.pipefd2[0];
	nb->sout = dop.pipefd2[1];
	ft_free_tabstr(dop.env);
	ft_strdel(&(dop.s));
	return (nb);
}

t_exec			*ft_do_pipe(t_term *term, t_exec *toto, t_nb *nb, t_env *e)
{
	int		status;

	e = make_redirection_left(term, toto, e);
	nb = ft_do_first_pipe(term, toto, nb, e);
	toto = toto->next;
	while (toto && toto->mask != NULL && !ft_strncmp(toto->mask, "|\0", 2))
	{
		if (toto->error)
			break ;
		term->flash++;
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
