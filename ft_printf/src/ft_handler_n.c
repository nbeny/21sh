/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_n.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 11:05:56 by nbeny             #+#    #+#             */
/*   Updated: 2017/03/07 11:06:00 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_handler_n(t_flag *f, va_list *ap, t_list **begin_lst)
{
	f->arg = ft_uitoa_base((unsigned int)va_arg(*ap, unsigned int), 9);
	f->size = ft_strlen(f->arg);
	if (f->flag[2] == 1 || f->flag[3] == 1 ||
		f->flag[4] == 1 || f->flag[5] == 1 ||
		f->flag[6] == 1 || f->flag[1] > (int)f->size ||
		f->flag[13] == 1)
		return (ft_flags_int(f, begin_lst));
	ft_multibuf_arg(f, begin_lst, f->size);
	free(f->arg);
	return (0);
}
