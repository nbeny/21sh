/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ter1delete.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:16:52 by nbeny             #+#    #+#             */
/*   Updated: 2017/12/06 15:16:54 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_delete(t_term *term)
{
	t_del	del;

	init_del(&del);
	tputs(tgetstr("ei", NULL), 1, ft_putchar);
	ft_update_window(term);
	if (term->pos > 0)
	{
		if (term->pos == term->mlen)
			delete_end_line(term);
		else
			delete_core(term, &del);
		term->pos--;
		term->mlen--;
		ft_rotchar(term);
	}
}

void	ft_multiline_supp(t_term *term, t_del *del)
{
	tputs(tgetstr("dc", NULL), 1, ft_putchar);
	del->end -= del->i;
	while (del->end > 1)
	{
		del->i = term->ws_x;
		del->end -= del->i;
		del->c = term->line[term->pos + del->add + 1];
		tputs(tgoto(tgetstr("ch", NULL), 0, term->ws_x - 1), 1, ft_putchar);
		ft_putchar(del->c);
		tputs(tgetstr("do", NULL), 1, ft_putchar);
		tputs(tgetstr("cr", NULL), 1, ft_putchar);
		tputs(tgetstr("dc", NULL), 1, ft_putchar);
		del->add += del->i;
		del->count++;
	}
	while (del->count != 0)
	{
		tputs(tgetstr("up", NULL), 1, ft_putchar);
		tputs(tgoto(tgetstr("ch", NULL), 0, term->x - 1), 1, ft_putchar);
		del->count--;
	}
}

void	ft_supp(t_term *term)
{
	t_del	del;

	tputs(tgetstr("ei", NULL), 1, ft_putchar);
	del.count = 0;
	ft_update_window(term);
	if (term->pos != term->mlen)
	{
		del.end = term->mlen - term->pos;
		del.i = term->ws_x - term->x;
		del.add = del.i;
		if (term->x + del.end > term->ws_x)
			ft_multiline_supp(term, &del);
		else
			tputs(tgetstr("dc", NULL), 1, ft_putchar);
		term->mlen--;
		ft_rotchar(term);
	}
}
