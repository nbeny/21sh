/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:17:46 by nbeny             #+#    #+#             */
/*   Updated: 2017/12/06 15:17:46 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void	save_fd(t_exec *exe)
{
	exe->fd.fd0 = dup(0);
	exe->fd.fd1 = dup(1);
	exe->fd.fd2 = dup(2);
}

void	reload_fd(t_exec *exe)
{
	dup2(exe->fd.fd0, 0);
	dup2(exe->fd.fd1, 1);
	dup2(exe->fd.fd2, 2);
}
