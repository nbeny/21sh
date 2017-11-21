/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 17:38:35 by nbeny             #+#    #+#             */
/*   Updated: 2016/11/16 16:01:34 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
			strmap[i] = f(i, s[i]);
			i++;
		}
		strmap[i] = '\0';
		return (strmap);
	}
	else
		return (NULL);
}
