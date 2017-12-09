/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usefull.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 18:33:41 by nbeny             #+#    #+#             */
/*   Updated: 2017/03/01 16:43:30 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_mask_wchar(int size, wchar_t wchar, char *fresh, int i)
{
	if (size > 3)
	{
		fresh[i++] = (wchar >> 18) + 0xF0;
		fresh[i++] = ((wchar >> 12) & 0x3F) + 0x80;
		fresh[i++] = ((wchar >> 6) & 0x3F) + 0x80;
		fresh[i++] = (wchar & 0x3F) + 0x80;
	}
	else if (size == 3)
	{
		fresh[i++] = (wchar >> 12) + 0xE0;
		fresh[i++] = ((wchar >> 6) & 0x3F) + 0x80;
		fresh[i++] = (wchar & 0x3F) + 0x80;
	}
	else if (size == 2)
	{
		fresh[i++] = (wchar >> 6) + 0xC0;
		fresh[i++] = (wchar & 0x3F) + 0x80;
	}
	else if (size == 1)
		fresh[i++] = wchar;
	return (i);
}

int		ft_putwchar_in_char(wchar_t wchar, char *fresh, int i, t_flag *f)
{
	int		size;

	size = ft_wcharlen(wchar);
	if ((f->pre + size) > f->flag[0] && f->flag[13] == 1 && f->flag[0] != 0)
		return (-1);
	if (MB_CUR_MAX >= 4)
		i = ft_mask_wchar(size, wchar, fresh, i);
	else
	{
		fresh[i++] = wchar;
		f->neg = -1;
	}
	f->pre += size;
	return (i);
}

void	ft_wint_to_char(wint_t wchar, t_flag *f)
{
	if (!wchar)
	{
		if (f->flag[1] > 0)
			f->flag[1]--;
		f->arg = ft_strdup("\0");
	}
	else
	{
		f->arg = ft_strnew(ft_wbytelen(&wchar));
		ft_putwchar_in_char(wchar, f->arg, 0, f);
	}
}

char	*ft_transform_wchar_in_char(wchar_t *ws, t_flag *f)
{
	char	*fresh;
	int		i;
	int		k;
	int		len;

	if (!ws)
		return (0);
	i = 0;
	k = 0;
	len = ft_wbytelen(ws);
	if (!(fresh = (char*)malloc(sizeof(char) * len)))
		return (NULL);
	fresh[len] = '\0';
	while (ws[k])
	{
		i = ft_putwchar_in_char(ws[k], fresh, i, f);
		if (f->flag[0] != 0 && f->flag[13] == 1)
		{
			if (i == -1)
				break ;
		}
		k++;
	}
	return (fresh);
}
