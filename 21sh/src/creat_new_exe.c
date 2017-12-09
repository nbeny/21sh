/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_new_exe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:13:42 by nbeny             #+#    #+#             */
/*   Updated: 2017/12/06 15:13:43 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_exec	*ft_right_redirection(t_term *term, t_exec *exe)
{
	if (term->line[term->i + 1] == '>')
		exe = ft_push_mask_v2(term, exe, ">>");
	else if (term->line[term->i + 1] == '&')
		exe = ft_push_mask_v2(term, exe, ">&");
	else
	{
		exe->mask = ft_strdup(">");
		exe->cmd = ft_cmd_building(term, exe);
		if (exe->cmd == NULL)
			ft_strdel(&(exe->mask));
		else
		{
			exe->next = ft_new_exe();
			exe = exe->next;
		}
		term->i++;
	}
	return (exe);
}

t_exec	*ft_left_redirection(t_term *term, t_exec *exe)
{
	if (term->line[term->i + 1] == '<')
		exe = ft_push_mask_v2(term, exe, "<<");
	else if (term->line[term->i + 1] == '&')
		exe = ft_push_mask_v2(term, exe, "<&");
	else
	{
		exe->mask = ft_strdup("<");
		exe->cmd = ft_cmd_building(term, exe);
		if (exe->cmd == NULL)
			ft_strdel(&(exe->mask));
		else
		{
			exe->next = ft_new_exe();
			exe = exe->next;
		}
		term->i++;
	}
	return (exe);
}
