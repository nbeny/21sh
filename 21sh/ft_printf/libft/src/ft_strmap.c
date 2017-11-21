/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 17:28:58 by nbeny             #+#    #+#             */
/*   Updated: 2016/11/16 15:56:54 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*strmap;
	size_t	i;

	if (s)
	{
		i = 0;
		while (s[i])
			i++;
		strmap = (char *)malloc(sizeof(char) * (i + 1));
		if (strmap == NULL)
			return (NULL);
		i = 0;
		while (s[i])
		{
			strmap[i] = f(s[i]);
			i++;
		}
		strmap[i] = '\0';
		return (strmap);
	}
	else
		return (NULL);
}
