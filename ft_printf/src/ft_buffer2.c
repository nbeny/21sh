/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 15:26:52 by nbeny             #+#    #+#             */
/*   Updated: 2017/03/21 15:27:00 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_multibuf_ox2(t_flag *f, t_list *lst, size_t size)
{
	size_t	i[2];

	i[0] = 0;
	i[1] = 4095 - lst->i;
	ft_strncpy(&lst->buf[lst->i], f->ox, i[1]);
	lst->i += i[1];
	i[0] += i[1];
	size -= i[1];
	while (size > 0)
	{
		if (size > 4095)
			i[1] = 4095;
		else
			i[1] = size;
		if (!(lst->next = (t_list *)malloc(sizeof(t_list))))
			break ;
		lst = lst->next;
		lst->i = 0;
		ft_strncpy(&lst->buf[lst->i], &f->ox[i[0]], i[1]);
		size -= i[1];
		i[0] += i[1];
		lst->i += i[1];
	}
	lst->next = NULL;
	return (0);
}

int		ft_multibuf_arg2(t_flag *f, t_list *lst, size_t size)
{
	size_t	i[2];

	i[0] = 0;
	i[1] = 4096 - lst->i;
	ft_strncpy(&lst->buf[lst->i], f->arg, i[1]);
	lst->i += i[1];
	i[0] += i[1];
	size -= i[1];
	while (size > 0)
	{
		if (size > 4095)
			i[1] = 4095;
		else
			i[1] = size;
		if (!(lst->next = (t_list *)malloc(sizeof(t_list))))
			break ;
		lst = lst->next;
		lst->i = 0;
		ft_strncpy(&lst->buf[lst->i], &f->arg[i[0]], i[1]);
		size -= i[1];
		i[0] += i[1];
		lst->i += i[1];
	}
	lst->next = NULL;
	return (0);
}

int		ft_multibuf_nchar2(t_list *lst, int c, size_t size)
{
	size_t	i;

	i = 4095 - lst->i;
	ft_cpynchar(&lst->buf[lst->i], c, i);
	lst->i += i;
	size -= i;
	while (size > 0)
	{
		if (size > 4095)
			i = 4095;
		else
			i = size;
		if (!(lst->next = (t_list *)malloc(sizeof(t_list))))
			break ;
		lst = lst->next;
		lst->i = 0;
		ft_cpynchar(&lst->buf[lst->i], c, i);
		lst->i += i;
		size -= i;
	}
	lst->next = NULL;
	return (0);
}

int		ft_booster2(const char *format, size_t i, t_list *lst, size_t n)
{
	size_t	size;

	size = 4095 - lst->i;
	ft_strncpy(&lst->buf[lst->i], (char *)&format[i], size);
	lst->i += size;
	n -= size;
	while (n > 0)
	{
		if (n > 4095)
			size = 4095;
		else
			size = n;
		if (!(lst->next = (t_list *)malloc(sizeof(t_list))))
			break ;
		lst = lst->next;
		lst->i = 0;
		ft_strncpy(&lst->buf[lst->i], (char *)&format[i], size);
		lst->i += size;
		n -= size;
		i += size;
	}
	lst->next = NULL;
	return (i);
}
