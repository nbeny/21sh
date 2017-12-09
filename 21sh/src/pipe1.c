/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 19:21:27 by nbeny             #+#    #+#             */
/*   Updated: 2017/12/09 19:21:29 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	init_last_pipe(t_dopp *dop, t_exec *toto, t_env *e)
{
	dop->status = 0;
	dop->s = ft_path_istrue(toto->cmd, e);
	dop->env = ft_list_to_tab(e);
	dop->pid2 = fork();
}

void	init_first_pipe(t_dopp *dop, t_term *term, t_exec *toto, t_env *e)
{
	e = make_redirection_left(term, toto, e);
	dop->s = ft_path_istrue(toto->cmd, e);
	dop->env = ft_list_to_tab(e);
	dop->status = 0;
	pipe(dop->pipefd2);
	dop->pid2 = fork();
}

void	init_mid_pipe(t_dopp *dop, t_exec *toto, t_env *e)
{
	dop->env = ft_list_to_tab(e);
	dop->s = ft_path_istrue(toto->cmd, e);
	pipe(dop->pipefd2);
	dop->pid2 = fork();
}
