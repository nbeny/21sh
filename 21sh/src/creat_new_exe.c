#include "21sh.h"

t_exec	*ft_right_redirection(t_term *term, t_exec *exe)
{
	if (term->line[term->i + 1] == '>')
		exe = ft_push_mask_v2(term, exe, ">>");
	else if (term->line[term->i + 1] == '&')
		exe = ft_push_mask_v2(term, exe, ">&");
	else
	{
		exe->mask = ft_strdup(">");
		exe->cmd = ft_cmd_building(term, exe);
		if (exe->cmd == NULL)
			ft_strdel(&(exe->mask));
		else
		{
			exe->next = ft_new_exe();
			exe = exe->next;
		}
		term->i++;
	}
	return (exe);
}

t_exec	*ft_left_redirection(t_term *term, t_exec *exe)
{
	if (term->line[term->i + 1] == '<')
		exe = ft_push_mask_v2(term, exe, "<<");
	else if (term->line[term->i + 1] == '&')
		exe = ft_push_mask_v2(term, exe, "<&");
	else
	{
		exe->mask = ft_strdup("<");
		exe->cmd = ft_cmd_building(term, exe);
		if (exe->cmd == NULL)
			ft_strdel(&(exe->mask));
		else
		{
			exe->next = ft_new_exe();
			exe = exe->next;
		}
		term->i++;
	}
	return (exe);
}
