/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 15:01:02 by nbeny             #+#    #+#             */
/*   Updated: 2017/03/15 04:18:55 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_norme_ws(t_flag *f, t_list **begin_lst)
{
	if (f->flag[2] == 1 || f->flag[3] == 1 ||
		f->flag[4] == 1 || f->flag[5] == 1 ||
		f->flag[6] == 1 || f->flag[1] > (int)f->size ||
		f->flag[13] == 1)
		return (ft_flags_char(f, begin_lst));
	ft_multibuf_arg(f, begin_lst, f->size);
	return (0);
}

static int	ft_handler_ws_null(t_flag *f, t_list **begin_lst)
{
	f->arg = ft_strdup("(null)");
	f->free = 1;
	f->size = ft_strlen(f->arg);
	if (f->flag[2] == 1 || f->flag[3] == 1 ||
		f->flag[4] == 1 || f->flag[5] == 1 ||
		f->flag[6] == 1 || f->flag[1] > (int)f->size ||
		f->flag[13] == 1)
		return (ft_flags_char(f, begin_lst));
	ft_multibuf_arg(f, begin_lst, f->size);
	return (0);
}

int			ft_handler_ws(t_flag *f, va_list *ap, t_list **begin_lst)
{
	int i;

	i = 0;
	f->warg = va_arg(*ap, wchar_t *);
	if (f->warg == NULL)
		return (ft_handler_ws_null(f, begin_lst));
	f->arg = ft_transform_wchar_in_char(f->warg, f);
	f->free = 1;
	f->size = ft_strlen(f->arg);
	ft_norme_ws(f, begin_lst);
	return (0);
}

int			ft_handler_s(t_flag *f, va_list *ap, t_list **begin_lst)
{
	if (f->flag[10] == 1)
		return (ft_handler_ws(f, ap, begin_lst));
	f->arg = va_arg(*ap, char *);
	if (f->arg == NULL)
	{
		f->arg = ft_strdup("(null)");
		f->free = 1;
	}
	f->size = ft_strlen(f->arg);
	if (f->flag[2] == 1 || f->flag[3] == 1 ||
		f->flag[4] == 1 || f->flag[5] == 1 ||
		f->flag[6] == 1 || f->flag[1] > (int)f->size ||
		f->flag[13] == 1)
		return (ft_flags_char(f, begin_lst));
	ft_multibuf_arg(f, begin_lst, f->size);
	return (0);
}
