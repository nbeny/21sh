#include "minishell.h"

void	ft_dquot(t_term *term, t_exec *exe)
{
	char	*tmp;

	term->quot = ft_strjoin(term->line, "\n");
	ft_strdel(&(term->line));
	term->prompt = 8;
	while (!ft_strchr(&term->quot[term->i], 34))
	{
		ft_putstr("dquote> ");
		term->hty = ft_get_command(term, term->hty);
		tmp = ft_strjoin(term->quot, term->line);
		ft_strdel(&(term->quot));
		ft_strdel(&(term->line));
		if (!ft_strchr(&tmp[term->i], 34))
			term->quot = ft_strjoin(tmp, "\n");
		else
		{
			while (tmp[term->i] != 34 && tmp[term->i] != 0)
				term->i++;
			if (tmp[term->i] == 0)
				term->quot = ft_strjoin(tmp, "\n");
			else
			{
				term->p[1] = term->i;
				term->quot = ft_strdup(tmp);
				term->line = ft_strdup(tmp);
			}
		}
		ft_strdel(&tmp);
	}
	ft_strdel(&(term->quot));
}

void	ft_quot(t_term *term, t_exec *exe)
{
	char	*tmp;

	term->quot = ft_strjoin(term->line, "\n");
	ft_strdel(&(term->line));
	term->prompt = 7;
	while (!ft_strchr(&term->quot[term->i], 39))
	{
		ft_putstr("quote> ");
		term->hty = ft_get_command(term, term->hty);
		tmp = ft_strjoin(term->quot, term->line);
		ft_strdel(&(term->quot));
		ft_strdel(&(term->line));
		if (!ft_strchr(&tmp[term->i], 39))
			term->quot = ft_strjoin(tmp, "\n");
		else
		{
			while (tmp[term->i] != 39 && tmp[term->i] != 0)
				term->i++;
			if (tmp[term->i] == 0)
				term->quot = ft_strjoin(tmp, "\n");
			else
			{
				term->p[1] = term->i;
				term->quot = ft_strdup(tmp);
				term->line = ft_strdup(tmp);
			}
		}
		ft_strdel(&tmp);
	}
	ft_strdel(&(term->quot));
}
