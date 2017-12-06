/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_termcaps.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:17:57 by nbeny             #+#    #+#             */
/*   Updated: 2017/12/06 15:17:58 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void	ft_make_ctrl_d(t_term *term)
{
	if (!ft_strncmp(term->line, "\0", 1))
	{
		if (tcsetattr(0, TCSANOW, &(term->term_clean)) == -1)
			return ;
		ft_putstr("exit\n");
		exit(EXIT_SUCCESS);
	}
	else
		;
}

int		block_ctrl(char *buff)
{
	if ((buff[0] == 8 && buff[1] == '\0') ||\
		(buff[0] == 21 && buff[1] == '\0') ||\
		(buff[0] == 1 && buff[1] == '\0') ||\
		(buff[0] == 11 && buff[1] == '\0') ||\
		(buff[0] == 7 && buff[1] == '\0') ||\
		(buff[0] == 6 && buff[1] == '\0') ||\
		(buff[0] == 16 && buff[1] == '\0') ||\
		(buff[0] == 20 && buff[1] == '\0') ||\
		(buff[0] == 18 && buff[1] == '\0') ||\
		(buff[0] == 5 && buff[1] == '\0') ||\
		(buff[0] == 23 && buff[1] == '\0'))
		return (1);
	return (0);
}

void	ft_tabulation(t_term *term)
{
	int	pull;
	int	i;

	i = 0;
	pull = 0;
	while (i != 3)
	{
		ft_update_window(term);
		ft_edit_line(term);
		ft_update_window(term);
		if (term->x == term->ws_x && term->pos != term->mlen)
			pull = 1;
		ft_putchar(' ');
		if (pull == 1)
		{
			tputs(tgetstr("do", NULL), 1, ft_putchar);
			pull = 0;
		}
		if (term->pos != term->mlen)
			ft_insert_char(term, ' ');
		else
			ft_strjoin_v2(term, ' ');
		term->pos++;
		term->mlen++;
		i++;
	}
}
