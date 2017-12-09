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

void	add_cmd_(t_exec *exe, char *path)
{
	exe->c = ft_tab_to_list_cmd(exe->cmd);
	exe->c = add_cmd_str(exe->c, path);
	free_cmd_str(exe->cmd);
	exe->cmd = ft_list_to_tab_cmd(exe->c);
	free_list_cmd_str(exe->c);
	exe->c = NULL;
}

t_exec	*ft_cmd_parcing(t_term *term)
{
	t_exec	*exe;
	char	**split;

	exe = NULL;
	split = NULL;
	if (term->line != NULL && term->line[0] != '\0')
		exe = ft_parse_quot(term);
	return (exe);
}
