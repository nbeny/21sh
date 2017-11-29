#include "21sh.h"

void	save_fd(t_exec *exe)
{
	exe->fd.fd0 = dup(0);
	exe->fd.fd1 = dup(1);
	exe->fd.fd2 = dup(2);
}

void	reload_fd(t_exec *exe)
{
	dup2(exe->fd.fd0, 0);
	dup2(exe->fd.fd1, 1);
	dup2(exe->fd.fd2, 2);
}
