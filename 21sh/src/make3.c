#include "21sh.h"

t_red	*make_rightaddrless(t_exec *exe, t_red *r, t_env *e)
{
	return (r);
}

t_red	*make_doubleright_redirection(t_exec *exe, t_red *r, t_env *e)
{
	return (r);
}

t_red	*make_rightpipe(t_exec *exe, t_red *r, t_env *e)
{
	return (r);
}

t_red	*make_right(t_exec *exe, t_red *r, t_env *e)
{
//	int			in;
	int			out;

//	in = open(0, O_RDONLY);
	exe->fd.fd1 = dup(1);
    out = open(r->file, O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);

	// replace standard input with input file
	//   dup2(in, 0);

	// replace standard output with output file
    dup2(out, 1);

	// close unused file descriptors
//	close(in);
	close(out);

	return (r);
}
