/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 15:00:23 by nbeny             #+#    #+#             */
/*   Updated: 2017/02/27 18:25:43 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_modifier_d(t_flag *f, va_list *ap, t_list **begin_lst)
{
	if (f->flag[7] == 1)
		return (ft_handler_hhd(f, ap, begin_lst));
	if (f->flag[8] == 1)
		return (ft_handler_hd(f, ap, begin_lst));
	if (f->flag[9] == 1)
		return (ft_handler_lld(f, ap, begin_lst));
	if (f->flag[10] == 1)
		return (ft_handler_ld(f, ap, begin_lst));
	if (f->flag[11] == 1)
		return (ft_handler_jd(f, ap, begin_lst));
	if (f->flag[12] == 1)
		return (ft_handler_zd(f, ap, begin_lst));
	return (0);
}

int		ft_handler_wd(t_flag *f, va_list *ap, t_list **begin_lst)
{
	f->arg = ft_litoa_base((long int)va_arg(*ap, long int), 10);
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

int		ft_handler_d(t_flag *f, va_list *ap, t_list **begin_lst)
{
	if (f->flag[7] == 1 || f->flag[8] == 1 ||
		f->flag[9] == 1 || f->flag[10] == 1 ||
		f->flag[11] == 1 || f->flag[12] == 1)
		return (ft_modifier_d(f, ap, begin_lst));
	f->arg = ft_itoa((int)va_arg(*ap, int));
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
