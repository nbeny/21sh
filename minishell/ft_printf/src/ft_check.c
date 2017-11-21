/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 14:57:59 by nbeny             #+#    #+#             */
/*   Updated: 2017/03/15 03:28:01 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_check_flag(t_flag *f)
{
	if (f->format[f->i] == '#' || f->format[f->i] == ' ' ||
		f->format[f->i] == '0' || f->format[f->i] == '-' ||
		f->format[f->i] == '+' || f->format[f->i] == '*')
	{
		if (f->format[f->i] == '*')
			f->wc[0] = 1;
		if (f->format[f->i] == '#')
			f->flag[2] = 1;
		if (f->format[f->i] == '0')
			f->flag[3] = 1;
		if (f->format[f->i] == '-')
			f->flag[4] = 1;
		if (f->format[f->i] == '+')
			f->flag[5] = 1;
		if (f->format[f->i] == ' ')
			f->flag[6] = 1;
		f->i++;
	}
}

void	ft_check_width(t_flag *f)
{
	int		i;
	char	*str;

	i = f->i;
	if (ft_isdigit(f->format[f->i]) && f->format[i] != '0')
	{
		while (ft_isdigit(f->format[f->i]))
			f->i++;
		if (f->i - i > 0)
		{
			f->flag[1] = 0;
			str = ft_strsub(f->format, i, (f->i - i));
			f->flag[1] = ft_atoi((const char *)str);
			free(str);
		}
	}
}

void	ft_check_precision(t_flag *f)
{
	int		i;
	char	*str;

	if (f->format[f->i] == '.')
	{
		if (f->format[f->i + 1] == '*')
		{
			f->wc[1] = 1;
			f->i += 2;
			return ;
		}
		f->flag[13] = 1;
		f->flag[0] = 0;
		i = ++f->i;
		while (ft_isdigit(f->format[f->i]))
			f->i++;
		if (f->i - i > 0)
		{
			str = ft_strsub(f->format, i, f->i - i);
			f->flag[0] = ft_atoi((const char *)str);
			free(str);
		}
		if (f->flag[0] == 0)
			f->flag[0] = -1;
	}
}

void	ft_check_modifier(t_flag *f)
{
	while (f->format[f->i] == 'h' || f->format[f->i] == 'l' ||
		f->format[f->i] == 'j' || f->format[f->i] == 'z')
	{
		if (f->format[f->i] == 'h' && f->format[f->i + 1] == 'h')
		{
			f->flag[7] = 1;
			f->i++;
		}
		else if (f->format[f->i] == 'h')
			f->flag[8] = 1;
		if (f->format[f->i] == 'l' && f->format[f->i + 1] == 'l')
		{
			f->flag[9] = 1;
			f->i++;
		}
		else if (f->format[f->i] == 'l')
			f->flag[10] = 1;
		if (f->format[f->i] == 'j')
			f->flag[11] = 1;
		if (f->format[f->i] == 'z')
			f->flag[12] = 1;
		f->i++;
	}
}

int		ft_check(t_flag *f)
{
	while (f->format[f->i] == '#' || f->format[f->i] == '0' ||
		f->format[f->i] == '-' || f->format[f->i] == '+' ||
		f->format[f->i] == ' ' || f->format[f->i] == 'h' ||
		f->format[f->i] == 'l' || f->format[f->i] == 'j' ||
		f->format[f->i] == 'z' || f->format[f->i] == '.' ||
		ft_isdigit(f->format[f->i]) || f->format[f->i] == '*')
	{
		ft_check_flag(f);
		ft_check_width(f);
		ft_check_precision(f);
		ft_check_modifier(f);
	}
	if (f->format[f->i] == '\0')
		return (-1);
	return (0);
}
