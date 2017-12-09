/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_execute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:15:54 by nbeny             #+#    #+#             */
/*   Updated: 2017/12/06 15:15:55 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int		ft_isbultin(t_exec *exe, t_env *e)
{
	if (!ft_strncmp(exe->cmd[0], "exit\0", 5) ||\
		!ft_strncmp(exe->cmd[0], "env\0", 4) ||\
		!ft_strncmp(exe->cmd[0], "setenv\0", 7) ||\
		!ft_strncmp(exe->cmd[0], "unsetenv\0", 9) ||\
		!ft_strncmp(exe->cmd[0], "cd\0", 3) ||\
		!ft_strncmp(exe->cmd[0], "echo\0", 5))
		return (1);
	return (0);
}

t_env	*make_bultin(t_exec *exe, t_env *e)
{
	if (!ft_strncmp(exe->cmd[0], "exit\0", 5))
		ft_exit(exe, e);
	else if (!ft_strncmp(exe->cmd[0], "env\0", 4))
		ft_env(exe, e);
	else if (!ft_strncmp(exe->cmd[0], "setenv\0", 7))
		e = ft_setenv(exe, e);
	else if (!ft_strncmp(exe->cmd[0], "unsetenv\0", 9))
		e = ft_unsetenv(exe, e);
	else if (!ft_strncmp(exe->cmd[0], "cd\0", 3))
		e = ft_cd(exe, e);
	else if (!ft_strncmp(exe->cmd[0], "echo\0", 5))
		ft_echo(exe, e);
	else
		ft_printf(2, "bultin: no match found with '%s'\n", exe->cmd[0]);
	return (e);
}

void	turn_mask_exec(t_group *g, t_term *term)
{
	if (g->s->mask == NULL)
		g->e = make_semicolon(term, g->s, g->e);
	else if (g->s->mask[0] == '|' ||\
		(g->s->next && g->s->next->mask[0] == '|'))
	{
		g->s->mask[0] = '|';
		if (g->s->mask[1] == '|')
		{
			g->e = boucle_numeric_or(term, g->s, g->e);
			g->s = term_flash_bcl(term, g->s);
		}
		else
		{
			g->e = make_pipe(term, g->s, g->e);
			g->s = term_flash_bcl(term, g->s);
		}
	}
	else if (g->s->mask[0] == '&' && g->s->mask[1] == '&')
	{
		g->e = boucle_numeric_and(term, g->s, g->e);
		g->s = term_flash_bcl(term, g->s);
	}
	else
		g->e = make_semicolon(term, g->s, g->e);
}

t_env	*ft_parse_mask(t_term *term, t_exec *exe, t_env *e)
{
	t_group	g;
	t_exec	*s;

	s = exe;
	if (exe == NULL)
		return (e);
	term->flash = 0;
	while (s != NULL && s->cmd[0] != NULL && s->error == NULL)
	{
		g.s = s;
		g.e = e;
		turn_mask_exec(&g, term);
		s = g.s;
		e = g.e;
		s = parse_mask_error(s);
	}
	return (e);
}
