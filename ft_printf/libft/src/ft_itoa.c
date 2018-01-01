/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 10:42:37 by nbeny             #+#    #+#             */
/*   Updated: 2017/02/07 21:27:57 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static char		*ft_reverse_itoa(char *itoa)
{
	size_t	i;
	size_t	j;
	char	tmp;

	i = 0;
	j = 0;
	if (itoa[i] == '-')
		i++;
	while (itoa[j])
		j++;
	j--;
	while (i < j)
	{
		tmp = itoa[i];
		itoa[i] = itoa[j];
		itoa[j] = tmp;
		i++;
		j--;
	}
	return (itoa);
}

static size_t	ft_ccl_malloc(int n)
{
	size_t	i;

	i = 0;
	if (n < 0)
	{
		n = n * (-1);
		i++;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	i++;
	return (i);
}

char			*ft_itoa(int n)
{
	char	*itoa;
	size_t	i;
	size_t	j;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = 0;
	j = ft_ccl_malloc(n);
	if (!(itoa = (char *)malloc(sizeof(char) * (j + 1))))
		return (NULL);
	if (n < 0)
	{
		n = n * (-1);
		itoa[i++] = '-';
	}
	while (n > 9)
	{
		itoa[i++] = n % 10 + '0';
		n = n / 10;
	}
	if (n <= 9)
		itoa[i++] = n % 10 + '0';
	itoa[i] = '\0';
	itoa = ft_reverse_itoa(itoa);
	return (itoa);
}
