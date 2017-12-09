/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 10:05:45 by nbeny             #+#    #+#             */
/*   Updated: 2017/05/20 10:05:46 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_lib	*ft_lstmap(t_lib *lst, t_lib *(*f)(t_lib *elem))
{
	t_lib *lstnew;
	t_lib *dlstnew;

	if (lst == NULL)
		return (NULL);
	lstnew = f(lst);
	dlstnew = lstnew;
	while (lst->next)
	{
		lstnew->next = f(lst->next);
		if (lstnew->next == NULL)
		{
			free(dlstnew);
			return (NULL);
		}
		lst = lst->next;
		lstnew = lstnew->next;
	}
	return (dlstnew);
}
