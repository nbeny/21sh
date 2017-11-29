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
	ft_strdel(&(term->line));
	term->prompt = 9;
	ft_putstr("heredoc> ");
	term->hty = ft_get_command(term, term->hty);
	while (ft_strncmp(term->line, r->file, (ft_strlen(r->file) + 1)))
	{
		if (i == 0)
			tmp = ft_strdup(term->line);
		else
			tmp = ft_strjoin(term->quot, term->line);
		i++;
		term->quot = ft_strjoin(tmp, "\n");
		ft_strdel(&tmp);
		ft_strdel(&(term->line));
		ft_putstr("heredoc> ");
		term->hty = ft_get_command(term, term->hty);
		if (ft_strncmp(term->line, r->file, (ft_strlen(r->file) + 1)))
			tmp = ft_strjoin(term->quot, term->line);
		else
			tmp = ft_strdup(term->quot);
		ft_strdel(&(term->quot));
		term->quot = tmp;
	}
	ft_strdel(&(term->line));
	r = creat_fd_or_file(term->quot, exe, r);
	ft_strdel(&(term->quot));
	return (r);
}

t_red	*make_fdleft(t_exec *exe, t_red *r, t_env *e)
{
	char	*tmp;
	char	*path;
	int     fd;
		
	if (r->fd1 == 0)
		return(r = make_left(exe, r, e));
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
    fd = open(r->file, O_RDONLY, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
    if (fd == -1)
    {
        exe->error = ft_strdup("21sh: open failed\n");
        return (r);
    }
	dup2(fd, r->fd1);
	close(fd);
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
	{
		exe->c = ft_tab_to_list_cmd(exe->cmd);
		exe->c = add_cmd_str(exe->c, path);
		free_cmd_str(exe->cmd);
		exe->cmd = ft_list_to_tab_cmd(exe->c);
		free_list_cmd_str(exe->c);
		exe->c = NULL;
	}
	ft_strdel(&path);
	return (r);
}
