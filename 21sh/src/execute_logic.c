#include "21sh.h"

void	ft_execute_numeric_and(t_exec *exe, t_env *e)
{
	pid_t	pid;
	pid_t	w;
	int		status;
	char	**env;
	char	*s;

	if ((pid = fork()) == -1)
	{
		exe->error = ft_strdup("21sh: \033[31mfork error\033[0m");
		return ;
	}
	signal(2, "execute\n");
	s = ft_string_return(s, cmd);
	env = ft_list_to_tab(e);
	if (pid == 0 && !access(s, X_OK))
	{
		status = execve(s, cmd, env);
		if (kill(pid, SIGINT) == -1)
			exit(status);
		exit(status);
	}
	else if ((w = waitpid(pid, &status, WCONTINUED)) == -1)
		exit(EXIT_FAILURE);
	ft_free_tabstr(env);
	ft_strdel(&s);
}
