
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

typedef struct s_gg
{
	char **str;
	struct s_gg *next;
}   t_gg;

typedef struct s_nb
{
	int sin;
	int sout;
} t_nb;

char    *ft_strdup(const char *s1)
{
    char            *s2;
    unsigned int    i;

    i = 0;
    if (s1 == NULL)
        return (NULL);
    while (s1[i])
        i++;
    if (!(s2 = (char *)malloc(sizeof(char) * (i + 1))))
        return (NULL);
    i = 0;
    while (s1[i])
    {
        s2[i] = s1[i];
        i++;
    }
    s2[i] = '\0';
    return (s2);
}

int  ft_do_last_pipe(t_gg *toto, t_nb *nb)
{
	int pid3;
	int status;

	printf("ft_do_last_pipee\n");
	pid3 = fork();
	if (pid3 == 0)
	{
		close(nb->sout);
		dup2(nb->sin, 0);
		close(nb->sin);

		status = execvp(toto->str[0],toto->str);
		perror("exec");
        return 1;
	}

    close(nb->sin);
    close(nb->sout);
	return (status);
}
int ft_do_pipe(t_gg *toto, t_nb *nb)
{
	pid_t pid1, pid2, pid3;
    int pipefd[2];
    int status;
    int pipefd2[2];
	printf("ft_do_pipee\n");
	pipe(pipefd);
	pid1 = fork();
	nb->sin = 0;
	nb->sout = 1;

	if (pid1 == 0) 
	{
		close(pipefd[0]);
		dup2(pipefd[1], nb->sout);                   //   fd[1] = STDOUT
		close(pipefd[1]);
		status = execvp(toto->str[0], toto->str);
		perror("exec");
		return 1;
	}
	nb->sin = pipefd[0];
	nb->sout = pipefd[1];
	toto = toto->next;
	while (toto)
	{
		if (toto->next == NULL)
		{
			status = ft_do_last_pipe(toto, nb);
		}
		else
		{
			printf("elese\n");
			pipe(pipefd2);
			nb->sin = pipefd2[0];
			nb->sout = pipefd2[1];
		
			pid2 = fork();

			if (pid2 == 0) 
			{
				close(pipefd[1]);                    //   fd[1] = close
				dup2(pipefd[0], STDIN_FILENO);       // fd[0] = stdin
				close(pipefd[0]);
			
				close(pipefd2[0]);
				dup2(pipefd2[1], 1);
				close(pipefd[1]);
			
			
				status = execvp(toto->str[0],toto->str);
				perror("exec");
				return 1;
			}
		
			close(pipefd[0]);
			close(pipefd[1]);
		
		}
		toto = toto->next;
	}
	wait(NULL);
	
	return (0);
}

int main(int argc, char** av) 
{
	pid_t pid1, pid2;
	int pipefd[2];
	int status;

	t_gg *toto;
	t_gg *save;
	
	t_nb *f_d;

	f_d =  malloc(sizeof(t_nb));
	toto = malloc(sizeof(t_gg));
	save = toto;

	f_d->sin = 0;
	f_d->sout = 1;

	char *argv1[] = {"ls", "-l", "-h", NULL};
	char *argv2[] = {"wc", "-l", NULL};
	char *argv3[] = {"wc", "-c", NULL};



	toto->str = argv1;
	toto->next = malloc(sizeof(t_gg));
	toto = toto->next;

	toto->str = argv2;
//	toto->next =  malloc(sizeof(t_gg));
//	toto = toto->next;

//	toto->str = argv3;
//	toto->next =  malloc(sizeof(t_gg));
//	toto = toto->next;

	toto->next = NULL;

	ft_do_pipe(save, f_d);

	return 0;
}
