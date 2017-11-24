#include "21sh.h"

t_red	*make_fdrightaddrfd(t_exec *exe, t_red *r, t_env *e)
{
	if (r->fd1 != -1)
		dup2(r->fd1, r->fd2);
	return (r);
}

t_red	*make_fdrightaddrless(t_exec *exe, t_red *r, t_env *e)
{
	if (r->fd1 != -1)
		dup2(r->fd1, 2);
	return (r);
}

t_red	*make_fddoubleright(t_exec *exe, t_red *r, t_env *e)
{
	int		fd;

	fd = open(r->file, O_WRONLY | O_APPEND | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
	if (r->fd1 != -1)
		dup2(fd, r->fd1);
	close(fd);
	return (r);
}

t_red	*make_fdright(t_exec *exe, t_red *r, t_env *e)
{
	if (r->fd1 != -1)
		dup2(r->fd1, 1);
	return (r);
}
