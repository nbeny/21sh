#include "21sh.h"

t_term  *ft_left_arrow(t_term *term)
{
    if (term->x > term->pos_x && term->y == term->pos_y)
    {
        term->x -= 1;
        tputs(tgoto(term->cursor, term->x, term->y), 1, ft_putchar);
	return (term);
    }
    else if (term->x <= 0 && term->y > term->pos_y)
    {
        term->x	-= 1;
        term->y	= ws_y - 1;
        tputs(tgoto(term->cursor, term->x, term->y), 1, ft_putchar);
	return (term);
    }
    else
	return (term);
}

t_term  *ft_right_arrow(t_term *term, char *buff)
{
    if (term->x > term->pos_x && term->y == term->pos_y)
    {
        term->x += 1;
        tputs(tgoto(term->cursor, term->x, term->y), 1, ft_putchar);
	return (term);
    }
    else if (term->x <= (term->ws_x - 1) && term->y >= term->pos_y &&\
        buff[6] != 0 && buff[6] != -1)
    {
	term->y += 1;
        term->x	= 0;
        tputs(tgoto(term->cursor, term->x, term->y), 1, ft_putchar);
	return (term);
    }
}
