#include "21sh.h"

void	init_redirection(t_exec *exe)
{
//	int			in;
//	int			out;

//	in = open("/dev/fd/1", O_RDONLY);
//    out = open("/dev/fd/1", O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);

	// replace standard input with input file
//	dup2(in, 1);
	
	// replace standard output with output file
	dup2(exe->fd.fd1, 1);
	
	// close unused file descriptors
//	close(in);
	close(exe->fd.fd1);
}

t_red	*make_digit_right(t_exec *exe, t_red *r, t_env *e)
{
	ft_printf(2, ";;make_digit_right\n");
	if (r->mask[1] == '>')
	{
		ft_printf(2, ";;<1>\n");
		if (r->mask[2] == '&')
		{
			ft_printf(2, ";;<2>\n");
			if (ft_isdigit(r->mask[3]))
				r = make_fdrightaddrfd(exe, r, e);
			else if (r->mask[3] == '-')
				r = make_fdrightaddrless(exe, r, e);
		}
		else if (r->mask[2] == '>')
			r = make_fddoubleright(exe, r, e);
		else
			r = make_fdright(exe, r, e);
		ft_printf(2, ";;<3>\n");
	}
	return (r);
}

t_red	*make_digit_left(t_exec *exe, t_red *r, t_env *e)
{
	ft_printf(2, ";;make_digit_left\n");
	if (r->mask[1] == '<')
	{
		ft_printf(2, ";;<1>\n");
		if (r->mask[2] == '&')
		{
			ft_printf(2, ";;<2>\n");
			if (ft_isdigit(r->mask[3]))
				r = make_fdleftaddrfd(exe, r, e);
			else if (r->mask[3] == '-')
				r = make_fdleftaddrless(exe, r, e);
		}
		else if (r->mask[2] == '<')
			r = make_fddoubleleft(exe, r, e);
		else
			r = make_fdleft(exe, r, e);
		ft_printf(2, ";;<3>\n");
	}
	return (r);
}
