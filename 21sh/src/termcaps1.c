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

#include "21sh.h"

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
