#include "21sh.h"

t_red	*make_right_red(t_exec *exe, t_red *r, t_env *e)
{
	ft_printf(2, "::boucle_start_redir\n");
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
	ft_printf(2, "::boucle_start_redir\n");
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

//<<<<<<< HEAD
//	ft_putstr("ALLO");
//	r = exe->red;
//	ft_printf(0, "r->mask = %s   r->file = [%s]   fd1-2 = {%i, %i}\n", r->mask, r->file, r->fd1, r->fd2);
//	ft_execute_fd(exe->cmd[0], exe, e);

	ft_printf(2, "::::::::::::::\n");
	if (exe == NULL || exe->error != NULL)
		return (e);
	r = exe->red;
	while (r != NULL && r->mask != NULL)
	{
		ft_printf(2, "::boucle_start_eredoc\n");
		if (ft_isdigit(r->mask[0]))
			r = make_digit_left(term, exe, r, e);
		else if (r->mask[0] == '<')
			r = make_left_red(term, exe, r, e);
		r = r->next;
	}
	ft_printf(2, "::>>>>>>>>>>|*|<<<<<<<<<::\n");
	r = exe->red;
	while (r != NULL && r->mask != NULL)
	{
		ft_printf(2, "::boucle_start_redir\n");
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
