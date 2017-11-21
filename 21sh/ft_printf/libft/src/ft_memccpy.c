/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:49:33 by nbeny             #+#    #+#             */
/*   Updated: 2016/11/18 14:57:10 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t i;

	i = 0;
	while (n--)
	{
		if (((unsigned char *)s2)[i] != (unsigned char)c)
			((unsigned char *)s1)[i] = ((unsigned char *)s2)[i];
		if (((unsigned char *)s2)[i] == (unsigned char)c)
		{
			((unsigned char *)s1)[i] = ((unsigned char *)s2)[i];
			return ((unsigned char *)s1 + i + 1);
		}
		i++;
	}
	return (NULL);
}
