/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_o.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 17:44:28 by nbeny             #+#    #+#             */
/*   Updated: 2017/02/27 18:26:02 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_modifier_o(t_flag *f, va_list *ap, t_list **begin_lst)
{
	if (f->flag[7] == 1)
		return (ft_handler_hho(f, ap, begin_lst));
	if (f->flag[8] == 1)
		return (ft_handler_ho(f, ap, begin_lst));
	if (f->flag[9] == 1)
		return (ft_handler_llo(f, ap, begin_lst));
	if (f->flag[10] == 1)
		return (ft_handler_lo(f, ap, begin_lst));
	if (f->flag[11] == 1)
		return (ft_handler_jo(f, ap, begin_lst));
	if (f->flag[12] == 1)
		return (ft_handler_zo(f, ap, begin_lst));
	return (0);
}

int		ft_handler_wo(t_flag *f, va_list *ap, t_list **begin_lst)
{
	f->arg = ft_ulitoa_base(
		(unsigned long int)va_arg(*ap, unsigned long int), 8);
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

int		ft_handler_o(t_flag *f, va_list *ap, t_list **begin_lst)
{
	if (f->flag[7] == 1 || f->flag[8] == 1 ||
		f->flag[9] == 1 || f->flag[10] == 1 ||
		f->flag[11] == 1 || f->flag[12] == 1)
		return (ft_modifier_o(f, ap, begin_lst));
	f->arg = ft_uitoa_base((unsigned int)va_arg(*ap, unsigned int), 8);
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
