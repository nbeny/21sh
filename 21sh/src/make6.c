#include "21sh.h"

t_red	*make_fdleftaddrfd(t_exec *exe, t_red *r, t_env *e)
{
	return (r);
}

t_red	*make_fdleftaddrless(t_exec *exe, t_red *r, t_env *e)
{
	return (r);
}

t_red	*make_fddoubleleft(t_exec *exe, t_red *r, t_env *e)
{
	
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
