/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatcher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 14:58:13 by nbeny             #+#    #+#             */
/*   Updated: 2017/03/14 23:26:38 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void		ft_init_specs2(t_spec *specs)
{
	specs[10].c = 'x';
	specs[10].ptr = &ft_handler_x;
	specs[11].c = 'X';
	specs[11].ptr = &ft_handler_wx;
	specs[12].c = 'c';
	specs[12].ptr = &ft_handler_c;
	specs[13].c = 'C';
	specs[13].ptr = &ft_handler_wc;
	specs[14].c = '%';
	specs[14].ptr = &ft_handler;
	specs[15].c = 'b';
	specs[15].ptr = &ft_handler_b;
	specs[16].c = 't';
	specs[16].ptr = &ft_handler_t;
	specs[17].c = 'q';
	specs[17].ptr = &ft_handler_q;
	specs[18].c = 'n';
	specs[18].ptr = &ft_handler_n;
	specs[19].c = 'v';
	specs[19].ptr = &ft_handler_v;
	specs[20].c = 0;
	specs[20].ptr = NULL;
}

void		ft_init_specs1(t_spec *specs)
{
	specs[0].c = 's';
	specs[0].ptr = &ft_handler_s;
	specs[1].c = 'S';
	specs[1].ptr = &ft_handler_ws;
	specs[2].c = 'p';
	specs[2].ptr = &ft_handler_p;
	specs[3].c = 'd';
	specs[3].ptr = &ft_handler_d;
	specs[4].c = 'D';
	specs[4].ptr = &ft_handler_wd;
	specs[5].c = 'i';
	specs[5].ptr = &ft_handler_d;
	specs[6].c = 'o';
	specs[6].ptr = &ft_handler_o;
	specs[7].c = 'O';
	specs[7].ptr = &ft_handler_wo;
	specs[8].c = 'u';
	specs[8].ptr = &ft_handler_u;
	specs[9].c = 'U';
	specs[9].ptr = &ft_handler_wu;
	ft_init_specs2(specs);
}

static int	ft_wildcard(t_flag *f, va_list *ap)
{
	if (f->wc[0] == 1)
	{
		f->flag[1] = (int)va_arg(*ap, int);
		if (f->flag[1] < 0)
			f->flag[1] = 0;
	}
	if (f->wc[1] == 1)
	{
		f->flag[0] = (int)va_arg(*ap, int);
		f->flag[13] = 1;
		if (f->flag[0] <= 0)
			f->flag[0] = -1;
	}
	return (0);
}

int			ft_dispatcher(t_flag *f, va_list *ap, t_list **begin_lst)
{
	t_spec	specs[21];
	int		j;

	f->arg = NULL;
	f->warg = NULL;
	if (ft_check(f) == -1)
		return (-1);
	ft_init_specs1(specs);
	f->c = f->format[f->i];
	j = 0;
	while (specs[j].c != f->c && specs[j].c != 0)
		j++;
	ft_wildcard(f, ap);
	if (specs[j].c == 0)
		return (ft_handler_undefined(f, begin_lst));
	if (j == 14)
		return (specs[14].ptr(f, begin_lst));
	return (specs[j].ptr(f, ap, begin_lst));
}
