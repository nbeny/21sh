/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 15:00:13 by nbeny             #+#    #+#             */
/*   Updated: 2017/03/07 11:46:17 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_handler_wc(t_flag *f, va_list *ap, t_list **begin_lst)
{
	wchar_t	wc;
	wchar_t	ws[2];

	wc = va_arg(*ap, wint_t);
	ws[0] = wc;
	ws[1] = 0;
	if (ws[0] < 0 && ws[0] > 55295 && ws[0] < 57344 && ws[0] > 1114111)
		return (0);
	f->size = (size_t)ft_wcharlen(wc);
	f->arg = ft_transform_wchar_in_char(ws, f);
	f->free = 1;
	if (f->flag[2] == 1 || f->flag[3] == 1 ||
		f->flag[4] == 1 || f->flag[5] == 1 ||
		f->flag[6] == 1 || f->flag[1] > (int)f->size ||
		f->flag[13] == 1)
		return (ft_flags_char(f, begin_lst));
	ft_multibuf_arg(f, begin_lst, f->size);
	return (0);
}

int		ft_handler_c(t_flag *f, va_list *ap, t_list **begin_lst)
{
	char c;
	char s[2];

	if (f->flag[10] == 1)
		return (ft_handler_wc(f, ap, begin_lst));
	c = (char)va_arg(*ap, int);
	s[0] = c;
	s[1] = 0;
	f->arg = s;
	f->size = 1;
	if (f->flag[2] == 1 || f->flag[3] == 1 ||
		f->flag[4] == 1 || f->flag[5] == 1 ||
		f->flag[6] == 1 || f->flag[1] > (int)f->size ||
		f->flag[13] == 1)
		return (ft_flags_char(f, begin_lst));
	ft_multibuf_arg(f, begin_lst, f->size);
	return (0);
}
