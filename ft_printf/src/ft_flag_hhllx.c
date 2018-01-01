/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_hhllx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 22:44:27 by nbeny             #+#    #+#             */
/*   Updated: 2017/02/27 20:02:25 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_handler_hhx(t_flag *f, va_list *ap, t_list **begin_lst)
{
	f->arg = ft_uchar_itoa_base(
		(unsigned char)va_arg(*ap, unsigned int), 16);
	f->size = ft_strlen(f->arg);
	if (f->flag[2] == 1 || f->flag[3] == 1 ||
		f->flag[4] == 1 || f->flag[5] == 1 ||
		f->flag[6] == 1 || f->flag[1] > (int)f->size ||
		f->flag[13] == 1)
		return (ft_flags_int(f, begin_lst));
	if (f->c == 'X')
		ft_capitalizer(f->arg);
	ft_multibuf_arg(f, begin_lst, f->size);
	free(f->arg);
	return (0);
}

int		ft_handler_hx(t_flag *f, va_list *ap, t_list **begin_lst)
{
	f->arg = ft_ushort_itoa_base(
		(unsigned short int)va_arg(*ap, unsigned int), 16);
	f->size = ft_strlen(f->arg);
	if (f->flag[2] == 1 || f->flag[3] == 1 ||
		f->flag[4] == 1 || f->flag[5] == 1 ||
		f->flag[6] == 1 || f->flag[1] > (int)f->size ||
		f->flag[13] == 1)
		return (ft_flags_int(f, begin_lst));
	if (f->c == 'X')
		ft_capitalizer(f->arg);
	ft_multibuf_arg(f, begin_lst, f->size);
	free(f->arg);
	return (0);
}

int		ft_handler_llx(t_flag *f, va_list *ap, t_list **begin_lst)
{
	f->arg = ft_ullitoa_base(
		(unsigned long long int)va_arg(*ap, unsigned long long int), 16);
	f->size = ft_strlen(f->arg);
	if (f->flag[2] == 1 || f->flag[3] == 1 ||
		f->flag[4] == 1 || f->flag[5] == 1 ||
		f->flag[6] == 1 || f->flag[1] > (int)f->size ||
		f->flag[13] == 1)
		return (ft_flags_int(f, begin_lst));
	if (f->c == 'X')
		ft_capitalizer(f->arg);
	ft_multibuf_arg(f, begin_lst, f->size);
	free(f->arg);
	return (0);
}

int		ft_handler_lx(t_flag *f, va_list *ap, t_list **begin_lst)
{
	f->arg = ft_ulitoa_base(
		(unsigned long int)va_arg(*ap, unsigned long int), 16);
	f->size = ft_strlen(f->arg);
	if (f->flag[2] == 1 || f->flag[3] == 1 ||
		f->flag[4] == 1 || f->flag[5] == 1 ||
		f->flag[6] == 1 || f->flag[1] > (int)f->size ||
		f->flag[13] == 1)
		return (ft_flags_int(f, begin_lst));
	if (f->c == 'X')
		ft_capitalizer(f->arg);
	ft_multibuf_arg(f, begin_lst, f->size);
	free(f->arg);
	return (0);
}
