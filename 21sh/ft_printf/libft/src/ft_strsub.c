/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:34:56 by nbeny             #+#    #+#             */
/*   Updated: 2017/02/17 07:28:11 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strsub(char const *s, int start, int len)
{
	char	*strsub;
	int		i;

	if (s)
	{
		i = 0;
		if (start > (int)ft_strlen(s))
			return (NULL);
		if (!(strsub = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		while (start < len && s[start])
		{
			strsub[i] = s[start];
			start++;
			i++;
		}
		strsub[i] = '\0';
		return (strsub);
	}
	else
		return (NULL);
}
