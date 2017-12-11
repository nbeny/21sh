/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_main_shell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 15:31:53 by nbeny             #+#    #+#             */
/*   Updated: 2017/12/09 15:31:56 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	check_sin()
{
	struct termios	def;
	char			*term;
	char			buf[1024];

	term = getenv("TERM");
	if (!isatty(0) || term == NULL ||\
		tcgetattr(0, &def) == -1 ||\
		tgetent(buf, term) != 1)
	{
		ft_printf(2, "This shell needs a stdin terminal connected.\n");
		exit(EXIT_SUCCESS);
	}
}

t_env	*init_env_shell(char **env)
{
	t_env		*e;

	e = ft_tab_to_list(env);
	e = ft_shlvl(e);
	return (e);
}
