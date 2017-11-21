#include "21sh.h"
/*
t_exec	*ft_double_right(t_term *term, t_exec *exe)
{
	exe->mask = ft_strdup(">>");
	exe->cmd = ft_cmd_building(term, exe);
	if (exe->cmd == NULL)
		ft_strdel(&(exe->mask));
	else
	{
		exe->next = ft_new_exe();
		//ft_free_quot(exe->quot);
		exe = exe->next;
	}
	term->i += 2;
	return (exe);
}

t_exec	*ft_double_left(t_term *term, t_exec *exe)
{
	exe->mask = ft_strdup("<<");
	exe->cmd = ft_cmd_building(term, exe);
	if (exe->cmd = NULL)
		ft_strdel(&(exe->mask));
	else
	{
		exe->next = ft_new_exe();
		//ft_free_quot(exe->quot);
		exe = exe->next;
	}
	term->i += 2;
	return (exe);
}

t_exec	*ft_merge_output(t_term *term, t_exec *exe)
{
	exe->mask = ft_strdup(">&");
	exe->cmd = ft_cmd_building(term, exe);
	if (exe->cmd = NULL)
		ft_strdel(&(exe->mask));
	else
	{
		exe->next = ft_new_exe();
		//ft_free_quot(exe->quot);
		exe = exe->next;
	}
	term->i += 2;
	return (exe);
}

t_exec	*ft_merge_input(t_term *term, t_exec *exe)
{
	exe->mask = ft_strdup("<&");
	exe->cmd = ft_cmd_building(term, exe);
	if (exe->cmd = NULL)
		ft_strdel(&(exe->mask));
	else
	{
		exe->next = ft_new_exe();
		//ft_free_quot(exe->quot);
		exe = exe->next;
	}
	term->i += 2;
	return (exe);
}
*/
