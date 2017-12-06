/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 23:12:19 by nbeny             #+#    #+#             */
/*   Updated: 2017/12/06 23:12:24 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

t_env	*gestion_oldpwd(t_env *e, char *str, t_env *oldpwd)
{
	if (oldpwd != NULL)
	{
		ft_strdel(&(oldpwd->value));
		oldpwd->value = getcwd(NULL, 1024);
	}
	else
		e = ft_list_push_back(e, "PWD", str);
	return (e);
}
