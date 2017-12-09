/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 15:01:25 by nbeny             #+#    #+#             */
/*   Updated: 2017/05/20 10:09:39 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static t_flag	ft_init_f(t_flag f)
{
	int i;

	i = -1;
	f.i = 0;
	f.c = 0;
	f.arg = NULL;
	f.warg = NULL;
	f.sign = 0;
	while (++i < 14)
		f.flag[i] = 0;
	f.size = 0;
	f.x = 0;
	f.p = 0;
	f.free = 0;
	f.wc[0] = 0;
	f.wc[1] = 0;
	f.what = 0;
	f.pre = 0;
	return (f);
}

void			ft_free(t_list *begin_lst)
{
	t_list *lst_nxt;

	while (begin_lst)
	{
		lst_nxt = begin_lst->next;
		free(begin_lst);
		begin_lst = NULL;
		begin_lst = lst_nxt;
	}
}

int				ft_print_and_free(int fd, t_err *e, t_list *begin_lst,\
									t_flag *f)
{
	size_t	ret;
	t_list	*tmp;

	ret = 0;
	tmp = begin_lst;
	if (e->a > -1)
	{
		while (begin_lst)
		{
			ret += begin_lst->i;
			ft_putnstr_fd(fd, begin_lst->buf, begin_lst->i);
			begin_lst = begin_lst->next;
		}
	}
	else
	{
		begin_lst = tmp;
		ft_free(begin_lst);
		return (-1);
	}
	begin_lst = tmp;
	ft_free(begin_lst);
	if (f->neg == -1)
		return (-1);
	return ((int)ret);
}

int				ft_fill_stdout(int fd, const char *format, va_list *ap)
{
	t_err		e;
	t_flag		f;
	t_list		*begin_lst;

	e.i = -1;
	f.neg = 0;
	if (!(begin_lst = (t_list *)malloc(sizeof(t_list))))
		return (-1);
	begin_lst->next = NULL;
	begin_lst->i = 0;
	while (format[++e.i] != '\0')
	{
		if (format[e.i] == '%')
		{
			if (format[e.i + 1] == '\0')
				break ;
			f = ft_init_f(f);
			f.format = (char *)&format[++e.i];
			if (ft_pourcent_gestion(&e, &begin_lst, &f, ap) == -1)
				break ;
		}
		else if (ft_error_copy(&e, format, &begin_lst) == -1)
			break ;
	}
	return (ft_print_and_free(fd, &e, begin_lst, &f));
}

int				ft_printf(int fd, const char *format, ...)
{
	va_list	ap;
	int		ret;

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	ret = ft_fill_stdout(fd, format, &ap);
	va_end(ap);
	return (ret);
}
