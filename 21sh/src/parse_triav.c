#include "21sh.h"

static t_exec	*tri_avav_right(t_term *term, t_exec *e)
{
	char	*s;

	if (ft_isdigit(term->line[term->i + 3]))
	{
		s = get_mask(term->line[term->i], '>',\
				'&', term->line[term->i + 3]);
		e = ft_push_red_fd12(term, e, s);
		ft_strdel(&s);
	}
	else if (term->line[term->i + 3] == '-')
	{
		s = get_mask(term->line[term->i], '>', '&', '-');
		e = ft_push_red_fd1(term, e, s);
		ft_putstr(s);
		ft_strdel(&s);
	}
	else
	{
		term->i += 3;
		e->error = ft_strdup("sh: parse error near `>&`\n");
	}
	return (e);
}

static t_exec	*tri_avav_left(t_term *term, t_exec *e)
{
	char	*s;

	if (ft_isdigit(term->line[term->i + 3]))
	{
		s = get_mask(term->line[term->i], '<',\
				'&', term->line[term->i + 3]);
		e = ft_push_red_fd12(term, e, s);
		ft_strdel(&s);
	}
	else if (term->line[term->i + 3] == '-')
	{
		s = get_mask(term->line[term->i], '<', '&', '-');
		e = ft_push_red_fd1(term, e, s);
		ft_strdel(&s);
	}
	else
	{
		term->i += 3;
		e->error = ft_strdup("sh: parse error near `>&`\n");
	}
	return (e);
}


static t_exec	*tri_av_right(t_term *term, t_exec *e)
{
	char	*s;

	if (term->line[term->i + 2] == '&')
		e = tri_avav_right(term, e);
	else if (term->line[term->i + 2] == '>')
	{
		s = get_mask(term->line[term->i], '>', '>', '\0');
		e = ft_push_red_fd1file(term, e, s);
		ft_strdel(&s);
	}
	else
	{
		s = get_mask(term->line[term->i], '>', '\0', '\0');
		e = ft_push_red_fd1file(term, e, s);
		ft_strdel(&s);
	}
	return (e);
}

static t_exec	*tri_av_left(t_term *term, t_exec *e)
{
	char	*s;

	if (term->line[term->i + 2] == '&')
		e = tri_avav_left(term, e);
	else if (term->line[term->i + 2] == '<')
	{
		s = get_mask(term->line[term->i], '<', '<', '\0');
		e = ft_push_red_fd1file(term, e, s);
		ft_strdel(&s);
	}
	else
	{
		s = get_mask(term->line[term->i], '<', '\0', '\0');
		e = ft_push_red_fd1file(term, e, s);
		ft_strdel(&s);
	}
	return (e);
}

t_exec			*tri_av_redirection(t_term *term, t_exec *e)
{
	if (ft_isdigit(term->line[term->i]) && term->line[term->i + 1] == '>')
		e = tri_av_right(term, e);
	else
		e = tri_av_left(term, e);
	return (e);
}
