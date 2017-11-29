#include "21sh.h"

void	ft_optup_arrow(t_term *term)
{
	if (term->pos - term->ws_x >= 0)
	{
		term->pos -= term->ws_x;
		tputs(tgetstr("up", NULL), 1, ft_putchar);
	}
	else
		ft_move_home(term);
}

void	ft_optdown_arrow(t_term *term)
{
	if (term->pos + term->ws_x <= term->mlen)
	{
		term->pos += term->ws_x;
		tputs(tgetstr("do", NULL), 1, ft_putchar);
		tputs(tgoto(tgetstr("ch", NULL), 0, term->x - 1), 1, ft_putchar);
	}
	else
		ft_move_end(term);
}

void	ft_optright_arrow(t_term *term)
{
	while (term->line[term->pos] == ' ' || term->line[term->pos] == '\t')
		ft_right_arrow(term);
	while (term->line[term->pos] != ' ' && term->line[term->pos] != '\t' &&	\
		   term->line[term->pos] != '\0')
		ft_right_arrow(term);
}

void	ft_optleft_arrow(t_term *term)
{
	if (term->line && term->pos > 0)
	{
		if ((term->line[term->pos - 1] == ' ' || term->line[term->i - 1] == '\t') && \
			term->pos > 0)
			ft_left_arrow(term);
		while (term->line[term->pos] == ' ' || term->line[term->pos] == '\t')
			ft_left_arrow(term);
		while (term->line[term->pos] != ' ' && term->line[term->pos] != '\t' &&	\
			   term->pos > 0)
			ft_left_arrow(term);
		if (term->pos > 0)
			ft_right_arrow(term);
	}
}
