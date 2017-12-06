/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buff_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:13:27 by nbeny             #+#    #+#             */
/*   Updated: 2017/12/06 15:13:28 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

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
	else if (buff[0] == 27 && buff[1] == 91 &&\
		buff[2] == 'D' && buff[3] == '\0')
		ft_left_arrow(term);
	else if (buff[0] == 27 && buff[1] == 27 &&\
		buff[2] == 91 && buff[3] == 'A' && \
		buff[4] == '\0')
		ft_optup_arrow(term);
	else if (buff[0] == 27 && buff[1] == 27 && \
		buff[2] == 91 && buff[3] == 'B' && \
		buff[4] == '\0')
		ft_optdown_arrow(term);
	return (next_check_buff(term, hty, buff));
}
