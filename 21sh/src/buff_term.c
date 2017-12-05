#include "21sh.h"
/*
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
*/

t_hty	*next_check_buff(t_term *term, t_hty *hty, char *buff)
{
	if (buff[0] == 27 && buff[1] == 27 &&\
		buff[2] == 91 && buff[3] == 'C' &&\
		buff[4] == '\0')
		ft_optright_arrow(term);
	else if (buff[0] == 27 && buff[1] == 27 &&\
			 buff[2] == 91 && buff[3] == 'D' &&\
			 buff[4] == '\0')
		ft_optleft_arrow(term);
	else if (buff[0] == 27 && buff[1] == 91 &&\
			 buff[2] == 'H' && buff[3] == '\0')
		ft_move_home(term);
	else if (buff[0] == 27 && buff[1] == 91 &&\
			 buff[2] == 'F' && buff[3] == '\0')
		ft_move_end(term);
	else if (buff[0] == 27 && buff[1] == 91 &&\
			 buff[2] == 51 && buff[3] == 126 && buff[4] == '\0')
		ft_supp(term);
	return (hty);
}

t_hty	*check_buff_twentyseven(t_term *term, t_hty *hty, char *buff)
{
	if (buff[0] == 27 && buff[1] == 91 &&\
		buff[2] == 'A' && buff[3] == '\0')
		hty = ft_up_arrow(term, hty);
	else if (buff[0] == 27 && buff[1] == 91 &&\
			 buff[2] == 'B' && buff[3] == '\0')
		hty = ft_down_arrow(term, hty);
	else
		ft_rollback_history(term, hty);
	if (buff[0] == 27 && buff[1] == 91 &&\
		buff[2] == 'C' && buff[3] == '\0')
		ft_right_arrow(term);
	else if (buff[0] == 27 && buff[1] == 91 &&  \
			 buff[2] == 'D' && buff[3] == '\0')
		ft_left_arrow(term);
	else if (buff[0] == 27 && buff[1] == 27 &&  \
			 buff[2] == 91 && buff[3] == 'A' &&	\
			 buff[4] == '\0')
		ft_optup_arrow(term);
	else if (buff[0] == 27 && buff[1] == 27 &&  \
			 buff[2] == 91 && buff[3] == 'B' &&	\
			 buff[4] == '\0')
		ft_optdown_arrow(term);
	return (next_check_buff(term, hty, buff));
}
