/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 15:42:06 by nbeny             #+#    #+#             */
/*   Updated: 2016/11/12 19:17:37 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*strtrim;

	if (s == NULL)
		return (NULL);
	j = ft_strlen(s);
	while (s[j - 1] == ' ' || s[j - 1] == '\t' || s[j - 1] == '\n')
		j--;
	i = -1;
	while (s[++i] == ' ' || s[i] == '\t' || s[i] == '\n')
		j--;
	if (j <= 0)
		j = 0;
	strtrim = (char*)malloc(sizeof(char) * (j + 1));
	if (strtrim == NULL)
		return (NULL);
	s += i;
	i = -1;
	while (++i < j)
		strtrim[i] = *s++;
	strtrim[i] = '\0';
	return (strtrim);
}
