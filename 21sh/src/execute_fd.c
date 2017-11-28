#include "21sh.h"
/*
void ft_exe_red(t_exec *exe, t_env *e)
{
	char *str;	
	//if (ft_isbultin(exe, e))
	//	e = make_bultin(exe, e);
	if (!ft_strncmp(exe->cmd[0], "./", 2) ||	\
			 !ft_strncmp(exe->cmd[0], "/", 1))
		ft_execute_fd(exe, e);
	else if ((str = ft_path_istrue(exe->cmd, e)))
		ft_execute_path_fd(str, exe, e);
	else
		ft_printf(2, "command not found: %s\n", exe->cmd[0]);
}
t_red *ft_dup(t_red *red)
{
	t_red *r;

	r = red;
	while (r)
	{
		r->fd_open = open(r->file, O_RDWR | O_CREAT, 0644);
		dup2(r->fd_open, r->fd1);
		r = r->next;
	}
	return (red);
}
t_fd *ft_close_dup(t_fd *fd)
{
	t_fd *r;

	r = fd;
	while (r)
	{
		close(r->fd_open);
		r = r->next;
	}
	return (fd);
	}*/
static t_exec *ft_close_fd(t_exec *e)
{
	if (e->fd.ffd0)
		close(0);
	if (e->fd.ffd1)
		close(1);
	if (e->fd.ffd2)
		close(2);
	return (e);
	
}
void    ft_execute_fd(t_exec *exe, t_env *e)
{
    pid_t   pid;
    pid_t   w;
    int     status;
    char    **env;
	char *s;

    pid = fork();
	signal(SIGINT, sig_exe);
	s =ft_string_return(e, exe->cmd);
    env = ft_list_to_tab(e);
    if (pid == -1)
        exit(EXIT_FAILURE);
    else if (pid == 0)
    {
		exe = ft_close_fd(exe);
		status = execve(s, exe->cmd, env);
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

    ft_free_tabstr(env);
	ft_strdel(&s);
}

void    ft_execute_path_fd(char *str, t_exec *exe, t_env *e)
{
    pid_t   pid;
    pid_t   w;
    int     status;
    char    **env;
	
    pid = fork();
    signal(SIGINT, sig_exe);
    env = ft_list_to_tab(e);
    if (pid == -1)
        exit(EXIT_FAILURE);
    else if (pid == 0 && !access(str, X_OK))
    {
		exe = ft_close_fd(exe);
        status = execve(str, exe->cmd, env);
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
    ft_free_tabstr(env);
    ft_strdel(&str);
}
