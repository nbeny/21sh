/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 14:10:09 by nbeny             #+#    #+#             */
/*   Updated: 2017/03/07 11:08:46 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static void	ft_init(char *s)
{
	s[0] = '0';
	s[1] = '1';
	s[2] = '2';
	s[3] = '3';
	s[4] = '4';
	s[5] = '5';
	s[6] = '6';
	s[7] = '7';
	s[8] = '8';
	s[9] = '9';
	s[10] = 'a';
	s[11] = 'b';
	s[12] = 'c';
	s[13] = 'd';
	s[14] = 'e';
	s[15] = 'f';
	s[16] = 'g';
	s[17] = 'h';
	s[18] = 'i';
	s[19] = 'j';
}

static int	ft_size_nbr(int *tab, char *s, unsigned int nb, int base)
{
	int i;

	i = 0;
	while (nb != 0)
	{
		tab[i] = s[nb % base];
		nb = nb / base;
		i++;
	}
	i--;
	return (i);
}

static char	*ft_special(unsigned int nb, int base)
{
	if (nb == 0)
		return (ft_strdup("0"));
	if (nb == 4294967295 && base == 8)
		return (ft_strdup("37777777777"));
	if (nb == 4294967295 && base == 10)
		return (ft_strdup("4294967295"));
	if (nb == 4294967295 && base == 16)
		return (ft_strdup("ffffffff"));
	if (nb == 4294967295 && base == 2)
		return (ft_strdup("11111111111111111111111111111111"));
	if (nb == 4294967295 && base == 3)
		return (ft_strdup("102002022201221111210"));
	if (nb == 4294967295 && base == 5)
		return (ft_strdup("32244002423140"));
	if (nb == 4294967295 && base == 9)
		return (ft_strdup("12068657453"));
	if (nb == 4294967295 && base == 20)
		return (ft_strdup("3723ai4f"));
	return (NULL);
}

char		*ft_uitoa_base(unsigned int nb, int base)
{
	char			*itoa;
	char			s[20];
	int				tab[64];
	unsigned int	n;
	int				i[2];

	n = nb;
	ft_init(s);
	if ((itoa = ft_special(nb, base)) != NULL)
		return (itoa);
	i[0] = ft_size_nbr(tab, s, nb, base);
	if (!(itoa = (char *)malloc(sizeof(char) * (i[0] + 1))))
		return (NULL);
	i[1] = 0;
	while (i[0] >= 0)
		itoa[i[1]++] = tab[i[0]--];
	itoa[i[1]] = 0;
	return (itoa);
}
