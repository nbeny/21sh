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
	else if (!ft_strncmp(exe->cmd[0], "./", 2) ||\
			 !ft_strncmp(exe->cmd[0], "/", 1))
		ft_execute_fd(exe, e);
	else if ((str = ft_path_istrue(exe->cmd, e)))
		ft_execute_path_fd(str, exe, e);
	else
	{
		ft_printf(2, "command not found: %s\n", exe->cmd[0]);
		exe->error = ft_strdup("0");
	}
	if (exe->red != NULL)
		reload_fd(exe);
	return (e);
}

t_env	*make_pipe(t_term *term, t_exec *exe, t_env *e)
{
	t_exec	*s;
	char	*str;
	int		i;
	t_nb *nb;

	nb = malloc(sizeof(t_nb ));
	str = NULL;
	i = 1;
	s = exe;
	ft_printf(2, "je ss la !\n");
	while (s && s->mask != NULL && !ft_strncmp(s->mask, "|\0", 2))
	{
//		if (s->red != NULL)
//        {
		//           save_fd(s);
		//   e = make_redirection(term, s, e);
        //}

//			nb = ft_do_first_pipe(s, nb, e);
//		else
		ft_putendl("beef");
		if (i == 1)
			s = ft_do_pipe(s, nb, e);
		else
			ft_putendl("elsounet");
				ft_putendl("afft");
/*		ft_printf(2, "je ss dans la boucle !\n");
		if (s->red != NULL)
		{
		save_fd(s);
		e = make_redirection(term, s, e);
		}
		if (ft_isbultin(s, e))
		e = make_bultin(s, e);
		else if (!ft_strncmp(s->cmd[0], "./", 2) ||\
		!ft_strncmp(s->cmd[0], "/", 1))
		{
		if (i == 1)
		ft_do_first_pipe(t_gg *toto, t_nb *nb);
		else if (!s->next || ft_strncmp(s->next->mask, "|\0", 2))
		else 
		nb = ft_do_pipe(s, nb, e);
		}

		else if ((str = ft_path_istrue(s->cmd, e)))
		ft_execute_path_fd(str, s, e);
		else
		{
		ft_printf(2, "command not found: %s\n", s->cmd[0]);
		s->error = ft_strdup("0");
		}
		if (s->red != NULL)
		reload_fd(s);
		s = s->next;
		i++;*/
//		if (s->red != NULL)
//			reload_fd(s);
		i ++;
//		s = s->next;

	}
	ft_putendl("ret;");
	return (e);
}
