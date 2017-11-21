/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:10:46 by nbeny             #+#    #+#             */
/*   Updated: 2016/11/18 14:11:45 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	unsigned char *c1;
	unsigned char *c2;

	if (n == 0 && s1 == s2)
		return (s1);
	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	while (n--)
		*c1++ = *c2++;
	return (s1);
}
