/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 10:11:37 by nbeny             #+#    #+#             */
/*   Updated: 2017/05/20 10:11:39 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

t_exec	*ft_init_exe(t_exec *exe)
{
	exe->cmd = NULL;
	exe->c = NULL;
	exe->mask = NULL;
	exe->wait = 0;
	exe->error = NULL;
	exe->quot = NULL;
	exe->red = NULL;
	exe->fd.fd0 = -1;
	exe->fd.fd1 = -1;
	exe->fd.fd2 = -1;
	exe->i[0] = 0;
	exe->i[1] = 0;
	exe->i[2] = 0;
	exe->i[3] = 0;
	return (exe);
}

t_env	*ft_shlvl(t_env *e)
{
	t_env	*shlvl;
	int		lvl;

	lvl = 0;
	shlvl = ft_moove_env(e, "SHLVL\0", 6);
	if (shlvl != NULL)
	{
		lvl = ft_atoi(shlvl->value) + 1;
		ft_strdel(&(shlvl->value));
		shlvl->value = ft_itoa(lvl);
	}
	return (e);
}

void	ft_print_env(t_env *e, int nb, int i, int free)
{
	t_env	*s;
	t_env	*f;

	s = e;
	f = e;
	if (e != NULL)
	{
		while (free == 1 && s && s->name != NULL)
		{
			ft_printf(0, "%s=%s\n", s->name, s->value);
			s = s->next;
		}
		if (i == 1 && f != NULL)
			ft_free_env(f);
		else if (i == 0 && nb != 0)
			f = ft_env_opt_i(f, nb);
	}
}

int		main(int ac, char **av, char **env)
{
	t_env	*e;
	t_exec	*exec;
	t_term	term;
	t_hty	*hty;

	(void)av;
	hty = NULL;
	if (ac == 1)
	{
		e = ft_tab_to_list(env);
		e = ft_shlvl(e);
		if (!ft_init_term(&term))
			return (-1);
		while (42)
		{
			term.error = NULL;
			signal(SIGINT, sig_init);
			ft_printf(0, "\033[34;1m$> \033[0m");
			term.prompt = 4;
			hty = ft_get_command(&term, hty);
			if (ft_multi_strchr(term.line))
				hty = ft_mem_cmd(&term, hty);
			term.hty = hty;
			exec = ft_cmd_parcing(&term);
			if (term.error == NULL)
				e = ft_parse_mask(&term, exec, e);
			else
				ft_strdel(&(term.error));
			ft_free_exe(exec);
			ft_strdel(&(term.line));
		}
	}
	return (0);
}
