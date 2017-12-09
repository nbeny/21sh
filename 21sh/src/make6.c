/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:15:34 by nbeny             #+#    #+#             */
/*   Updated: 2017/12/06 15:15:35 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

t_red	*make_fdleftaddrfd(t_exec *exe, t_red *r, t_env *e)
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

t_red	*make_fdleftaddrless(t_exec *exe, t_red *r, t_env *e)
{
	make_fdrightaddrless(exe, r, e);
	return (r);
}

t_red	*make_fddoubleleft(t_term *term, t_exec *exe, t_red *r, t_env *e)
{
	char	*tmp;
	int		i;

	i = 0;
	start_heredoc(term);
	while (ft_strncmp(term->line, r->file, (ft_strlen(r->file) + 1)))
	{
		if (i == 0)
			tmp = ft_strdup(term->line);
		term->quot = ft_strjoin(tmp, "\n");
		ft_strdel(&tmp);
		ft_strdel(&(term->line));
		ft_putstr("heredoc> ");
		i++;
		term->hty = ft_get_command(term, term->hty);
		if (ft_strncmp(term->line, r->file, (ft_strlen(r->file) + 1)))
			tmp = ft_strjoin(term->quot, term->line);
		else
			tmp = ft_strdup(term->quot);
		ft_strdel(&(term->quot));
		term->quot = tmp;
	}
	r = clear_creat(term, exe, r);
	return (r);
}

t_red	*make_fdleft(t_exec *exe, t_red *r, t_env *e)
{
	char	*tmp;
	char	*path;

	if (r->fd1 == 0)
		return (r = make_left(exe, r, e));
	if (r->file[0] == '/')
	{
		tmp = getcwd(NULL, 1024);
		path = ft_add_path(tmp, r->file);
		ft_strdel(&tmp);
	}
	else
		path = ft_strdup(r->file);
	if (access(path, R_OK))
	{
		exe->error = ft_strdup("21sh: no such file or directory\n");
		return (r);
	}
	r = modfd_leftred(exe, r, e);
	ft_strdel(&path);
	return (r);
}

t_red	*make_left(t_exec *exe, t_red *r, t_env *e)
{
	char	*tmp;
	char	*path;

	if (r->file[0] == '/')
	{
		tmp = getcwd(NULL, 1024);
		path = ft_add_path(tmp, r->file);
		ft_strdel(&tmp);
	}
	else
		path = ft_strdup(r->file);
	if (access(path, R_OK))
	{
		exe->error = ft_strdup("21sh: no such file or directory\n");
		return (r);
	}
	else if (!ft_cmp_tabstr(exe->cmd))
		add_cmd_(exe, path);
	ft_strdel(&path);
	return (r);
}
