/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mask.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:16:04 by nbeny             #+#    #+#             */
/*   Updated: 2017/12/06 15:16:05 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

t_exec  *ft_push_mask(t_term *term, t_exec *exe, char *str)
{
	t_exec *s;

	s = exe;
	if (exe->first == 1)
		exe->mask = ft_strdup(str);
    exe->cmd = ft_cmd_building(term, exe);
	exe->next = ft_new_exe();
	exe = exe->next;
	exe->mask = ft_strdup(str);
	exe->prev = s;
    return (exe);
}

t_exec  *ft_push_mask_v1(t_term *term, t_exec *exe, char *str)
{
	t_exec *s;

	s = exe;
	if (exe->first == 1)
		exe->mask = ft_strdup(str);
    exe->cmd = ft_cmd_building(term, exe);
	exe->next = ft_new_exe();
	s = exe;
	exe = exe->next;
	exe->mask = ft_strdup(str);
	exe->prev = s;
    term->i++;
    return (exe);
}

t_exec	*ft_push_mask_v2(t_term *term, t_exec *exe, char *str)
{
	t_exec	*s;

	s = exe;
	if (exe->first == 1)
		exe->mask = ft_strdup(str);
	exe->cmd = ft_cmd_building(term, exe);
	exe->next = ft_new_exe();
	s = exe;
	exe = exe->next;
	exe->mask = ft_strdup(str);
	exe->prev = s;
	term->i += 2;
	return (exe);
}

t_exec	*ft_push_mask_v3(t_term *term, t_exec *exe, char *str)
{
	t_exec	*s;

	s = exe;
	if (exe->first == 1)
		exe->mask = ft_strdup(str);
	exe->cmd = ft_cmd_building(term, exe);
	exe->next = ft_new_exe();
	s = exe;
	exe = exe->next;
	exe->mask = ft_strdup(str);
	exe->prev = s;
	term->i += 3;
	return (exe);
}

t_exec	*ft_push_mask_v4(t_term *term, t_exec *exe, char *str)
{
	t_exec	*s;

	s = exe;
	if (exe->first == 1)
		exe->mask = ft_strdup(str);
	exe->cmd = ft_cmd_building(term, exe);
	exe->next = ft_new_exe();
	s = exe;
	exe = exe->next;
	exe->mask = ft_strdup(str);
	exe->prev = s;
	term->i += 4;
	return (exe);
}
