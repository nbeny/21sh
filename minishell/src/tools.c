/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 10:11:44 by nbeny             #+#    #+#             */
/*   Updated: 2017/05/20 10:11:45 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int		ft_listsize(t_env *e)
{
	t_env	*s;
	int		i;

	i = 0;
	s = e;
	if (e != NULL)
	{
		while (s != NULL)
		{
			i++;
			s = s->next;
		}
	}
	return (i);
}

int		ft_equal(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0' && s[i] != '=')
			i++;
		if (s[i] == '=')
			return (i + 1);
	}
	return (0);
}

char    *ft_getenv(t_env *e, char *str, int i)
{
    t_env   *s;

    s = e;
    if (e != NULL)
    {
        while (s != NULL)
        {
            if (!ft_strncmp(s->name, str, i))
                return (s->value);
            s = s->next;
        }
    }
    return (NULL);
}

char	**ft_list_to_tab(t_env *e)
{
	char	**tstr;
	char	*stock;
	t_env	*s;
	int		i;

	s = e;
	if (e == NULL)
		return (NULL);
	i = ft_listsize(e);
	if (!(tstr = (char **)malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	i = 0;
	while (s != NULL)
	{
		stock = ft_strjoin(s->name, "=");
		tstr[i] = ft_strjoin(stock, s->value);
		ft_strdel(&stock);
		i++;
		s = s->next;
	}
	tstr[i] = NULL;
	return (tstr);
}

t_env	*ft_tab_to_list(char **env)
{
	t_env	*e;
	t_env	*s;
	int		i;

	i = 1;
	if (env == NULL || env[0] == NULL)
		return (NULL);
	if (!(e = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	e->name = ft_strsub(env[0], 0, (ft_equal(env[0]) - 1));
	e->value = ft_strdup(&env[0][ft_equal(env[0])]);
	s = e;
	while (env[i] != NULL)
	{
		if (!(s->next = (t_env *)malloc(sizeof(t_env))))
			return (NULL);
		s = s->next;
		s->name = ft_strsub(env[i], 0, (ft_equal(env[i]) - 1));
		s->value = ft_strdup(&env[i][ft_equal(env[i])]);
		i++;
	}
	s->next = NULL;
	return (e);
}
