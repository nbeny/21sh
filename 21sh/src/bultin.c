/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bultin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 10:11:03 by nbeny             #+#    #+#             */
/*   Updated: 2017/12/06 15:13:35 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_env	*ft_cd(t_exec *exe, t_env *e)
{
	t_env	*home;
	t_env	*pwd;
	t_env	*oldpwd;

	pwd = ft_moove_env(e, "PWD\0", 4);
	oldpwd = ft_moove_env(e, "OLDPWD\0", 7);
	home = ft_moove_env(e, "HOME\0", 5);
	if (exe->cmd[1] != NULL && exe->cmd[2] != NULL)
		ft_printf(2, "cd: too many arguments\n");
	else if (exe->cmd[1] == NULL && home)
		e = ft_null(pwd, oldpwd, home, e);
	else if (exe->cmd[1] && exe->cmd[1][0] == '-' && oldpwd)
		e = ft_old(exe, oldpwd, pwd, e);
	else if (exe->cmd[1] && exe->cmd[1][0] == '/')
		e = ft_slash(exe, pwd, oldpwd, e);
	else if (exe->cmd[1] && exe->cmd[1][0] == '~' && pwd && oldpwd && home)
		ft_home(exe, pwd, oldpwd, home);
	else if (exe->cmd[1])
		e = ft_modif_path(exe, pwd, oldpwd, e);
	else
		ft_error_cd(pwd, oldpwd, home, exe);
	return (e);
}

t_env	*ft_setenv(t_exec *exe, t_env *e)
{
	t_env	*s;
	char	*str;

	str = NULL;
	s = e;
	exe->i[0] = 0;
	if (exe->cmd[0] == NULL || exe->cmd[1] == NULL)
		return (e);
	while (exe->cmd[++(exe->i[0])] != NULL)
	{
		if ((exe->i[1] = ft_equal(exe->cmd[exe->i[0]])))
			e = ft_multi_setenv(exe, str, e, s);
		else
		{
			s = ft_moove_env(e, exe->cmd[exe->i[0]],\
								(ft_strlen(exe->cmd[exe->i[0]]) + 1));
			if (s == NULL)
				e = ft_list_push_back(e, exe->cmd[exe->i[0]], NULL);
			else
				del_and_creat(s);
		}
	}
	return (e);
}

t_env	*ft_unsetenv(t_exec *exe, t_env *e)
{
	t_env	*s;
	t_env	*b;

	s = e;
	b = NULL;
	if (e != NULL && exe != NULL && exe->cmd[0] != NULL)
	{
		exe->i[0] = 1;
		while (exe->cmd[exe->i[0]])
		{
			s = ft_moove_env(e, exe->cmd[exe->i[0]],\
								(ft_strlen(exe->cmd[exe->i[0]]) + 1));
			if (s != NULL)
			{
				b = e;
				while (b->next != NULL && ft_strncmp(b->next->name,\
					exe->cmd[exe->i[0]], (ft_strlen(exe->cmd[exe->i[0]]) + 1)))
					b = b->next;
				e = ft_free_oneenv(e, s, b);
			}
			exe->i[0]++;
		}
	}
	return (e);
}

void	ft_env(t_exec *exe, t_env *e)
{
	t_env	*s;

	exe = ft_init_exe(exe);
	s = e;
	exe->i[0] = 1;
	while (e != NULL && exe != NULL && exe->cmd != NULL && exe->cmd[exe->i[0]])
	{
		if ((exe->i[1] = ft_equal(exe->cmd[exe->i[0]])))
			s = ft_add_env(exe, s, exe->i[0], exe->i[1]);
		else if (!ft_strncmp(exe->cmd[exe->i[0]], "-i", 2))
		{
			s = ft_env_opt_i(s, exe->i[2]);
			exe->i[2] = 0;
			exe->i[3] = 1;
		}
		else if (ft_strncmp(exe->cmd[exe->i[0]], "env", 3))
			return (ft_env_success(exe, s));
		exe->i[0] += 1;
	}
	ft_print_env(s, exe->i[2], exe->i[3], 1);
}

void	ft_echo(t_exec *exe, t_env *e)
{
	t_env	*s;
	int		i;

	i = 1;
	if (exe != NULL && exe->cmd != NULL)
	{
		while (exe->cmd[i])
		{
			if (exe->cmd[i] && exe->cmd[i][0] == '$' && exe->cmd[i][1] != '\0')
			{
				s = ft_moove_env(e, &(exe->cmd)[i][1],\
										ft_strlen(exe->cmd[i]));
				if (s != NULL)
					ft_putecho(s->value, exe->cmd, i);
				else
					ft_putecho(exe->cmd[i], exe->cmd, i);
			}
			else
				ft_putecho(exe->cmd[i], exe->cmd, i);
			i++;
		}
	}
	ft_putchar('\n');
}
