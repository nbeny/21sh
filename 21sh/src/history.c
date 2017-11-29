#include "21sh.h"

t_hty	*ft_add_history(t_term *term)
{
	t_hty	*new;

	if (!(new = (t_hty *)malloc(sizeof(t_hty))))
		return (NULL);
	new->cmd = ft_strdup(term->line);
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_hty  *ft_mem_cmd(t_term *term, t_hty *hty)
{
    t_hty   *p;
	t_hty	*s;

    p = hty;
    if (hty != NULL)
    {
		while (p->next != NULL)
			p = p->next;
		s = p;
    	s->next = ft_add_history(term);
        s = s->next;
		s->prev = p;
    }
    else
    	hty = ft_add_history(term);
	return (hty);
}

t_hty	*ft_rollback_history(t_term *term, t_hty *hty)
{
	term->hmax = 1;
	if (hty != NULL)
	{
		while (hty->prev != NULL)
			hty = hty->prev;
		while (hty->next != NULL)
		{
			term->hmax++;
			hty = hty->next;
		}
		return (hty);
	}
	term->h = 0;
	return (NULL);
}

t_hty	*ft_up_arrow(t_term *term, t_hty *hty)
{
	if (hty != NULL)
	{
		if (term->h <= term->hmax)
			term->h++;
		if (term->h == 1)
		{
			ft_clear_mlen(term, hty);
			ft_putstr(hty->cmd);
			term->mlen = ft_strlen(hty->cmd);
			term->pos = term->mlen;
			return (hty);
		}
		else
		{
			if (hty->prev != NULL)
				hty = hty->prev;
			ft_clear_mlen(term, hty);
			ft_putstr(hty->cmd);
			term->mlen = ft_strlen(hty->cmd);
			term->pos = term->mlen;
			return (hty);
		}
	}
	else
		return (NULL);
}

t_hty	*ft_down_arrow(t_term *term, t_hty *hty)
{
	if (hty != NULL)
	{
		if (term->h >= 1)
			term->h--;
		if (term->h == 1)
		{
			ft_clear_mlen(term, hty);
			ft_putstr(hty->cmd);
			term->mlen = ft_strlen(hty->cmd);
			term->pos = term->mlen;
			return (hty);
		}
		else
		{
			if (hty->next != NULL)
				hty = hty->next;
			ft_clear_mlen(term, hty);
			ft_putstr(hty->cmd);
			term->mlen = ft_strlen(hty->cmd);
			term->pos = term->mlen;
			return (hty);
		}
	}
	else
		return (NULL);
}
