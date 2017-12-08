/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:16:48 by nbeny             #+#    #+#             */
/*   Updated: 2017/12/06 15:16:49 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void	*select_static(void)
{
	static t_term	*term = NULL;

	if (term == NULL)
		if (!(term = (t_term *)malloc(sizeof(t_term))))
			return (NULL);
	return (term);
}

void	sig_exe(int sig)
{
	if (sig == SIGINT)
	{
		ft_putchar('\n');
		signal(SIGINT, sig_exe);
	}
}

void	sig_init(int sig)
{
	t_term	*t;

	if (sig == SIGINT)
	{
		t = (t_term *)select_static();
		ft_move_end(t);
		if (t->line != NULL)
			ft_strdel(&(t->line));
		t->line = ft_strdup("\0");
		ft_putstr("\n\033[34;1m$> \033[0m");
	}
}
