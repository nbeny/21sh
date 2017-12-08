/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_integer_tab.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 18:05:59 by nbeny             #+#    #+#             */
/*   Updated: 2017/02/24 18:06:02 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_sort_integer_tab(int *tab, int size)
{
	int a;
	int temp;

	a = 0;
	while (a < size - 1)
	{
		if (tab[a] > tab[a + 1])
		{
			temp = tab[a + 1];
			tab[a + 1] = tab[a];
			tab[a] = temp;
			a = 0;
		}
		else
			a++;
	}
}
