#include "21sh.h"

t_red	*make_leftaddr(t_exec *exe, t_red *r, t_env *e)
{
	exe->error = ft_strdup("21sh: ambigous redirection after <&\n");
	return (r);
}

t_red	*make_trileft_redirection(t_exec *exe, t_red *r, t_env *e)
{
	char	*tmp;

	tmp = NULL;
	if (!ft_cmp_tabstr(exe->cmd))
	{
		tmp = ft_strjoin(r->file, "\n");
		creat_fd_or_file(tmp, exe, r);
		ft_strdel(&tmp);
	}
	return (r);
}

t_red	*make_doubleleftless(t_term *term, t_exec *exe, t_red *r, t_env *e)
{
 	 r = make_doubleleft(term, exe, r, e);	
	return (r);
}

t_red	*make_doubleleft(t_term *term, t_exec *exe, t_red *r, t_env *e)
{
	char	*tmp;
	int		i;

	i = 0;
	ft_strdel(&(term->line));
	term->prompt = 9;
	ft_putstr("heredoc> ");
	term->hty = ft_get_command(term, term->hty);
	while (ft_strncmp(term->line, r->file, (ft_strlen(r->file) + 1)))
	{
		if (i == 0)
			tmp = ft_strdup(term->line);
		else
			tmp = ft_strjoin(term->quot, term->line);
		i++;
		term->quot = ft_strjoin(tmp, "\n");
		ft_strdel(&tmp);
		ft_strdel(&(term->line));
		ft_putstr("heredoc> ");
		term->hty = ft_get_command(term, term->hty);
		if (ft_strncmp(term->line, r->file, (ft_strlen(r->file) + 1)))
			tmp = ft_strjoin(term->quot, term->line);
		else
			tmp = ft_strdup(term->quot);
		ft_strdel(&(term->quot));
		term->quot = tmp;
	}
	ft_strdel(&(term->line));
	r = creat_fd_or_file(term->quot, exe, r);
	ft_strdel(&(term->quot));
	return (r);
}

t_red	*make_leftpipe(t_exec *exe, t_red *r, t_env *e)
{
	exe->error = ft_strdup("21sh: syntax error near unexpected token `|'\n");
	return (r);
}
