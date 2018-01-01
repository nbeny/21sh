/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:14:50 by nbeny             #+#    #+#             */
/*   Updated: 2017/12/06 15:14:51 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*ft_multi_strchr(t_term *term)
{
	char	*line;

	line = term->line;
	if (line == NULL)
		return (NULL);
	while (!ft_isalnum(*line) && *line != '\0')
	{
		ft_putchar('a');
		line++;
	}
	if (ft_isalnum(*line))
		return ((char *)line);
	return (NULL);
}
