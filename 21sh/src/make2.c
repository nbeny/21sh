#include "21sh.h"

t_red	*make_right_red(t_red *r, t_env *e)
{
	if (r->mask[1] == '&')
	{
//		if (ft_isdigit(r->mask[2]))
//			make_rightaddrfd(r, e);
		if (r->mask[2] == '-')
			make_rightaddrless(r, e);
	}
	else if (r->mask[1] == '>')
		make_doubleright_redirection(r, e);
	else if (r->mask[1] == '|')
		make_rightpipe(r, e);
	else
		make_right(r, e);
	return (r);
}

t_red	*make_left_red(t_red *r, t_env *e)
{
	if (r->mask[1] == '&')
	{
//		if (ft_isdigit(r->mask[2]))
//			make_rightaddrfd(r, e);
		r = make_leftaddr(r, e);
	}
	else if (r->mask[1] == '<')
	{
		if (r->mask[2] == '<')
			r = make_trileft_redirection(r, e);
		else if (r->mask[2] == '-')
			r = make_doubleleftless(r, e);
		else
			r = make_doubleleft(r, e);
	}
	else if (r->mask[1] == '|')
		r = make_rightpipe(r, e);
	else
		r = make_right(r, e);
	return (r);
}

t_red	*make_digit(t_red *r, t_env *e)
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
	else if (r->mask[1] == '<')
	{
		if (r->mask[2] == '&')
		{
			if (ft_isdigit(r->mask[3]))
				r = make_fdleftaddrfd(r, e);
			else if (r->mask[3] == '-')
				r = make_fdleftaddrless(r, e);
		}
		else if (r->mask[2] == '<')
			r = make_fddoubleleft(r, e);
		else
			r = make_fdleft(r, e);
	}
	return (r);
}

t_env	*make_redirection(t_exec *exe,t_env *e)
{
	t_red	*r;

	r = exe->red;
	while (r != NULL && r->mask != NULL)
	{
		if (exe->error != NULL)
			ft_printf(2, "%s", exe->error);
		else if (ft_isdigit(exe->mask[0]))
			r = make_digit(r, e);
		else if (exe->mask[0] == '>')
			r = make_right_red(r, e);
		else if (exe->mask[0] == '<')
			r = make_left_red(r, e);
		else
			ft_printf(2, "what");
		r = r->next;
	}
	return (e);
}
