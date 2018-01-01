/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 10:05:32 by nbeny             #+#    #+#             */
/*   Updated: 2017/05/20 10:05:33 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_lstiter(t_lib *lst, void (*f)(t_lib *elem))
{
	int		i;

	i = 0;
	if (lst != NULL)
	{
		while (lst->next != NULL)
		{
			f(lst);
			lst = lst->next;
		}
		f(lst);
	}
}
