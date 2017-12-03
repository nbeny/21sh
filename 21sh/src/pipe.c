#include "21sh.h"

static t_exec *ft_close_fd(t_exec *e)
{
/*    if (e->fd.ffd0)
	  close(0);
	  if (e->fd.ffd1)
	  close(1);
	  if (e->fd.ffd2)
	  close(2);*/
	(void)e;
    return (e);

}
int  ft_do_last_pipe(t_exec *toto, t_nb *nb, t_env *e)
{
	int pid3;
	int status;
    char *s;
    char **env;

	ft_putendl("last");
	status = 0;
	s = ft_path_istrue(toto->cmd, e);
    env = ft_list_to_tab(e);
	pid3 = fork();
	if (pid3 == 0)
	{
		
		close(nb->sout);
		dup2(nb->sin, 0);
		close(nb->sin);
		status = execve(s, toto->cmd, env);
		perror("exec");
        return 1;
	}
	close(nb->sout);
	close(nb->sin);
	return (status);
}

t_nb *ft_do_first_pipe(t_exec *toto, t_nb *nb, t_env *e)
{
	int status;
	pid_t pid1;
	int pipefd[2];
    char *s;
    char **env;

	s = ft_path_istrue(toto->cmd, e);
//	s = toto->cmd[0];
//    s =ft_string_return(e, toto->cmd);
    env = ft_list_to_tab(e);
	status = 0;
	pipe(pipefd);
	ft_putendl(s);
	pid1 = fork();
	nb->sin = 0;
	nb->sout = 1;
	if (pid1 == 0)
	{
		toto = ft_close_fd(toto);
		close(pipefd[0]);
		dup2(pipefd[1], 1);
		close(pipefd[1]);
		status = execve(s, toto->cmd, env);
		perror("exec");
		return 0;
	}
	nb->sout = pipefd[1];
	nb->sin = pipefd[0];
//	wait(NULL);
	return (nb);
}

t_exec *ft_do_pipe(t_exec *toto, t_nb *nb, t_env *e)
{
	pid_t  pid2;
    int status;
    int pipefd2[2];
	char *s;
	char **env;

//	s = toto->cmd[0];
//	s = ft_path_istrue(toto->cmd, e);
	s = NULL;
	env = ft_list_to_tab(e);
	nb = ft_do_first_pipe(toto, nb, e);
	ft_putendl("bmid");
	toto = toto->next;

	while (toto && toto->mask != NULL && !ft_strncmp(toto->mask, "|\0", 2))
	{
			s = ft_path_istrue(toto->cmd, e);
		ft_putendl("mid");
		if (toto->next == NULL)
			ft_putendl("toto next null");
		else
		
		{
			ft_putendl("toto next non null");
			if (toto->next->mask == NULL)
				ft_putendl("toto next mask null");
			else
				ft_putendl(toto->next->mask);
			
		}
		if (!toto->next || ft_strncmp(toto->next->mask, "|\0", 2))
		{
			status = ft_do_last_pipe(toto, nb, e);
			return 0;
		}
		else
		{
			pipe(pipefd2);
			pid2 = fork();
			if (pid2 == 0)
			{
				toto = ft_close_fd(toto);
				
				close(nb->sout);
				dup2(nb->sin, 0);
				close(nb->sin);

				close(pipefd2[0]);
				dup2(pipefd2[1], 1);
				close(pipefd2[1]);

				status = execve(s, toto->cmd, env);
				perror("exec");
				return 0;
			}
		}
		ft_putendl("bclose");
		ft_putchar('\t');
		ft_putnbr(nb->sout);
		ft_putnbr(nb->sin);
		close(nb->sout);
		close(nb->sin);
		nb->sin = pipefd2[0];
		nb->sout = pipefd2[1];
		toto = toto->next;
	}
	ft_putendl("bwait");
	wait(NULL);

	return (toto);
}

/*int main(int argc, char** av)
  {
  pid_t pid1, pid2;
  int pipefd[2];
  int status;

  t_gg *toto;
  t_gg *save;

  t_nb *nb;

  nb =  malloc(sizeof(t_nb));
  toto = malloc(sizeof(t_gg));
  save = toto;

  nb->sin = 0;
  nb->sout = 1;


  char *argv1[] = {"base64", "/dev/urandom", NULL};
  char *argv2[] = {"head", "-c", "10000", NULL};
  char *argv3[] = {"grep", "42", NULL};
  char *argv4[] = {"wc", "-c", NULL};


  toto->str = argv1;
  toto->next = malloc(sizeof(t_gg));
  toto = toto->next;

  toto->str = argv2;

//	toto->next =  malloc(sizeof(t_gg));
//	toto = toto->next;

//	toto->str = argv3;
//	toto->next =  malloc(sizeof(t_gg));
//	toto = toto->next;

//toto->str = argv4;
toto->next = NULL;



ft_do_pipe(save, nb);

return 0;
}
*/
