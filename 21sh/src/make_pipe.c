#include "21sh.h"

t_env	*ft_do_pipe(t_term *term, t_exec **exe, t_env *e)
{
    if (ft_isbultin(s, e))
        e = make_bultin(s, e);
    else if (!ft_strncmp(s->cmd[0], "./", 2) ||\
             !ft_strncmp(s->cmd[0], "/", 1))
        ft_execute_pipe(s, e);
    else if ((str = ft_path_istrue(s->cmd, e)))
        ft_execute_path_pipe(str, s, e);
    else
        ft_printf(2, "command not found: %s\n", s->cmd[0]);
}
