/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:15:29 by nbeny             #+#    #+#             */
/*   Updated: 2017/12/06 15:15:30 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

t_red	*make_fdrightaddrfd(t_exec *exe, t_red *r, t_env *e)
{
	if (r->fd1 != -1)
	{
		if (r->fd2 == 0 || r->fd2 == 1 || r->fd2 == 2)
			dup2(r->fd1, r->fd2);
		else
			exe->error = ft_strdup("21sh: bad file descriptor\n");
	}
	if (r->fd1 == 1)
		exe->pipe = 1;
	return (r);
}

t_red	*make_fdrightaddrless(t_exec *exe, t_red *r, t_env *e)
{
	if (r->fd1 == 0)
	{
		close(exe->fd.fd0);
		exe->fd.ffd0 = 1;
	}
	if (r->fd1 == 1)
	{
		exe->fd.ffd1 = 1;
		close(exe->fd.fd1);
	}
	if (r->fd1 == 2)
	{
		exe->fd.ffd2 = 1;
		close(exe->fd.fd2);
	}
	if (r->fd1 == 1)
		exe->pipe = 1;
	return (r);
}

t_red	*make_fddoubleright(t_exec *exe, t_red *r, t_env *e)
{
	int		fd;

	fd = open(r->file, O_WRONLY | O_APPEND | O_CREAT,\
				S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
	if (fd == -1)
	{
		exe->error = ft_strdup("21sh: open failed\n");
		return (r);
	}
	dup2(fd, r->fd1);
	close(fd);
	if (r->fd1 == 1)
		exe->pipe = 1;
	return (r);
}

t_red	*make_fdright(t_exec *exe, t_red *r, t_env *e)
{
	int		fd;

	fd = open(r->file, O_WRONLY | O_TRUNC | O_CREAT,\
				S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
	if (fd == -1)
	{
		exe->error = ft_strdup("21sh: open return -1\n");
		return (r);
	}
	dup2(fd, r->fd1);
	close(fd);
	if (r->fd1 == 1)
		exe->pipe = 1;
	return (r);
}
