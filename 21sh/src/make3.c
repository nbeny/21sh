#include "21sh.h"

t_red	*make_rightaddrless(t_exec *exe, t_red *r, t_env *e)
{
	    if (r->fd1 != -1)
    {
        if (r->fd2 == 0 || r->fd2 == 1 || r->fd2 == 2)
            dup2(1, r->fd2);
        else
            exe->error = ft_strdup("21sh: bad file descriptor\n");
    }
    return (r);
}

t_red	*make_doubleright_redirection(t_exec *exe, t_red *r, t_env *e)
{
	int			fd;

	fd = open(r->file, O_WRONLY | O_APPEND | O_CREAT,\
			S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
	if (fd == -1)
	{
		exe->error = ft_strdup("21sh: open return -1\n");
		return (r);
	}
	dup2(fd, 1);
	close(fd);
	return (r);
}

t_red	*make_rightpipe(t_exec *exe, t_red *r, t_env *e)
{
	int			fd;

	fd = open(r->file, O_WRONLY | O_TRUNC | O_CREAT,\
			S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
	if (fd == -1)
	{
		exe->error = ft_strdup("21sh: open return -1\n");
		return (r);
	}
	dup2(fd, 1);
	close(fd);
	return (r);
}

t_red	*make_right(t_exec *exe, t_red *r, t_env *e)
{
	int			fd;

	fd = open(r->file, O_WRONLY | O_TRUNC | O_CREAT,\
			S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
	if (fd == -1)
	{
		exe->error = ft_strdup("21sh: open return -1\n");
		return (r);
	}
	dup2(fd, 1);
	close(fd);
	return (r);
}