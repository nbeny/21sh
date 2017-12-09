/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:17:31 by nbeny             #+#    #+#             */
/*   Updated: 2017/12/06 15:17:31 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_insert_char(t_term *term, int c)
{
	char	tmp[2];
	char	*swap;
	char	*p1;
	char	*p2;

	tmp[0] = c;
	tmp[1] = 0;
	swap = ft_strsub(term->line, 0, term->pos);
	p2 = ft_strsub(term->line, term->pos, ft_strlen(term->line));
	p1 = ft_strjoin(swap, tmp);
	ft_strdel(&swap);
	ft_strdel(&(term->line));
	term->line = ft_strjoin(p1, p2);
	ft_strdel(&p1);
	ft_strdel(&p2);
}

void	ft_multiligne_insert_char(t_term *term)
{
	char	*tmp;
	int		i;

	i = term->pos - 1;
	tmp = ft_strdup(term->line);
	tputs(tgetstr("sc", NULL), 1, ft_putchar);
	ft_putstr(&tmp[i]);
	tputs(tgetstr("rc", NULL), 1, ft_putchar);
	if (term->x >= term->ws_x)
		ft_right_arrow(term);
}

void	ft_multiligne_insert(t_term *term, int c)
{
	if ((term->x + (term->mlen - term->pos)) < term->ws_x &&\
		((term->mlen + term->prompt) % term->ws_x) != 0)
		tputs(tgetstr("im", NULL), 1, ft_putchar);
	else
	{
		ft_multiligne_insert_char(term);
		if (term->y == term->ws_y)
			tputs(tgoto(tgetstr("ch", NULL), 0, term->ws_y - 1), 1, ft_putchar);
	}
}

void	ft_putendl_error(char *str)
{
	char	*print;

	print = NULL;
	print = ft_strjoin("command not found: ", str);
	ft_putendl_fd(print, 2);
	ft_strdel(&print);
}
