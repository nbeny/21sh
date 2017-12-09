/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 21:18:51 by nbeny             #+#    #+#             */
/*   Updated: 2017/12/06 21:18:55 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	init_tt(t_term *term)
{
	term->pos = 0;
	term->mlen = 0;
	term->h = 0;
	term->last = 0;
	term->line = ft_strdup("\0");
}

void	edit_line_ml(t_term *term, t_del *del)
{
	del->end = del->end - del->i;
	del->add = del->i;
	while (del->end > 0)
	{
		del->c = term->line[term->pos + del->add];
		tputs(tgetstr("cr", NULL), 1, ft_putchar);
		tputs(tgetstr("do", NULL), 1, ft_putchar);
		ft_putchar(del->c);
		tputs(tgoto(tgetstr("ch", NULL), 0, term->ws_x - 2), 1, ft_putchar);
		del->i = term->ws_x;
		del->add += del->i;
		del->end = del->end - del->i;
		del->count++;
	}
	while (del->count > 0)
	{
		del->count--;
		tputs(tgetstr("up", NULL), 1, ft_putchar);
		tputs(tgoto(tgetstr("ch", NULL), 0, term->x - 1), 1, ft_putchar);
	}
}

int		continue_buffer(t_norm *n)
{
	ft_update_window(n->term);
	ft_bzero(n->buff, 6);
	if (read(0, n->buff, 6) == -1)
		return (-1);
	if (n->buff[0] == 127 && n->buff[1] == '\0')
		ft_delete(n->term);
	else if (block_ctrl(n->buff))
		;
	else if (n->buff[0] == 4 && n->buff[1] == '\0')
		ft_make_ctrl_d(n->term);
	else if (n->buff[0] == 27)
		n->hty = check_buff_twentyseven(n->term, n->hty, n->buff);
	else
	{
		if (n->buff[0] == '\n')
			return (0);
		get_char(n->term, n->buff, &(n->pull));
	}
	return (1);
}

int		continue_buffer_other(t_norm *n)
{
	ft_update_window(n->term);
	ft_bzero(n->buff, 6);
	if (read(0, n->buff, 6) == -1)
		return (-1);
	if (n->buff[0] == 127 && n->buff[1] == '\0')
		ft_delete(n->term);
	else if (block_ctrl(n->buff))
		;
	else if (n->buff[0] == 4 && n->buff[1] == '\0')
		;
	else if (n->buff[0] == 27)
		n->hty = check_buff_twentyseven(n->term, n->hty, n->buff);
	else
	{
		if (n->buff[0] == '\n')
			return (0);
		get_char(n->term, n->buff, &(n->pull));
	}
	return (1);
}

t_hty	*ft_get_command_shell(t_term *term, t_hty *hty)
{
	t_norm	n;

	if (!ft_init_term(term))
		return (hty);
	ft_update_window(term);
	init_tt(term);
	n.pull = 0;
	hty = ft_rollback_history(term, hty);
	while (42)
	{
		n.term = term;
		n.hty = hty;
		if (!continue_buffer(&n))
			break ;
		hty = n.hty;
		term = n.term;
	}
	ft_move_end(term);
	ft_putchar('\n');
	if (tcsetattr(0, TCSANOW, &(term->term_clean)) == -1)
		return (hty);
	return (hty);
}
