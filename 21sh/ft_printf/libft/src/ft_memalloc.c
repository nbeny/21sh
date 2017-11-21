/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 00:02:29 by nbeny             #+#    #+#             */
/*   Updated: 2016/11/16 10:25:03 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memalloc(size_t size)
{
	char			*memalloc;

	memalloc = (char *)malloc(sizeof(char) * size);
	if (memalloc == NULL)
		return (NULL);
	ft_bzero(memalloc, size);
	return (memalloc);
}
