#include "21sh.h"
/*
t_env   *make_semicolon(t_exec *exe, t_env *e)
{
	char	*str;

	str = NULL;
    if (exe->red != NULL)
        e = make_redirection(exe, e);
    else if (ft_isbultin(exe, e))
        e = make_bultin(exe, e);
    else if (!ft_strncmp(exe->cmd[0], "./", 2) ||\
			 !ft_strncmp(exe->cmd[0], "/", 1))
        ft_execute(exe->cmd, e);
    else if ((str = ft_path_istrue(exe->cmd, e)))
        ft_execute_path(str, exe->cmd, e);
    else
        ft_printf(2, "command not found: %s\n", exe->cmd[0]);
    return (e);
}
*/
/*
t_env   *make_numeric_or(t_exec *exe,t_env *e)
{
	char	*str;

	str = NULL;
    if (exe->red != NULL)
        e = make_redirection(exe, e);
    else if (ft_isbultin(exe, e))
        e = make_bultin(exe, e);
    else if (!ft_strncmp(exe->cmd[0], "./", 2) ||\
			 !ft_strncmp(exe->cmd[0], "/", 1))
        ft_execute(exe->cmd, e);
    else if ((str = ft_path_istrue(exe->cmd, e)))
        ft_execute_path(str, exe->cmd, e);
    else
        ft_printf(2, "command not found: %s\n", exe->cmd[0]);
    return (e);
}
*/
t_env	*make_numeric_and(t_exec *exe, t_env *e)
{
	char	*str;

	str = NULL;
    if (exe->red != NULL)
        e = make_redirection(exe, e);
    else if (ft_isbultin(exe, e))
        e = make_bultin(exe, e);
    else if (!ft_strncmp(exe->cmd[0], "./", 2) ||\
			 !ft_strncmp(exe->cmd[0], "/", 1))
        ft_execute(exe->cmd, e);
    else if ((str = ft_path_istrue(exe->cmd, e)))
        ft_execute_path(str, exe->cmd, e);
    else
        ft_printf(2, "command not found: %s\n", exe->cmd[0]);
	return (e);
}

t_env	*make_pipe(t_exec *exe, t_env *e)
{
	t_exec	*s;
	char	*str;

	str = NULL;
	s = exe;
	while (s->mask != NULL && !ft_strncmp(s->mask, "|\0", 2))
	{
		if (exe->red != NULL)
			e = make_redirection(exe, e);
		else if (ft_isbultin(exe, e))
			e = make_bultin(exe, e);
		else if (!ft_strncmp(exe->cmd[0], "./", 2) ||\
				 !ft_strncmp(exe->cmd[0], "/", 1))
			ft_execute(exe->cmd, e);
		else if ((str = ft_path_istrue(exe->cmd, e)))
			ft_execute_path(str, exe->cmd, e);
		else
			ft_printf(2, "command not found: %s\n", exe->cmd[0]);
		s = s->next;
	}
	return (e);
}
