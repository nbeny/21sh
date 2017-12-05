#include "21sh.h"

int		ft_init_term(t_term *term)
{
	if ((term->name = getenv("TERM")) == NULL)
		return (0);
	if (tgetent(NULL, term->name) == -1)
		return (0);
	if (tcgetattr(0, &(term->term_clean)) == -1)
		return (0);
	if (tcgetattr(0, &(term->term)) == -1)
		return (0);
	term->clear = tgetstr("cl", NULL);
	term->cursor = tgetstr("cm", NULL);
	term->shadow = tgetstr("vi", NULL);
	term->term.c_lflag &= ~(ICANON);
	term->term.c_lflag &= ~(ECHO);
	term->term.c_cc[VMIN] = 1;
	term->term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &(term->term)) == -1)
		return (0);
	return (1);
}

void	ft_update_window(t_term *term)
{
	struct winsize	ws;
	char			*ansi;
	char			*buff;
	char			*tmp;

	ansi = ft_strnew(1);
	buff = ft_strnew(10);
	ioctl(0, TIOCGWINSZ, &ws);
	term->ws_y = ws.ws_row;
	term->ws_x = ws.ws_col;
	ft_printf(0, "\E[6n");
	while (ft_strchr(buff, 'R') == NULL)
	{
		ft_bzero(buff, 10);
		read(0, buff, 10);
		tmp = ansi;
		ansi = ft_strjoin(tmp, buff);
		ft_strdel(&tmp);
	}
	term->y = ft_atoi(&ansi[2]);
	term->x = ft_atoi(&ft_strchr(&ansi[2], ';')[1]);
	ft_strdel(&buff);
	ft_strdel(&ansi);
}

void	ft_edit_line(t_term *term)
{
	int		i;
	int		c;
	int		end;
	int		add;
	int		count;

	count = 0;
	if (term->pos != term->mlen)
	{
		tputs(tgetstr("im", NULL), 1, ft_putchar);
		tputs(tgetstr("ic", NULL), 1, ft_putchar);
		end = term->mlen - term->pos;
		i = term->ws_x - term->x;
		if ((term->x + end) >= term->ws_x)
		{
			end = end - i;
			add = i;
			while (end > 0)
			{
				c = term->line[term->pos + add];
				tputs(tgetstr("cr", NULL), 1, ft_putchar);
				tputs(tgetstr("do", NULL), 1, ft_putchar);
				ft_putchar(c);
				tputs(tgoto(tgetstr("ch", NULL), 0, term->ws_x - 2), 1, ft_putchar);
				i = term->ws_x;
				add += i;
				end = end - i;
				count++;
			}
			while (count > 0)
			{
				count--;
				tputs(tgetstr("up", NULL), 1, ft_putchar);
				tputs(tgoto(tgetstr("ch", NULL), 0, term->x - 1), 1, ft_putchar);
			}
		}
	}
	else
		tputs(tgetstr("ei", NULL), 1, ft_putchar);
}

t_hty		*ft_get_command(t_term *term, t_hty *hty)
{
	char	buff[6];
	int		pull;

	if (!ft_init_term(term))
		return (hty);
	ft_update_window(term);
	term->pos = 0;
	term->mlen = 0;
	term->h = 0;
	term->last = 0;
	pull = 0;
	hty = ft_rollback_history(term, hty);
	term->line = ft_strdup("\0");
	while (42)
	{
//		ft_printf(0, "[%i,%i,%i,%i,%i,%i]", buff[0], buff[1], buff[2], buff[3], buff[4], buff[5]);
//		tputs(tgetstr("st", NULL), 1, ft_putchar);
		ft_update_window(term);
		ft_bzero(buff, 6);
		if (read(0, buff, 6) == -1)
			return (hty);
		if (buff[0] == 127 && buff[1] == '\0')
			ft_delete(term);
		else if (block_ctrl(buff))
			;
		else if (buff[0] == 4 && buff[1] == '\0')
			ft_make_ctrl_d(term);
		else if (buff[0] == 27)
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
			else if (buff[0] == 27 && buff[1] == 91 &&	\
					 buff[2] == 'D' && buff[3] == '\0')
				ft_left_arrow(term);
			else if (buff[0] == 27 && buff[1] == 27 &&	\
				buff[2] == 91 && buff[3] == 'A' &&	\
					 buff[4] == '\0')
				ft_optup_arrow(term);
			else if (buff[0] == 27 && buff[1] == 27 &&	\
				buff[2] == 91 && buff[3] == 'B' &&	\
					 buff[4] == '\0')
				ft_optdown_arrow(term);
			else if (buff[0] == 27 && buff[1] == 27 &&\
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
		}
		else
		{
			ft_update_window(term);
			if (buff[0] != '\t')
			{
				ft_edit_line(term);
				ft_update_window(term);
				if (term->x == term->ws_x && term->pos != term->mlen)
					pull = 1;
				write(0, buff, 6);
				if (pull == 1)
				{
					tputs(tgetstr("do", NULL), 1, ft_putchar);
					pull = 0;
				}
			}
			if (buff[0] == '\t')
				ft_tabulation(term);
			else if (buff[0] == '\n')
				break ;
			else
			{
				if (term->pos != term->mlen)
					ft_insert_char(term, buff[0]);
				else
					ft_strjoin_v2(term, buff[0]);
				term->pos++;
				term->mlen++;
			}
		}
	}
	if (tcsetattr(0, TCSANOW, &(term->term_clean)) == -1)
		return (0);
	return (hty);
}
