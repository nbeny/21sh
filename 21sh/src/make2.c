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

t_env	*make_redirection(t_exec *exe,t_env *e)
{
	t_red	*r;

//<<<<<<< HEAD
//	ft_putstr("ALLO");
//	r = exe->red;
//	ft_printf(0, "r->mask = %s   r->file = [%s]   fd1-2 = {%i, %i}\n", r->mask, r->file, r->fd1, r->fd2);
//	ft_execute_fd(exe->cmd[0], exe, e);

	ft_printf(2, "::::::::::::::\n");
	if (exe == NULL)
		return (e);
	r = exe->red;
	if (exe->error != NULL)
		return (e);
	while (r != NULL && r->mask != NULL)
	{
		ft_printf(2, "::boucle_start_eredoc\n");
		if (ft_isdigit(r->mask[0]))
			r = make_digit_left(r, e);
		else if (r->mask[0] == '<')
			r = make_left_red(r, e);
		r = r->next;
	}
	ft_printf(2, "::>>>>>>>>>>|*|<<<<<<<<<::\n");
	r = exe->red;
	while (r != NULL && r->mask != NULL)
	{
		ft_printf(2, "::boucle_start_redir\n");
		if (ft_isdigit(r->mask[0]))
			r = make_digit_right(r, e);
		else if (r->mask[0] == '>')
			r = make_right_red(r, e);
		r = r->next;
		}
	r = exe->red;
	if (r)
		ft_exe_red(exe, e);
	return (e);
}
