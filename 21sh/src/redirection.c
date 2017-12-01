#include "21sh.h"

/*
void	make_background(t_exec *exe, t_env *env)
{
	t_exec	*s;
	pid_t	pid;
	pid_t	w;
	int		status;
	char	**env;
	char	*str;

	if (s->next == NULL || s->next->cmd[0] == NULL || !(str = ft_path_is_true(exe->cmd, env)))
		return ;
	s = exe->next;
	pid = fork();
	signal(SIGINT, sig_exe);
	env = ft_list_to_tab(e);
	if (pid == -1)
		exit(EXIT_FAILURE);
	else if (pid == 0 && !access(str, X_OK))
	{
		status = execve(str, cmd, env);
		if (kill(pid, SIGINT) == -1)
			exit(status);
		exit(status);
	}
	if (w == -1)
		exit(EXIT_FAILURE);
	ft_free_tabstr(env);
	ft_strdel(&str);
}

void	make_right_redirection(t_exec *exe, t_env *env)
{
	t_exec	*s;
	int		fd;
	pid_t	pid;
	pid_t	w;
	int		status;
	char	**env;
	char	*str;
	char	c;

	if (s->next == NULL || s->next->cmd[0] == NULL ||\
		!(str = ft_path_is_true(exe->cmd, env)))
		return ;
	s = exe->next;
	if (fd = open(s->cmd[0], O_RDWR) == -1)
		return ;
	if (dup(0, fd) == -1 && dup(2, fd) == -1)
		return ;
	if (!ft_strncmp(exe->mask, ">>\0", 3) == 0)
		while (c != EOF)
			read(fd, &c, 1);
	pid = fork();
	signal(SIGINT, sig_exe);
	env = ft_list_to_tab(e);
	if (pid == -1)
		exit(EXIT_FAILURE);
	else if (pid == 0 && !access(str, X_OK))
	{
		status = execve(str, cmd, env);
		if (kill(pid, SIGINT) == -1)
			exit(status);
		exit(status);
	}
	else
	{
		w = waitpid(pid, &status, WCONTINUED);
		if (w == -1)
			exit(EXIT_FAILURE);
	}
	if (w == -1)
		exit(EXIT_FAILURE);
	ft_free_tabstr(env);
	ft_strdel(&str);
}
*/