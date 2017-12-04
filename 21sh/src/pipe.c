#include "21sh.h"

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

int  ft_do_last_pipe(t_term *term, t_exec *toto, t_nb *nb, t_env *e)
{
	int pid3;
	int status;
    char *s;
    char **env;

	term->flash++;
	ft_putendl("last");
	status = 0;
	s = ft_path_istrue(toto->cmd, e);
    env = ft_list_to_tab(e);
	ft_putnbr(nb->sin);
	pid3 = fork();
	if (pid3 == 0)
	{
		close(nb->sout);
        reload_fd(toto);//    <--- ici tu reset les redirection pour que le dup2 se fasse sur la vrai sortie 1 
		dup2(nb->sin, 0);
        e = make_redirection(term, toto, e);// <--- ici tu remet les redirections pour que execve se fasse sur le fichier 
		toto = ft_close_fd(toto);
		close(nb->sin);
		if ((status = execve(s, toto->cmd, env)) == -1)
		{
			toto->error = ft_strdup("21sh: execve failed\n");
			return (status);
		}
	}
	close(nb->sout);
	close(nb->sin);
	wait(NULL);
	return (status);
}

t_nb *ft_do_first_pipe(t_term *term, t_exec *toto, t_nb *nb, t_env *e)
{
	int status;
	pid_t pid1;
	int pipefd[2];
    char *s;
    char **env;

	term->flash++;
	s = ft_path_istrue(toto->cmd, e);
    env = ft_list_to_tab(e);
	status = 0;
	pipe(pipefd);
	ft_putendl(s);
	pid1 = fork();
	nb->sin = 0;
	nb->sout = 1;
    if (pid1 == 0)
    {
        close(pipefd[0]);
        reload_fd(toto);//    <--- ici tu reset les redirection pour que le dup2 se fasse sur la vrai sortie 1
        dup2(pipefd[1], 1);
        e = make_redirection(term, toto, e);// <--- ici tu remet les redirections pour que execve se fasse sur le fichier 
        toto = ft_close_fd(toto);
        close(pipefd[1]);
		if ((status = execve(s, toto->cmd, env)) == -1)
		{
			toto->error = ft_strdup("21sh: execve failed\n");
			return (NULL);
		}
    }
	nb->sout = pipefd[1];
	nb->sin = pipefd[0];
	wait(NULL);
	return (nb);
}

t_exec *ft_do_pipe(t_term *term, t_exec *toto, t_nb *nb, t_env *e)
{
	pid_t  pid2;
    int status;
    int pipefd2[2];
	char *s;
	char **env;

	s = NULL;
	env = ft_list_to_tab(e);
	term->flash++;
	nb = ft_do_first_pipe(term, toto, nb, e);
	toto = toto->next;

	while (toto && toto->mask != NULL && !ft_strncmp(toto->mask, "|\0", 2))
	{
		s = ft_path_istrue(toto->cmd, e);
		if (!toto->next || ft_strncmp(toto->next->mask, "|\0", 2) ||\
			toto->pipe == 1)
		{
			status = ft_do_last_pipe(term, toto, nb, e);
			return (toto);
		}
		else
		{
			term->flash++;
			pipe(pipefd2);
			pid2 = fork();
			if (pid2 == 0)
			{
				close(nb->sout);
				reload_fd(toto);//    <--- ici tu reset les redirection pour que le dup2 se fasse sur la vrai sortie 1
				dup2(nb->sin, 0);
				close(nb->sin);

				close(pipefd2[0]);
//				if (toto->pipe != 1)
				dup2(pipefd2[1], 1);
				e = make_redirection(term, toto, e);// <--- ici tu remet les redirections pour que execve se fasse sur le fichier 
				toto = ft_close_fd(toto);
				close(pipefd2[1]);

				if ((status = execve(s, toto->cmd, env)) == -1)
				{
					toto->error = ft_strdup("21sh: execve failed\n");
					return (toto);
				}
			}
		}
		close(nb->sout);
		close(nb->sin);
		nb->sin = pipefd2[0];
		nb->sout = pipefd2[1];
		toto = toto->next;
	}
	return (toto);
}
