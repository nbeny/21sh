/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_int2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 14:51:13 by nbeny             #+#    #+#             */
/*   Updated: 2017/03/15 04:03:21 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_flags_zero2(t_flag *f, int i, t_list **begin_lst)
{
	if (f->arg[0] == '-')
	{
		f->arg = ft_rotcstring(f->arg);
		ft_multibuf_nchar(begin_lst, '-', 1);
		f->size -= 1;
	}
	if (f->flag[2] == 1)
	{
		if ((f->arg[0] != '0' || f->c == 'p') && f->flag[0] != -1)
			ft_multibuf_ox(f, begin_lst, f->x);
	}
	if (i > 0)
		ft_multibuf_nchar(begin_lst, '0', i);
	if (f->c == 'X')
		ft_capitalizer(f->arg);
	return (ft_flags_zero3(f, begin_lst));
}

int		ft_flags_moins2(t_flag *f, t_list **begin_lst)
{
	if (f->flag[2] == 1)
	{
		if ((f->arg[0] != '0' || f->c == 'p') && f->flag[0] != -1)
			ft_multibuf_ox(f, begin_lst, f->x);
	}
	if (f->c == 'X')
		ft_capitalizer(f->arg);
	if (f->flag[13] == 1 && f->p > 0)
		ft_multibuf_nchar(begin_lst, '0', f->p);
	if (f->flag[0] != -1)
	{
		ft_multibuf_arg(f, begin_lst, f->size);
		free(f->arg);
	}
	return (0);
}

int		ft_flags_plus2(t_flag *f, t_list **begin_lst)
{
	if (f->flag[2] == 1)
	{
		if ((f->arg[0] != '0' || f->c == 'p') && f->flag[0] != -1)
			ft_multibuf_ox(f, begin_lst, f->x);
	}
	if (f->c == 'X')
		ft_capitalizer(f->arg);
	if (f->flag[13] == 1 && f->p > 0)
		ft_multibuf_nchar(begin_lst, '0', f->p);
	ft_flags_plus3(f, begin_lst);
	return (0);
}

int		ft_flags_plus3(t_flag *f, t_list **begin_lst)
{
	if (f->flag[0] != -1)
	{
		if (f->c == 'd' && f->format[f->i - 1] == ' ' &&
			f->format[f->i - 2] == '%' && f->arg[0] != '-')
			ft_multibuf_nchar(begin_lst, ' ', 1);
		ft_multibuf_arg(f, begin_lst, f->size);
		free(f->arg);
	}
	return (0);
}

int		ft_flags_int2(t_flag *f, t_list **begin_lst)
{
	if (f->arg[0] == '-' && f->flag[13] == 1 && f->flag[0] != -1)
	{
		f->arg = ft_rotcstring(f->arg);
		ft_multibuf_nchar(begin_lst, '-', 1);
		f->p += 1;
		f->size -= 1;
	}
	if (f->flag[2] == 1)
	{
		if ((f->arg[0] != '0' && f->flag[0] != -1) ||
			f->c == 'p' || f->c == 'o')
			ft_multibuf_ox(f, begin_lst, f->x);
	}
	if (f->c == 'X')
		ft_capitalizer(f->arg);
	ft_flags_int3(f, begin_lst);
	return (0);
}
