/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 07:56:18 by nbeny             #+#    #+#             */
/*   Updated: 2017/03/22 07:56:22 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_pourcent_gestion(t_err *e, t_list **begin_lst,
					t_flag *f, va_list *ap)
{
	e->a = ft_dispatcher(f, ap, begin_lst);
	if (f->free == 1)
		free(f->arg);
	if (e->a == -1)
		return (-1);
	e->i += f->i;
	return (0);
}

int		ft_error_copy(t_err *e, const char *format, t_list **begin_lst)
{
	e->a = (int)ft_booster(format, e->i, begin_lst) - 1;
	if (e->a < 0)
		return (-1);
	else
		e->i = (size_t)e->a;
	return (0);
}
