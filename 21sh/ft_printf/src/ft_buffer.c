/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 15:22:13 by nbeny             #+#    #+#             */
/*   Updated: 2017/03/21 15:22:18 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_multibuf_ox(t_flag *f, t_list **begin_lst, size_t size)
{
	t_list	*lst;

	lst = *begin_lst;
	while (lst->next)
		lst = lst->next;
	if (size > (4095 - lst->i))
		ft_multibuf_ox2(f, lst, size);
	else
	{
		ft_strncpy(&lst->buf[lst->i], f->ox, size);
		lst->i += size;
	}
	return (0);
}

int		ft_multibuf_arg(t_flag *f, t_list **begin_lst, size_t size)
{
	t_list	*lst;

	lst = *begin_lst;
	while (lst->next)
		lst = lst->next;
	if (size > (4095 - lst->i))
		ft_multibuf_arg2(f, lst, size);
	else
	{
		ft_strncpy(&lst->buf[lst->i], f->arg, size);
		lst->i += size;
	}
	return (0);
}

int		ft_multibuf_nchar(t_list **begin_lst, int c, size_t size)
{
	t_list	*lst;

	lst = *begin_lst;
	while (lst->next)
		lst = lst->next;
	if (size > (4095 - lst->i))
		ft_multibuf_nchar2(lst, c, size);
	else
	{
		ft_cpynchar(&lst->buf[lst->i], c, size);
		lst->i += size;
	}
	return (0);
}

size_t	ft_booster(const char *format, size_t i, t_list **begin_lst)
{
	size_t	n;
	t_list	*lst;

	lst = *begin_lst;
	n = 0;
	while (format[i + n] != '\0' && format[i + n] != '%')
		n++;
	while (lst->next)
		lst = lst->next;
	if ((lst->i + n) < 4095)
	{
		ft_strncpy(&lst->buf[lst->i], (char *)&format[i], n);
		lst->i += n;
		i += n;
	}
	else
		i = ft_booster2(format, i, lst, n);
	return (i);
}

char	*ft_cpynchar(char *dest, int c, size_t n)
{
	size_t i;

	i = 0;
	if (dest)
	{
		while (i < n)
		{
			dest[i] = c;
			i++;
		}
	}
	return (dest);
}
