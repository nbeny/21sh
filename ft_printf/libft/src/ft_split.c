/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 14:08:41 by nbeny             #+#    #+#             */
/*   Updated: 2017/05/26 14:08:48 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static size_t			ft_cnt_word(char const *s)
{
	int w;
	int i;

	i = 0;
	w = 0;
	while (*s != '\0')
	{
		if (i == 1 && (*s == ' ' || *s == '\t'))
			i = 0;
		if (i == 0 && *s != ' ' && *s != '\t')
		{
			i = 1;
			w++;
		}
		s++;
	}
	return (w);
}

static size_t			ft_size_word(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != ' ' && s[i] != '\t')
		i++;
	return (i);
}

static char const		*ft_ptr_move(char const *s)
{
	while (*s == ' ' || *s == '\t')
		s++;
	return (s);
}

char					**ft_split(char const *s)
{
	char	**split;
	size_t	cnt_w;
	size_t	i;
	size_t	l;

	if (!s)
		return (NULL);
	i = 0;
	cnt_w = ft_cnt_word(s);
	if (!(split = (char **)malloc(sizeof(*split) * (cnt_w + 1))))
		return (NULL);
	while (cnt_w-- > 0)
	{
		s = ft_ptr_move(s);
		split[i] = (char *)malloc(sizeof(char) * (ft_size_word(s) + 1));
		if (split == NULL)
			return (NULL);
		l = 0;
		while (*s != '\0' && *s != ' ' && *s != '\t')
			split[i][l++] = *s++;
		split[i++][l] = '\0';
		s = ft_ptr_move(s);
	}
	split[i] = NULL;
	return (split);
}
