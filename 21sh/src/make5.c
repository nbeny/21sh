#include "21sh.h"

t_red	*make_fdrightaddrfd(t_exec *exe, t_red *r, t_env *e)
{
	if (r->fd1 == 0)
		exe->fd.fd0 = dup(0);
	if (r->fd1 == 1)
		exe->fd.fd1 = dup(1);
	if (r->fd1 == 2)
		exe->fd.fd2 = dup(2);
	dup2(r->fd1, r->fd2);
	return (r);
}

t_red	*make_fdrightaddrless(t_exec *exe, t_red *r, t_env *e)
{
	if (r->fd1 == 0)
		exe->fd.fd0 = dup(0);
	if (r->fd1 == 1)
		exe->fd.fd1 = dup(1);
	if (r->fd1 == 2)
		exe->fd.fd2 = dup(2);
	dup2(r->fd1, 2);
	return (r);
}

t_red	*make_fddoubleright(t_exec *exe, t_red *r, t_env *e)
{
	return (r);
}

t_red	*make_fdright(t_exec *exe, t_red *r, t_env *e)
{
	return (r);
}
