/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 20:54:25 by nbeny             #+#    #+#             */
/*   Updated: 2016/11/18 19:13:03 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char	*src;
	char	*dst;
	size_t	i;

	i = -1;
	src = (char *)s2;
	dst = (char *)s1;
	if (src < dst)
		while ((int)(--n) >= 0)
			*(dst + n) = *(src + n);
	else
		while (++i < n)
			*(dst + i) = *(src + i);
	return (dst);
}
