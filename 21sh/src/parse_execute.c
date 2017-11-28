#include "21sh.h"

int		ft_isbultin(t_exec *exe, t_env *e)
{
	if (!ft_strncmp(exe->cmd[0], "exit\0", 5) ||\
		!ft_strncmp(exe->cmd[0], "env\0", 4) ||\
		!ft_strncmp(exe->cmd[0], "setenv\0", 7) ||\
		!ft_strncmp(exe->cmd[0], "unsetenv\0", 9) ||\
		!ft_strncmp(exe->cmd[0], "cd\0", 3) ||\
		!ft_strncmp(exe->cmd[0], "echo\0", 5))
		return (1);
	return (0);
}

t_env	*make_bultin(t_exec *exe, t_env *e)
{
	if (!ft_strncmp(exe->cmd[0], "exit\0", 5))
		ft_exit(exe, e);
	else if (!ft_strncmp(exe->cmd[0], "env\0", 4))
		ft_env(exe, e);
	else if (!ft_strncmp(exe->cmd[0], "setenv\0", 7))
		e = ft_setenv(exe, e);
	else if (!ft_strncmp(exe->cmd[0], "unsetenv\0", 9))
		e = ft_unsetenv(exe, e);
	else if (!ft_strncmp(exe->cmd[0], "cd\0", 3))
		e = ft_cd(exe, e);
	else if (!ft_strncmp(exe->cmd[0], "echo\0", 5))
		ft_echo(exe, e);
	else
		ft_printf(2, "bultin: no match found with '%s'\n", exe->cmd[0]);
	return (e);
}

t_env	*make_semicolon(t_term *term, t_exec *exe, t_env *e)
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
	ft_printf(2, "end_save_fd: DONE\n");
	if (ft_isbultin(exe, e))
		e = make_bultin(exe, e);
	else if (!ft_strncmp(exe->cmd[0], "./", 2) ||\
		!ft_strncmp(exe->cmd[0], "/", 1))
		ft_execute_fd(exe, e);
	else if ((str = ft_path_istrue(exe->cmd, e)))
		ft_execute_path_fd(str, exe, e);
	else
		ft_printf(2, "command not found: %s\n", exe->cmd[0]);
	ft_printf(2, "end_make_semicolon: DONE\n");
	if (exe->red != NULL)
		reload_fd(exe);
	return (e);
}

t_env	*make_numeric_or(t_term *term, t_exec *exe,t_env *e)
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
	else if (!ft_strncmp(exe->cmd[0], "./", 2) ||\
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

t_env	*ft_parse_mask(t_term *term, t_exec *exe, t_env *e)
{
	t_exec *s;

	s = exe;
	if (exe == NULL)
		return(e);
	while (s != NULL && s->cmd[0] != NULL && s->error == NULL)
	{
		if (s->mask == NULL)
			e = make_semicolon(term, s, e);
		else if (s->mask[0] == '|')
		{
			if (s->mask[1] == '|')
				e = boucle_numeric_or(term, s, e);
			else
				e = make_pipe(term, s, e);
		}
		else if (s->mask[0] == '&' && s->mask[1] == '&')
			boucle_numeric_and(term, s, e);
		else
			e = make_semicolon(term, s, e);
		if (exe->error != NULL)
		{
			ft_printf(2, "%s", exe->error);
			ft_strdel(&(exe->error));
		}
		s = s->next;
	}
	return (e);
}
