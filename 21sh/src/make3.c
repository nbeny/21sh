#include "21sh.h"

t_red	*make_rightaddrless(t_exec *exe, t_red *r, t_env *e)
{
	exe->fd.fd1 = dup(1);
    dup2(1, 2);
	return (r);
}

t_red	*make_doubleright_redirection(t_exec *exe, t_red *r, t_env *e)
{
	int			fd;

	exe->fd.fd1 = dup(1);
    fd = open(r->file, O_WRONLY | O_APPEND | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
    dup2(fd, 1);
	close(fd);
	return (r);
}

t_red	*make_rightpipe(t_exec *exe, t_red *r, t_env *e)
{
	int			fd;

	exe->fd.fd1 = dup(1);
    fd = open(r->file, O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
    dup2(fd, 1);
	close(fd);
	return (r);
}

t_red	*make_right(t_exec *exe, t_red *r, t_env *e)
{
	int			fd;

	exe->fd.fd1 = dup(1);
    fd = open(r->file, O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
    dup2(fd, 1);
	close(fd);
	return (r);
}
