#include "21sh.h"
/*
void	ft_execute_pipe(t_exec *exe, t_env *e)
{
	pid_t   w;
	int     status;
	char    **env;
	char	*s;
	int		pipe[2];

	if (pipe(pipe) == -1)
	{
		exe->error = ft_strdup("21sh: pipe return -1\n");
		return ;
	}
	exe->pid = fork();
	signal(SIGINT, sig_exe);
	s = ft_string_return(e, exe->cmd);
	env = ft_list_to_tab(e);
	if (exe->pid == -1)
		exit(EXIT_FAILURE);
	else if (exe->pid == 0)
	{
		close(pipe[1]);
		while (read(pipe[0], &buf, 1) > 0)
			write(STDOUT_FILENO, &buf, 1);
		write(STDOUT_FILENO, "\n", 1);
		close(pipefd[0]);
		status = execve(s, exe->cmd, env);
		if (kill(exe->pid, SIGINT) == -1)
			exit(status);
		exit(status);
	}
	else
	{
		close(pipe[0]);
        write(pipe[1], argv[1], ft_strlen(argv[1]));
        close(pipe[1]);   
		w = waitpid(exe->pid, &status, WCONTINUED);
		if (w == -1)
			exit(EXIT_FAILURE);
    }
    ft_free_tabstr(env);
	ft_strdel(&s);
}

void	ft_execute_path_pipe(char *str, t_exec *exe, t_env *e)
{
	pid_t   w;
    int     status;
    char    **env;

    exe->pid = fork();
    signal(SIGINT, sig_exe);
    env = ft_list_to_tab(e);
    if (exe->pid == -1)
        exit(EXIT_FAILURE);
    else if (exe->pid == 0 && !access(str, X_OK))
    {
        status = execve(str, exe->cmd, env);
        if (kill(exe->pid, SIGINT) == -1)
            exit(status);
        exit(status);
    }
    else
    {
        w = waitpid(exe->pid, &status, WCONTINUED);
        if (w == -1)
            exit(EXIT_FAILURE);
    }
    ft_free_tabstr(env);
    ft_strdel(&str);
}
*/
