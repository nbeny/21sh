#include "21sh.h"

t_env	*make_numeric_and(t_term *term, t_exec *exe, t_env *e)
{
	char	*str;

	str = NULL;
	if (exe->red != NULL)
	{
		save_fd(exe);
		e = make_redirection(term, exe, e);
	}
	if (exe->error != NULL)
		return (e);
	if (ft_isbultin(exe, e))
		e = make_bultin(exe, e);
	else if (!ft_strncmp(exe->cmd[0], "./", 2) ||	\
			 !ft_strncmp(exe->cmd[0], "/", 1))
		ft_execute_fd(exe, e);
	else if ((str = ft_path_istrue(exe->cmd, e)))
		ft_execute_path_fd(str, exe, e);
	else
		ft_printf(2, "command not found: %s\n", exe->cmd[0]);
	if (exe->red != NULL)
		reload_fd(exe);
	return (e);
}

t_env	*make_pipe(t_term *term, t_exec *exe, t_env *e)
{
	t_exec	*s;
	char	*str;
	int		i;

	str = NULL;
	i = 0;
	s = exe;
	while (s->mask != NULL && (!ft_strncmp(s->prev->mask, "|\0", 2) ||\
		!ft_strncmp(s->mask, "|\0", 2)))
	{
		if (exe->red != NULL)
		{
			save_fd(exe);
			e = make_redirection(term, exe, e);
		}
		if (ft_isbultin(exe, e))
			e = make_bultin(exe, e);
		else if (!ft_strncmp(exe->cmd[0], "./", 2) ||\
			!ft_strncmp(exe->cmd[0], "/", 1))
//			ft_execute_pipe(exe, e);
			;
		else if ((str = ft_path_istrue(exe->cmd, e)))
//			ft_execute_path_pipe(str, exe, e);
			;
		else
			ft_printf(2, "command not found: %s\n", exe->cmd[0]);
		if (exe->red != NULL)
			reload_fd(exe);
		s = s->next;
		i++;
	}
	return (e);
}
