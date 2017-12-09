/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 16:18:22 by nbeny             #+#    #+#             */
/*   Updated: 2016/11/19 17:42:12 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_sort_params(int argc, char **argv)
{
	char			*stock;
	unsigned int	i;
	unsigned int	j;

	i = 1;
	j = 2;
	(void)argc;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_strcmp(argv[i], argv[j]) > 0)
			{
				stock = argv[j];
				argv[j] = argv[i];
				argv[i] = stock;
			}
			j++;
		}
		i++;
	}
}
