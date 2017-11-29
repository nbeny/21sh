#include "21sh.h"

void	ft_free_quot(t_quot *quot)
{
	t_quot	*s;
	t_quot	*f;

	s = quot;
	if (quot)
		while (s)
		{
			f = s;
			ft_strdel(&(s->arg));
			s = s->next;
			free(f);
			f = NULL;
		}
}

void	ft_free_red(t_red *r)
{
	t_red	*s;
	t_red	*f;

	s = r;
	if (r)
		while (s)
		{
			f = s;
			ft_strdel(&(s->mask));
			ft_strdel(&(s->file));
			s = s->next;
			free(f);
			f = NULL;
		}
}

void	ft_free_hty(t_hty *hty)
{
	t_hty	*s;
	t_hty	*f;

	s = hty;
	if (hty)
		while (s)
		{
			f = s;
			ft_strdel(&(hty->cmd));
			s = s->next;
			free(f);
			f = NULL;
		}
}

void	ft_free_term(t_term *t)
{
	if (t)
	{
		if (t->hty)
			ft_free_hty(t->hty);
	}
}
