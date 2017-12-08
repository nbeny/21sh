/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 10:08:00 by nbeny             #+#    #+#             */
/*   Updated: 2017/05/20 10:08:02 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	**ft_tabstr(char **s, int c)
{
	int		i;
	char	**new_str;

	i = 0;
	if (s == NULL && s[0] == NULL)
		return (NULL);
	while (s[i] != NULL && s[i][0] != c)
		i++;
	if (!(new_str = (char **)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s[i] != NULL && s[i][0] != c)
	{
		new_str[i] = ft_strdup(s[i]);
		i++;
	}
	new_str[i] = NULL;
	return (new_str);
}
