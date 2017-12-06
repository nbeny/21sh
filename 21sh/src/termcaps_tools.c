/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:17:19 by nbeny             #+#    #+#             */
/*   Updated: 2017/12/06 15:17:20 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void	ft_rotchar(t_term *term)
{
	char	*p1;
	char	*p2;
	int		i;

	i = ft_strlen(term->line);
	p2 = ft_strsub(term->line, (term->pos + 1), i);
	p1 = ft_strsub(term->line, 0, term->pos);
	ft_strdel(&(term->line));
	term->line = ft_strjoin(p1, p2);
	ft_strdel(&p1);
	ft_strdel(&p2);
}

void	ft_strjoin_v2(t_term *term, int c)
{
	char	*new;
	char	buff[2];

	buff[0] = c;
	buff[1] = 0;
	new = ft_strjoin(term->line, buff);
	ft_strdel(&(term->line));
	term->line = ft_strdup(new);
	ft_strdel(&new);
}

void	ft_putnchar(int c, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		ft_putchar(c);
		i++;
	}
}

void	ft_clear_mlen(t_term *term, t_hty *hty)
{
	ft_move_home(term);
	tputs(tgetstr("sc", NULL), 1, ft_putchar);
	ft_putnchar(' ', term->mlen);
	tputs(tgetstr("rc", NULL), 1, ft_putchar);
	ft_strdel(&(term->line));
	term->line = ft_strdup(hty->cmd);
}
