#include "21sh.h"

char	*ft_add_path(char *path, char *file)
{
	char	*new;
	char	*tmp;

	tmp = ft_strjoin(path, "/");
	new = ft_strjoin(tmp, file);
	ft_strdel(&tmp);
	return (new);
}

t_env	*boucle_numeric_or(t_term *term, t_exec *exe, t_env *e)
{
	t_exec	*s;

	s = exe;
	s->jp_nxt = 0;
	while (s && s->mask && s->mask[0] == '|' && \
		s->mask[1] == '|')
	{
		s->jp_nxt++;
		e = make_numeric_or(term, s, e);
		if (s->error != NULL)
			while (s && s->mask && s->mask[0] == '|' && \
				s->mask[1] == '|')
			{
				s->jp_nxt++;
				s = s->next;
			}
	}
	return (e);
}

t_env	*boucle_numeric_and(t_term *term, t_exec *exe, t_env *e)
{
	t_exec	*s;

	s = exe;
	s->jp_nxt = 0;
	while (s && s->mask && s->mask[0] == '&' && \
		s->mask[1] == '&')
	{
		s->jp_nxt++;
		e = make_numeric_or(term, s, e);
		if (s->error == NULL)
			while (s && s->mask && s->mask[0] == '&' && \
				s->mask[1] == '&')
			{
				s->jp_nxt++;
				s = s->next;
			}
	}
	return (e);
}

t_env	*boucle_pipe(t_term *term, t_exec *exe, t_env *e)
{
	t_exec	*s;

	s = exe;
	s->jp_nxt = 0;
	while (s && s->mask && s->mask[0] == '|' && \
		s->mask[1] == '\0')
	{
		s->jp_nxt++;
		e = make_pipe(term, s, e);
		if (s->error == NULL)
			while (s && s->mask && s->mask[0] == '|' && \
				s->mask[1] == '\0')
			{
				s->jp_nxt++;
				s = s->next;
			}
	}
	return (e);
}
