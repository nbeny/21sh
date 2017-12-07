/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:17:08 by nbeny             #+#    #+#             */
/*   Updated: 2017/12/06 15:17:09 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	if ((ansi = ft_strnew(10)) == NULL)
		return ;
	if ((buff = ft_strnew(50)) == NULL)
		return ;
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
	t_del	del;

	del.count = 0;
	if (term->pos != term->mlen)
	{
		tputs(tgetstr("im", NULL), 1, ft_putchar);
		tputs(tgetstr("ic", NULL), 1, ft_putchar);
		del.end = term->mlen - term->pos;
		del.i = term->ws_x - term->x;
		if ((term->x + del.end) >= term->ws_x)
			edit_line_ml(term, &del);
	}
	else
		tputs(tgetstr("ei", NULL), 1, ft_putchar);
}

void	get_char(t_term *term, char *buff, int *pull)
{
	ft_update_window(term);
	if (buff[0] != '\t')
	{
		ft_edit_line(term);
		ft_update_window(term);
		if (term->x == term->ws_x && term->pos != term->mlen)
			*pull = 1;
		write(0, buff, 6);
		if (*pull == 1)
		{
			tputs(tgetstr("do", NULL), 1, ft_putchar);
			*pull = 0;
		}
	}
	if (buff[0] == '\t')
		ft_tabulation(term);
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

t_hty	*ft_get_command(t_term *term, t_hty *hty)
{
	char	buff[6];
	int		pull;

	if (!ft_init_term(term))
		return (hty);
	ft_update_window(term);
	init_tt(term);
	pull = 0;
	hty = ft_rollback_history(term, hty);
	while (42)
	{
//		ft_printf(0, "[%i, %i, %i, %i, %i, %i]", buff[0], buff[1], buff[2], buff[3], buff[4], buff[5]);
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
			hty = check_buff_twentyseven(term, hty, buff);
		else
		{
			if (buff[0] == '\n')
				break ;
			get_char(term, buff, &pull);
		}
	}
	if (tcsetattr(0, TCSANOW, &(term->term_clean)) == -1)
		return (hty);
	ft_putchar('\n');
	return (hty);
}
