#include "21sh.h"

void	init_redirection(t_exec *exe)
{
	if (exe->fd.fd0 != -1)
	{
		dup2(exe->fd.fd0, 0);
		close(exe->fd.fd0);
	}
	if (exe->fd.fd1 != -1)
	{
		dup2(exe->fd.fd1, 1);
		close(exe->fd.fd1);
	}
	if (exe->fd.fd2 != -1)
	{
		dup2(exe->fd.fd2, 2);
		close(exe->fd.fd2);
	}
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

t_red	*make_digit_left(t_term *term, t_exec *exe, t_red *r, t_env *e)
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
