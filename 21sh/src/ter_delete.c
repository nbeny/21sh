/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ter_delete.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:17:01 by nbeny             #+#    #+#             */
/*   Updated: 2017/12/06 15:17:02 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void	init_del(t_del *del)
{
	del->i = 0;
	del->c = 0;
	del->add = 0;
	del->end = 0;
	del->count = 0;
}

void	delete_end_line(t_term *term)
{
	if (term->x == 1)
	{
		tputs(tgetstr("up", NULL), 1, ft_putchar);
		tputs(tgoto(tgetstr("ch", NULL), 0, term->ws_x - 1), 1, ft_putchar);
		ft_putchar(' ');
		tputs(tgoto(tgetstr("ch", NULL), 0, term->ws_x - 1), 1, ft_putchar);
	}
	else
	{
		tputs(tgetstr("le", NULL), 1, ft_putchar);
		tputs(tgetstr("dc", NULL), 1, ft_putchar);
	}
}

void	delete_caractere(t_term *term)
{
	if (term->x == 1)
	{
		tputs(tgetstr("up", NULL), 1, ft_putchar);
		tputs(tgoto(tgetstr("ch", NULL), 0, term->ws_x - 1), 1, ft_putchar);
	}
	else
	{
		tputs(tgetstr("le", NULL), 1, ft_putchar);
		tputs(tgetstr("dc", NULL), 1, ft_putchar);
	}
}

void	delete_bcl(t_term *term, t_del *del)
{
	while (del->end > 0)
	{
		del->c = term->line[term->pos + del->add + 1];
		tputs(tgoto(tgetstr("ch", NULL), 0, term->ws_x - 1), 1, ft_putchar);
		ft_putchar(del->c);
		tputs(tgetstr("do", NULL), 1, ft_putchar);
		tputs(tgetstr("dc", NULL), 1, ft_putchar);
		del->add += term->ws_x;
		del->i = term->ws_x;
		del->end = del->end - del->i;
		del->count++;
	}
	while (del->count > 0)
	{
		del->count--;
		tputs(tgetstr("up", NULL), 1, ft_putchar);
		tputs(tgoto(tgetstr("ch", NULL), 0, term->x - 2), 1, ft_putchar);
	}
}

void	delete_core(t_term *term, t_del *del)
{
	del->end = term->mlen - term->pos;
	del->i = term->ws_x - term->x;
	if ((term->x + del->end) >= term->ws_x)
	{
		delete_caractere(term);
		del->end = del->end - del->i;
		del->add = del->i;
		delete_bcl(term, del);
	}
	else
	{
		if (term->x == 1)
		{
			tputs(tgetstr("up", NULL), 1, ft_putchar);
			tputs(tgoto(tgetstr("ch", NULL), 0, term->ws_x - 1), 1, ft_putchar);
			ft_putchar(' ');
			tputs(tgoto(tgetstr("ch", NULL), 0, term->ws_x - 1), 1, ft_putchar);
		}
		else
		{
			tputs(tgetstr("le", NULL), 1, ft_putchar);
			tputs(tgetstr("dc", NULL), 1, ft_putchar);
		}
	}
}
