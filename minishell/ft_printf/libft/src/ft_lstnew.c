/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 10:06:01 by nbeny             #+#    #+#             */
/*   Updated: 2017/05/20 10:06:03 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_lib	*ft_lstnew(void const *content, size_t content_size)
{
	t_lib *lstnew;

	if ((lstnew = (t_lib*)malloc(sizeof(t_lib))) == NULL)
		return (NULL);
	if (content == NULL)
	{
		lstnew->content = NULL;
		lstnew->content_size = 0;
		lstnew->next = NULL;
		return (lstnew);
	}
	if ((lstnew->content = ft_memalloc(content_size + 1)) == NULL)
		return (NULL);
	ft_memcpy(lstnew->content, content, content_size);
	lstnew->content_size = content_size;
	lstnew->next = NULL;
	return (lstnew);
}
