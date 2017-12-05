#include "21sh.h"

void	ft_left_arrow(t_term *term)
{
	ft_update_window(term);
	if (term->pos > 0)
	{
		if (term->x == 1)
		{
			tputs(tgetstr("up", NULL), 1, ft_putchar);
			tputs(tgoto(tgetstr("ch", NULL), 0, term->ws_x - 1), 1, ft_putchar);
		}
		else
		{
			if (term->line[term->pos - 1] == '\t')
				tputs(tgetstr("bt", NULL), 1, ft_putchar);
			else
				tputs(tgetstr("le", NULL), 1, ft_putchar);
		}
		term->pos--;
	}
}

void	ft_right_arrow(t_term *term)
{
	ft_update_window(term);
	if (term->pos < term->mlen)
	{
		if (term->x == term->ws_x)
			tputs(tgetstr("do", NULL), 1, ft_putchar);
		else
		{
			if (term->line[term->pos] == '\t')
				tputs(tgetstr("ta", NULL), 1, ft_putchar);
			else
				tputs(tgetstr("nd", NULL), 1, ft_putchar);
		}
		term->pos++;
	}
}

void	ft_move_home(t_term *term)
{
	ft_update_window(term);
	while (term->pos != 0)
		ft_left_arrow(term);
}

void	ft_move_end(t_term *term)
{
	ft_update_window(term);
	while (term->pos != term->mlen)
		ft_right_arrow(term);
}
