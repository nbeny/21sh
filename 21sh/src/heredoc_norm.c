/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_norm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:14:36 by nbeny             #+#    #+#             */
/*   Updated: 2017/12/06 15:14:37 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void	start_here(t_term *term)
{
	ft_strdel(&(term->line));
	term->prompt = 9;
	ft_putstr("heredoc> ");
	term->hty = ft_get_command(term, term->hty);
}

t_red	*end_here(t_term *term, t_exec *exe, t_red *r)
{
	ft_strdel(&(term->line));
	if (ft_strncmp(exe->mask, "|\0", 2))
		r = creat_fd_or_file(term->quot, exe, r);
	ft_strdel(&(term->quot));
	return (r);
}

t_red	*modfd_leftred(t_exec *exe, t_red *r, t_env *e)
{
	int		fd;

	fd = open(r->file, O_RDONLY, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
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
