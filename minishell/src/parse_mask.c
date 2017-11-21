#include "21sh.h"

t_exec  *ft_push_mask(t_term *term, t_exec *exe, char *str)
{
	t_exec *s;

	s = exe;
    exe->mask = ft_strdup(str);
    exe->cmd = ft_cmd_building(term, exe);
    if (exe->cmd == NULL)
        ft_strdel(&(exe->mask));
    else
    {
        exe->next = ft_new_exe();
		s = exe;
        exe = exe->next;
		exe->prev = s;
    }
    return (exe);
}

t_exec  *ft_push_mask_v1(t_term *term, t_exec *exe, char *str)
{
	t_exec *s;

    exe->mask = ft_strdup(str);
    exe->cmd = ft_cmd_building(term, exe);
    if (exe->cmd == NULL)
        ft_strdel(&(exe->mask));
    else
    {
        exe->next = ft_new_exe();
		s = exe;
//      ft_free_quot(exe->quot);
        exe = exe->next;
		exe->prev = s;
    }
    term->i++;
    return (exe);
}

t_exec	*ft_push_mask_v2(t_term *term, t_exec *exe, char *str)
{
	t_exec	*s;

	s = exe;
    exe->mask = ft_strdup(str);
    exe->cmd = ft_cmd_building(term, exe);
    if (exe->cmd == NULL)
        ft_strdel(&(exe->mask));
    else
    {
        exe->next = ft_new_exe();
		s = exe;
        exe = exe->next;
		exe->prev = s;
    }
    term->i += 2;
    return (exe);
}

t_exec	*ft_push_mask_v3(t_term *term, t_exec *exe, char *str)
{
	t_exec	*s;

	s = exe;
    exe->mask = ft_strdup(str);
    exe->cmd = ft_cmd_building(term, exe);
    if (exe->cmd == NULL)
        ft_strdel(&(exe->mask));
    else
    {
        exe->next = ft_new_exe();
		s = exe;
        exe = exe->next;
		exe->prev = s;
    }
    term->i += 3;
    return (exe);
}

t_exec	*ft_push_mask_v4(t_term *term, t_exec *exe, char *str)
{
	t_exec	*s;

	s = exe;
    exe->mask = ft_strdup(str);
    exe->cmd = ft_cmd_building(term, exe);
    if (exe->cmd == NULL)
        ft_strdel(&(exe->mask));
    else
    {
        exe->next = ft_new_exe();
		s = exe;
        exe = exe->next;
		exe->prev = s;
    }
    term->i += 4;
    return (exe);
}
