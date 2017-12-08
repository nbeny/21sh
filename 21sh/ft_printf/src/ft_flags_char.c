/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 14:59:36 by nbeny             #+#    #+#             */
/*   Updated: 2017/03/15 02:01:26 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_flag_moins(t_flag *f, t_list **begin_lst)
{
	int	i;

	if (f->flag[13] == 1 && f->flag[0] < (int)f->size &&
		f->c != '%' && f->c != 'c' && f->c != 'C' &&
		f->what != 1)
	{
		if (f->flag[0] == -1)
			f->flag[0] = 0;
		f->size = (size_t)f->flag[0];
	}
	i = f->flag[1] - (int)f->size;
	if (f->size > 0)
		ft_multibuf_arg(f, begin_lst, f->size);
	if (i > 0)
		ft_multibuf_nchar(begin_lst, ' ', (size_t)i);
	return (0);
}

static int	ft_flag_plus(t_flag *f, t_list **begin_lst)
{
	int	i;

	if (f->flag[13] == 1 && f->flag[0] < (int)f->size &&
		f->c != '%' && f->c != 'c' && f->c != 'C' &&
		f->what != 1)
	{
		if (f->flag[0] == -1)
			f->flag[0] = 0;
		f->size = (size_t)f->flag[0];
	}
	i = f->flag[1] - (int)f->size;
	if (i > 0)
		ft_multibuf_nchar(begin_lst, ' ', (size_t)i);
	if (f->size > 0)
		ft_multibuf_arg(f, begin_lst, f->size);
	return (0);
}

static int	ft_flag_zero(t_flag *f, t_list **begin_lst)
{
	int	i;

	if (f->flag[13] == 1 && f->flag[0] < (int)f->size &&
		f->c != '%' && f->c != 'c' && f->c != 'C' &&
		f->what != 1)
	{
		if (f->flag[0] == -1)
			f->flag[0] = 0;
		f->size = (size_t)f->flag[0];
	}
	i = f->flag[1] - (int)f->size;
	if (i > 0)
		ft_multibuf_nchar(begin_lst, '0', (size_t)i);
	if (f->size > 0)
		ft_multibuf_arg(f, begin_lst, f->size);
	return (0);
}

int			ft_flags_char(t_flag *f, t_list **begin_lst)
{
	if (f->flag[4] == 1)
		return (ft_flag_moins(f, begin_lst));
	if (f->flag[3] == 1)
		return (ft_flag_zero(f, begin_lst));
	if (f->flag[5] == 1 || f->flag[6] == 1 || f->flag[1] > (int)f->size ||
		(f->flag[1] > f->flag[0] && f->flag[13] == 1 &&
		f->flag[0] < (int)f->size))
		return (ft_flag_plus(f, begin_lst));
	if (f->flag[13] == 1 && f->flag[0] < (int)f->size &&
		f->c != '%' && f->c != 'c' && f->c != 'C' &&
		f->what != 1)
	{
		if (f->flag[0] == -1)
			f->flag[0] = 0;
		f->size = (size_t)f->flag[0];
	}
	ft_multibuf_arg(f, begin_lst, f->size);
	return (0);
}
