/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tri.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:16:18 by nbeny             #+#    #+#             */
/*   Updated: 2017/12/06 15:16:19 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

t_exec	*tri_and(t_term *term, t_exec *e)
{
	if (term->line[term->i] == '&' && term->line[term->i + 1] == '&' &&\
		term->line[term->i + 2] != '&' && term->line[term->i + 2] != '|' &&\
		term->line[term->i + 2] != '>' && term->line[term->i + 2] != '<' &&\
		term->line[term->i + 2] != ';')
		e = ft_push_mask_v2(term, e, "&&");
	else if (term->line[term->i] == '&' && term->line[term->i + 1] != '&' &&\
		term->line[term->i + 1] != '|' && term->line[term->i + 1] != '<' &&\
		term->line[term->i + 1] != '>' && term->line[term->i + 1] != ';')
	{
		term->i = 1;
		e->wait = 1;
	}
	else
		term->error = ft_strdup("21sh: parse error near `&`\n");
	return (e);
}

t_exec	*tri_pipe(t_term *term, t_exec *e)
{
	if (term->line[term->i] == '|' && term->line[term->i + 1] == '|' &&\
		term->line[term->i + 2] != '|' && term->line[term->i + 2] != '&' &&\
		term->line[term->i + 2] != '<' && term->line[term->i + 2] != '>' &&\
		term->line[term->i + 2] != ';')
		e = ft_push_mask_v2(term, e, "||");
	else if (term->line[term->i] == '|' && term->line[term->i + 1] != '|' &&\
		term->line[term->i + 1] != '&' && term->line[term->i + 1] != ';' &&\
		term->line[term->i + 1] != '>' && term->line[term->i + 1] != '<')
		e = ft_push_mask_v1(term, e, "|");
	else
		term->error = ft_strdup("21sh: parse error near `|`\n");
	return (e);
}

t_exec	*tri_right_redirection(t_term *term, t_exec *e)
{
	char	*s;

	if (term->line[term->i] == '>' && term->line[term->i + 1] == '&')
	{
		if (ft_isdigit(term->line[term->i + 2]))
		{
			s = get_mask('0', '>', '&', term->line[term->i + 2]);
			e = ft_push_red_fd12(term, e, s);
			ft_strdel(&s);
		}
		else if (term->line[term->i + 2] == '-')
			e = ft_push_red_error(term, e, ">&-");
		else
		{
			term->i += 2;
			term->error = ft_strdup("21sh: parse error near `>&`\n");
		}
	}
	else if (term->line[term->i] == '>' && term->line[term->i + 1] == '>')
		e = ft_push_red_file(term, e, ">>");
	else if (term->line[term->i] == '>' && term->line[term->i + 1] == '|')
		e = ft_push_red_file(term, e, ">|");
	else
		e = ft_push_red_file(term, e, ">");
	return (e);
}

t_exec	*tri_left_redirection(t_term *term, t_exec *e)
{
	char	*s;

	if (term->line[term->i] == '<' && term->line[term->i + 1] == '&')
	{
		if (ft_isdigit(term->line[term->i + 2]))
		{
			s = get_mask('0', '<', '&', term->line[term->i + 2]);
			e = ft_push_red_fd12(term, e, s);
			ft_strdel(&s);
		}
		else
			e = ft_push_red_file(term, e, "<&");
	}
	else if (term->line[term->i] == '<' && term->line[term->i + 1] == '<')
	{
		if (term->line[term->i + 2] == '<')
			e = ft_push_red_file(term, e, "<<<");
		else if (term->line[term->i + 2] == '-')
			e = ft_push_red_file(term, e, "<<-");
		else
			e = ft_push_red_file(term, e, "<<");
	}
	else
		e = ft_push_red_file(term, e, "<");
	return (e);
}
