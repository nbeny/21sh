/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 12:30:16 by nbeny             #+#    #+#             */
/*   Updated: 2017/03/01 15:45:47 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_precision(t_flag *f)
{
	if (f->flag[0] < (int)f->size && f->flag[0] != -1)
		f->flag[13] = 0;
	if (f->flag[0] >= (int)f->size)
		f->p = (size_t)f->flag[0] - f->size;
	if (f->flag[2] == 1 && (f->c == 'o' || f->c == 'O'))
		f->p -= f->x;
	return (0);
}
