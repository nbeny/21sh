/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 18:07:21 by nbeny             #+#    #+#             */
/*   Updated: 2017/02/24 18:07:23 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strnew(size_t size)
{
	char			*strnew;

	strnew = (char *)malloc(sizeof(char) * (size + 1));
	if (strnew == NULL)
		return (NULL);
	ft_bzero(strnew, (size + 1));
	return (strnew);
}
