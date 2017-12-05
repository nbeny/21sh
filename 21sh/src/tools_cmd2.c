#include "21sh.h"

int		ft_listsize_cmd(t_cmd *e)
{
	t_cmd	*s;
	int		i;

	i = 0;
	s = e;
	if (e != NULL)
	{
		while (s != NULL)
		{
			i++;
			s = s->next;
		}
	}
	return (i);
}

int		ft_cmp_tabstr(char **cmd)
{
	int		i;

	i = 1;
	while (cmd[i])
	{
		if (cmd[i][0] != '-')
			return(1);
		i++;
	}
	return (0);
}

t_red	*clear_creat(t_term *term, t_exec *exe, t_red *r)
{
    ft_strdel(&(term->line));
    if (!ft_strncmp(exe->mask, "|\0", 2))
        r = creat_fd_or_file(term->quot, exe, r);
    ft_strdel(&(term->quot));
	return (r);
}

void	start_heredoc(t_term *term)
{
    ft_strdel(&(term->line));
    term->prompt = 9;
    ft_putstr("heredoc> ");
    term->hty = ft_get_command(term, term->hty);
}

t_red	*creat_fd_or_file(char *quot, t_exec *exe, t_red *r)
{
	int		fd;

	fd = open("/tmp/file_generator",\
			O_WRONLY | O_TRUNC | O_CREAT,\
			S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
	if (fd == -1)
	{
		exe->error = ft_strdup("21sh: open return -1\n");
		return (r);
	}
	if ((r->fd1 == 0 || r->fd1 == -1) &&\
		(!ft_strncmp(exe->cmd[0], "as\0", 3) || !ft_strncmp(exe->cmd[0], "cat\0", 4)))
	{
		ft_putstr_fd(quot, fd);
		exe->c = ft_tab_to_list_cmd(exe->cmd);
		exe->c = add_cmd_str(exe->c, "/tmp/file_generator");
		free_cmd_str(exe->cmd);
		exe->cmd = ft_list_to_tab_cmd(exe->c);
		free_list_cmd_str(exe->c);
		exe->c = NULL;
	}
	close(fd);
	return (r);
}
