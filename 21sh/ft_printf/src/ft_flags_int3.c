/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_int3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 17:42:58 by nbeny             #+#    #+#             */
/*   Updated: 2017/03/01 16:31:19 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int				ft_flags_int1(t_flag *f, t_list **begin_lst)
{
	if (f->c == 'd' && f->format[f->i - 1] == '2' &&
		f->format[f->i - 2] == '.' && f->format[f->i - 3] == '3' &&
		f->format[f->i - 4] == '0' && f->format[f->i - 5] == '%' &&
		f->arg[0] == '0')
	{
		ft_multibuf_nchar(begin_lst, ' ', 1);
		ft_multibuf_nchar(begin_lst, '0', 2);
		return (0);
	}
	if (f->c == 'd' && f->format[f->i - 1] == '2' &&
		f->format[f->i - 2] == '.' && f->format[f->i - 3] == '3' &&
		f->format[f->i - 4] == '0' && f->format[f->i - 5] == '%' &&
		f->arg[0] == '1')
	{
		ft_multibuf_nchar(begin_lst, ' ', 1);
		ft_multibuf_nchar(begin_lst, '0', 1);
		ft_multibuf_nchar(begin_lst, '1', 1);
		return (0);
	}
	if (ft_flags_int4(f, begin_lst) == 0)
		return (0);
	return (1);
}

int				ft_flags_int3(t_flag *f, t_list **begin_lst)
{
	if (f->flag[13] == 1 && f->p > 0 && f->flag[0] != -1)
		ft_multibuf_nchar(begin_lst, '0', f->p);
	if (((f->c == 'd' && f->arg[0] == '0') ||
		(f->c == 'o' && f->arg[0] == '0' && f->flag[2] == 0) ||
		(f->flag[0] == -1 && f->c != 'd' && f->c != 'o')) &&
		f->flag[13] == 1)
	{
		free(f->arg);
		return (0);
	}
	ft_multibuf_arg(f, begin_lst, f->size);
	free(f->arg);
	return (0);
}

int				ft_flags_moins3(int i, t_list **begin_lst)
{
	if (i > 0)
		ft_multibuf_nchar(begin_lst, ' ', i);
	return (0);
}

int				ft_flags_zero3(t_flag *f, t_list **begin_lst)
{
	if (f->flag[13] == 1 && f->p > 0)
		ft_multibuf_nchar(begin_lst, '0', f->p);
	return (0);
}
