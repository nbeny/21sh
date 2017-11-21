#include "21sh.h"

t_red	*creat_redirection()
{
	t_red	*r;

	if (!(r = (t_red *)malloc(sizeof(t_red))))
		return (NULL);
	r->mask = NULL;
	r->file = NULL;
	r->fd1 = -1;
	r->fd2 = -1;
	r->next = NULL;
	return (r);
}

t_exec	*ft_push_red_file(t_term *term, t_exec *e, char	*str)
{
	t_red	*r;

	term->i += ft_strlen(str);
	while (term->line[term->i] != '\0' &&\
		(term->line[term->i] == ' ' || term->line[term->i] == '\t'))
		term->i++;
	term->p[0] = term->i;
	while (ft_isprint(term->line[term->i]) && term->line[term->i] != ' ' &&\
		term->line[term->i] != '\t' && term->line[term->i] != '\n')
		term->i++;
	term->p[1] = term->i;
	if (term->p[0] == term->p[1])
	{
		ft_printf(2, "parse error near `\\n`\n");
		return (e);
	}
	if (e->red != NULL)
	{
		r = e->red;
		while (r->next != NULL)
			r = r->next;
		r->next = creat_redirection();
		r = r->next;
		r->file = ft_strsub(term->line, term->p[0], term->p[1]);
		r->mask = ft_strdup(str);
	}
	else
	{
		e->red = creat_redirection();
		r = e->red;
		r->file = ft_strsub(term->line, term->p[0], term->p[1]);
		r->mask = ft_strdup(str);
	}
	return (e);
}

t_exec	*ft_push_red_fd12(t_term *term, t_exec *e, char	*str)
{
	t_red	*r;

	term->i += ft_strlen(str);
	if (e->red != NULL)
	{
		r = e->red;
		while (r->next != NULL)
			r = r->next;
		r->next = creat_redirection();
		r = r->next;
		r->mask = ft_strdup(str);
		r->fd1 = ft_atoi(str);
		r->fd2 = ft_atoi(&str[ft_strlen(str) - 1]);
	}
	else
	{
		e->red = creat_redirection();
		r = e->red;
		r->mask = ft_strdup(str);
		r->fd1 = ft_atoi(str);
		r->fd2 = ft_atoi(&str[ft_strlen(str) - 1]);
	}
	return (e);
}

t_exec	*ft_push_red_fd1(t_term *term, t_exec *e, char *str)
{
	t_red	*r;

	term->i += ft_strlen(str);
	if (e->red != NULL)
	{
		r = e->red;
		while (r->next != NULL)
			r = r->next;
		r->next = creat_redirection();
		r = r->next;
		r->mask = ft_strdup(str);
		r->fd1 = ft_atoi(str);
	}
	else
	{
		e->red = creat_redirection();
		r = e->red;
		r->mask = ft_strdup(str);
		r->fd1 = ft_atoi(str);
	}
	return (e);
}

t_exec	*ft_push_red_error(t_term *term, t_exec *e, char *str)
{
	t_red	*r;

	term->i += ft_strlen(str);
	if (e->red != NULL)
	{
		r = e->red;
		while (r->next != NULL)
			r = r->next;
		r->next = creat_redirection();
		r = r->next;
		r->mask = ft_strdup(str);
	}
	else
	{
		e->red = creat_redirection();
		r = e->red;
		r->mask = ft_strdup(str);
	}
	return (e);
}

t_exec	*ft_push_red_fd1file(t_term *term, t_exec *e, char	*str)
{
	t_red	*r;

	term->i += ft_strlen(str);
	while (term->line[term->i] != '\0' &&\
		(term->line[term->i] == ' ' || term->line[term->i] == '\t'))
		term->i++;
	term->p[0] = term->i;
	while (ft_isprint(term->line[term->i]) && term->line[term->i] != ' ' &&\
		term->line[term->i] != '\t' && term->line[term->i] != '\n')
		term->i++;
	term->p[1] = term->i;
	if (term->p[0] == term->p[1])
	{
		ft_printf(2, "parse error near `\\n`\n");
		return (e);
	}
	if (e->red != NULL)
	{
		r = e->red;
		while (r->next != NULL)
			r = r->next;
		r->next = creat_redirection();
		r = r->next;
		r->file = ft_strsub(term->line, term->p[0], term->p[1]);
		r->mask = ft_strdup(str);
		r->fd1 = ft_atoi(str);
	}
	else
	{
		e->red = creat_redirection();
		r = e->red;
		r->file = ft_strsub(term->line, term->p[0], term->p[1]);
		r->mask = ft_strdup(str);
		r->fd1 = ft_atoi(str);
	}
	return (e);
}
