/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 18:06:43 by nbeny             #+#    #+#             */
/*   Updated: 2017/02/24 18:06:47 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*strjoin;
	unsigned int	i;
	unsigned int	j;

	if ((!s1 || !s2))
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	strjoin = (char *)malloc(sizeof(char) * (i + j + 1));
	if (strjoin == NULL)
		return (NULL);
	j = i;
	i = 0;
	while (s1[i])
	{
		strjoin[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
		strjoin[j++] = s2[i++];
	strjoin[j] = '\0';
	return (strjoin);
}
