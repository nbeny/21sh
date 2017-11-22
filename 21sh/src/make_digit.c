#include "21sh.h"

t_red	*make_digit_right(t_red *r, t_env *e)
{
	if (r->mask[1] == '>')
	{
		if (r->mask[2] == '&')
		{
			if (ft_isdigit(r->mask[3]))
				r = make_fdrightaddrfd(r, e);
			else if (r->mask[3] == '-')
				r = make_fdrightaddrless(r, e);
		}
		else if (r->mask[2] == '>')
			r = make_fddoubleright(r, e);
		else
			r = make_fdright(r, e);
	}
	return (r);
}

t_red	*make_digit_left(t_red *r, t_env *e)
{
	ft_printf(2, ";;make_digit_left\n");
	if (r->mask[1] == '<')
	{
	ft_printf(2, ";;<1>\n");
		if (r->mask[2] == '&')
		{
	ft_printf(2, ";;<2>\n");
			if (ft_isdigit(r->mask[3]))
				r = make_fdleftaddrfd(r, e);
			else if (r->mask[3] == '-')
				r = make_fdleftaddrless(r, e);
		}
		else if (r->mask[2] == '<')
			r = make_fddoubleleft(r, e);
		else
			r = make_fdleft(r, e);
			ft_printf(2, ";;<3>\n");
	}
	return (r);
}
