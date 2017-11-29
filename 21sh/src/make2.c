#include "21sh.h"

t_red	*make_right_red(t_exec *exe, t_red *r, t_env *e)
{
	if (r->mask[1] == '&')
	{
//		if (ft_isdigit(r->mask[2]))
//			make_rightaddrfd(r, e);
		if (r->mask[2] == '-')
			make_rightaddrless(exe, r, e);
	}
	else if (r->mask[1] == '>')
		make_doubleright_redirection(exe, r, e);
	else if (r->mask[1] == '|')
		make_rightpipe(exe, r, e);
	else
		make_right(exe, r, e);
	return (r);
}

t_red	*make_left_red(t_term *term, t_exec *exe, t_red *r, t_env *e)
{
	if (r->mask[1] == '&')
	{
//		if (ft_isdigit(r->mask[2]))
//			make_rightaddrfd(r, e);
		r = make_leftaddr(exe, r, e);
	}
	else if (r->mask[1] == '<')
	{
		if (r->mask[2] == '<')
			r = make_trileft_redirection(exe, r, e);
		else if (r->mask[2] == '-')
			r = make_doubleleftless(term, exe, r, e);
		else
			r = make_doubleleft(term, exe, r, e);
	}
	else if (r->mask[1] == '|')
		r = make_leftpipe(exe, r, e);
	else
		r = make_left(exe, r, e);
	return (r);
}

t_env	*make_redirection(t_term *term, t_exec *exe,t_env *e)
{
	t_red	*r;

	if (exe == NULL || exe->error != NULL)
		return (e);
	r = exe->red;
	while (r != NULL && r->mask != NULL)
	{
		if (ft_isdigit(r->mask[0]))
			r = make_digit_left(term, exe, r, e);
		else if (r->mask[0] == '<')
			r = make_left_red(term, exe, r, e);
		r = r->next;
	}
	r = exe->red;
	while (r != NULL && r->mask != NULL)
	{
		if (ft_isdigit(r->mask[0]))
			r = make_digit_right(exe, r, e);
		else if (r->mask[0] == '>')
			r = make_right_red(exe, r, e);
		r = r->next;
	}

//	r = exe->red;
//	if (r)
//		ft_exe_red(exe, e);
	return (e);
}
