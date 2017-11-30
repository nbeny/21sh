#include "21sh.h"

t_exec	*ft_new_exe(void)
{
	t_exec *e;

	if (!(e = (t_exec *)malloc(sizeof(t_exec))))
		return (NULL);
	e->cmd = NULL;
	e->mask = NULL;
	e->wait = 0;
	e->error = NULL;
	e->quot = NULL;
	e->red = NULL;
	e->fd.fd0 = -1;
	e->fd.fd1 = -1;
	e->fd.fd2 = -1;
	e->fd.ffd0 = 0;
	e->fd.ffd1 = 0;
	e->fd.ffd2 = 0;
	e->next = NULL;
	e->prev = NULL;
	e->first = 0;
	return (e);
}

t_exec	*ft_get_arg(t_term *term, t_exec *exe)
{
	term->p[0] = term->i;
	while (ft_isprint(term->line[term->i]) && term->line[term->i] != ' ' &&\
		term->line[term->i] != 9 && term->line[term->i] != ';' &&\
		term->line[term->i] != '|' && term->line[term->i] != '&' &&\
		term->line[term->i] != '>' && term->line[term->i] != '<' &&\
		term->line[term->i] != 34 && term->line[term->i] != 39 &&\
		term->line[term->i] != 0)
	{
		if (term->line[term->i] == '\\' && term->line[term->i + 1] != 0)
			term->i++;
		term->i++;
	}
	term->p[1] = term->i;
	exe = ft_build_quot(term, exe);
	return (exe);
}

t_exec	*ft_quot_separation(t_term *term, t_exec *exe)
{
	if (term->line[term->i++] == 34)
	{
		term->p[0] = term->i;
		while (term->line[term->i] != 34 && term->line[term->i] != 0)
			term->i++;
		if (term->line[term->i] == 0)
			ft_dquot(term, exe);
		else
			term->p[1] = term->i;
	}
	else
	{
		term->p[0] = term->i;
		while (term->line[term->i] != 39 && term->line[term->i] != 0)
			term->i++;
		if (term->line[term->i] == 0)
			ft_quot(term, exe);
		else
			term->p[1] = term->i;
	}
	exe = ft_build_quot(term, exe);
	term->i++;
	return (exe);
}

t_exec	*ft_parse_quot(t_term *term)
{
	t_exec	*exe;
	t_exec	*s;

	exe = ft_new_exe();
	exe->first = 1;
	s = exe;
	term->i = 0;
	exe->quot = NULL;
	while (term->line[term->i] != 0)
	{
		if (term->line[term->i] == 34 || term->line[term->i] == 39)
			s = ft_quot_separation(term, s);
		else if (term->line[term->i] == ';')
			s = ft_push_mask_v1(term, s, ";");
		else if (term->line[term->i] == '&')
			s = tri_and(term, s);
		else if (term->line[term->i] == '|')
			s = tri_pipe(term, s);
		else if (term->line[term->i] == '>')
			s = tri_right_redirection(term, s);
		else if (term->line[term->i] == '<')
			s = tri_left_redirection(term, s);
		else if (ft_isdigit(term->line[term->i]) &&\
			(term->line[term->i + 1] == '<' || term->line[term->i + 1] == '>'))
			s = tri_av_redirection(term, s);
		else if (ft_isprint(term->line[term->i]) && term->line[term->i] != ' ' &&\
			term->line[term->i] != '\t')
			s = ft_get_arg(term, s);
		else
			term->i++;
		if (term->error != NULL)
		{
			ft_printf(2, "%s", term->error);
			return (exe);
		}
	}
	s->cmd = ft_cmd_building(term, s);
//	ft_free_quote(exe->quot);
	return (exe);
}

t_exec  *ft_cmd_parcing(t_term *term)
{
	t_exec  *exe;
	t_exec	*s;
	t_red	*r;
	int		i;
	char    **split;

	exe = NULL;
	split = NULL;
	if (term->line != NULL && term->line[0] != '\0')
	{
			exe = ft_parse_quot(term);
			i = 0;
			s = exe;
			ft_printf(0, "command:\n{\n");
			while (s != NULL)
			{
				i = 0;
				if (s->cmd != NULL)
					while (s->cmd[i] != NULL)
					{
						if (s->mask != NULL)
							ft_printf(0, "{%s}", s->mask);
						ft_printf(0, "[%i:%s]", i, s->cmd[i]);
						i++;
					}
				ft_putstr("\\n\n");
				s = s->next;
			}
			ft_printf(0, "}\nredirection:\n{\n");
			s = exe;
			while (s != NULL)
			{
				r = s->red;
				while (r != NULL)
				{
					ft_printf(0, "r->mask = %s   r->file = [%s]   fd1-2 = {%i, %i}\n", r->mask, r->file, r->fd1, r->fd2);
					r = r->next;
				}
				ft_putstr("\\n\n");
				s = s->next;
			}
			ft_printf(0, "}\n");
	}
	return (exe);
}
