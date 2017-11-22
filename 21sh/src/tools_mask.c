#include "21sh.h"

t_env	*boucle_numeric_or(t_exec *exe, t_env *e)
{
	t_exec	*s;

	s = exe;
	s->jp_nxt = 0;
	while (s && s->mask && s->mask[0] == '|' && \
		s->mask[1] == '|')
	{
		s->jp_nxt++;
		e = make_numeric_or(s, e);
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

t_env	*boucle_numeric_and(t_exec *exe, t_env *e)
{
	t_exec	*s;

	s = exe;
	s->jp_nxt = 0;
	while (s && s->mask && s->mask[0] == '&' && \
		s->mask[1] == '&')
	{
		s->jp_nxt++;
		e = make_numeric_or(s, e);
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

t_env	*boucle_pipe(t_exec *exe, t_env *e)
{
	t_exec	*s;

	s = exe;
	s->jp_nxt = 0;
	while (s && s->mask && s->mask[0] == '|' && \
		s->mask[1] == '\0')
	{
		s->jp_nxt++;
		e = make_pipe(s, e);
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
