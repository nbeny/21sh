#include "21sh.h"

void	ft_parse_mask(t_exec *exe, t_env *env)
{
	if (exe->mask == NULL)
		return ;
	else if (!ft_strncmp(exe->mask, ">", 1))
		make_right_redirection(exe, env);
	else if (!ft_strncmp(exe->mask, "&\0", 2))
		make_background(exe, env);
	else if (!ft_strncmp(exe->mask, "<", 1))
		make_simple_left(exe, env);
	else if (!ft_strncmp(exe->mask, "<<\0", 3))
		make_double_right(exe, env);
	else if (!ft_strncmp(exe->mask, "|\0", 2))
		make_pipe(exe, env);
	else if (!ft_strncmp(exe->mask, ";\0", 2))
		make_semicolon();
	else if (!ft_strncmp(exe->mask, "0>&", 3))
		make_zero_right();
	else if (!ft_strncmp(exe->mask, "1>&", 3))
		make_one_right();
	else if (!ft_strncmp(exe->mask, "2>&", 3))
		make_two_right();
	else if (!ft_strncmp(exe->mask, "0<&", 3))
		make_zero_left();
	else if (!ft_strncmp(exe->mask, "1<&", 3))
		make_one_left();
	else if (!ft_strncmp(exe->mask, "2<&", 3))
		make_two_left();
	else
		ft_printf(2, "mask error");
}
