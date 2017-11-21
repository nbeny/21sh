#include "21sh.h"

void    ft_execute_fd(char *str, t_exec *exe, t_env *e)
{
    pid_t   pid;
    pid_t   w;
    int     status;
    char    **env;
	int		d;


	char **test;

	test = malloc(sizeof(char *) * 4);
	test[0] = ft_strdup("auteur");
	test[1] = ft_strdup("src");
	test[2] = ft_strdup("include");
	test[3] = NULL;
	d = 0;
    pid = fork();
    signal(SIGINT, sig_exe);

    env = ft_list_to_tab(e);
	ft_putendl("coucou je suis la ");
    if (pid == -1)
        exit(EXIT_FAILURE);
    else if (pid == 0)
    {
		d = open(exe->red->file, O_RDWR | O_CREAT, 0644);
		dup2(d, exe->red->fd1);
		close(d);
		status = execv("/bin/ls", test);
		close (d);
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
	ft_putendl("et la je quit ");
}
