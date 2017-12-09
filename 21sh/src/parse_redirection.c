/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:16:09 by nbeny             #+#    #+#             */
/*   Updated: 2017/12/06 15:16:10 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_exec	*ft_push_red_file(t_term *term, t_exec *e, char *str)
{
	t_red	*r;

	if (!check_start_red_file(term, str))
		return (e);
	if (e->red != NULL)
	{
		r = e->red;
		while (r->next != NULL)
			r = r->next;
		r->next = creat_redirection();
		r = r->next;
		r->file = ft_strsub(term->line, term->p[0], term->p[1]);
		r->mask = ft_strdup(str);
	}
	else
	{
		e->red = creat_redirection();
		r = e->red;
		r->file = ft_strsub(term->line, term->p[0], term->p[1]);
		r->mask = ft_strdup(str);
	}
	return (e);
}

t_exec	*ft_push_red_fd12(t_term *term, t_exec *e, char *str)
{
	t_red	*r;

	term->i += ft_strlen(str);
	if (e->red != NULL)
	{
		r = e->red;
		while (r->next != NULL)
			r = r->next;
		r->next = creat_redirection();
		r = r->next;
		r->mask = ft_strdup(str);
		r->fd1 = ft_atoi(str);
		r->fd2 = ft_atoi(&str[ft_strlen(str) - 1]);
	}
	else
	{
		e->red = creat_redirection();
		r = e->red;
		r->mask = ft_strdup(str);
		r->fd1 = ft_atoi(str);
		r->fd2 = ft_atoi(&str[ft_strlen(str) - 1]);
	}
	return (e);
}

t_exec	*ft_push_red_fd1(t_term *term, t_exec *e, char *str)
{
	t_red	*r;

	term->i += ft_strlen(str);
	if (e->red != NULL)
	{
		r = e->red;
		while (r->next != NULL)
			r = r->next;
		r->next = creat_redirection();
		r = r->next;
		r->mask = ft_strdup(str);
		r->fd1 = ft_atoi(str);
	}
	else
	{
		e->red = creat_redirection();
		r = e->red;
		r->mask = ft_strdup(str);
		r->fd1 = ft_atoi(str);
	}
	return (e);
}

t_exec	*ft_push_red_error(t_term *term, t_exec *e, char *str)
{
	t_red	*r;

	term->i += ft_strlen(str);
	if (e->red != NULL)
	{
		r = e->red;
		while (r->next != NULL)
			r = r->next;
		r->next = creat_redirection();
		r = r->next;
		r->mask = ft_strdup(str);
	}
	else
	{
		e->red = creat_redirection();
		r = e->red;
		r->mask = ft_strdup(str);
	}
	return (e);
}

t_exec	*ft_push_red_fd1file(t_term *term, t_exec *e, char *str)
{
	t_red	*r;

	if (!check_start_red_file(term, str))
		return (e);
	if (e->red != NULL)
	{
		r = e->red;
		while (r->next != NULL)
			r = r->next;
		r->next = creat_redirection();
		r = r->next;
		r->file = ft_strsub(term->line, term->p[0], term->p[1]);
		r->mask = ft_strdup(str);
		r->fd1 = ft_atoi(str);
	}
	else
	{
		e->red = creat_redirection();
		r = e->red;
		r->file = ft_strsub(term->line, term->p[0], term->p[1]);
		r->mask = ft_strdup(str);
		r->fd1 = ft_atoi(str);
	}
	return (e);
}
