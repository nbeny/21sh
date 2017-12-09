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

char	*ft_multi_strchr(const char *line)
{
	while (!ft_isalnum(*line) && *line != '\0')
		line++;
	if (ft_isalnum(*line))
		return ((char *)line);
	return (NULL);
}
