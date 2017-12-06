/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 10:11:10 by nbeny             #+#    #+#             */
/*   Updated: 2017/05/20 10:11:12 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

t_env			*ft_old(t_exec *exe, t_env *oldpwd, t_env *pwd, t_env *e)
{
	char	*str;

	str = ft_strjoin(oldpwd->value, &(exe->cmd)[1][1]);
	if (chdir(str) == 0)
	{
		ft_strdel(&(oldpwd->value));
		if (pwd != NULL)
		{
			oldpwd->value = ft_strdup(pwd->value);
			ft_strdel(&(pwd->value));
			pwd->value = getcwd(NULL, 1024);
		}
		else
			e = ft_list_push_back(e, "PWD", str);
	}
	else
		ft_printf(2, "cd: no such file or directory: %s\n", exe->cmd[1]);
	ft_strdel(&str);
	return (e);
}

t_env			*ft_null(t_env *pwd, t_env *oldpwd, t_env *home, t_env *e)
{
	char	*str;

	str = NULL;
	if (home == NULL)
		return (e);
	str = getcwd(NULL, 1024);
	if (chdir(home->value) == 0)
	{
		if (oldpwd != NULL)
		{
			ft_strdel(&(oldpwd->value));
			oldpwd->value = ft_strdup(str);
		}
		else
			e = ft_list_push_back(e, "OLDPWD", str);
		if (pwd != NULL)
		{
			ft_strdel(&(pwd->value));
			pwd->value = getcwd(NULL, 1024);
		}
		else
			e = ft_list_push_back(e, "PWD", str);
	}
	ft_strdel(&str);
	return (e);
}

static t_env	*gestion_oldpwd(t_env *e, char *str, t_env *oldpwd)
{
	if (oldpwd != NULL)
	{
		ft_strdel(&(oldpwd->value));
		oldpwd->value = ft_strdup(str);
	}
	else
		e = ft_list_push_back(e, "OLDPWD", str);
	return (e);
}

t_env			*ft_slash(t_exec *exe, t_env *pwd, t_env *oldpwd, t_env *e)
{
	char	*str;
	char	*str2;

	str = getcwd(NULL, 1024);
	if (chdir(exe->cmd[1]) == 0)
	{
		e = gestion_oldpwd(e, str, oldpwd);
		if (pwd != NULL)
		{
			ft_strdel(&(pwd->value));
			pwd->value = getcwd(NULL, 1024);
		}
		else
		{
			str2 = getcwd(NULL, 1024);
			e = ft_list_push_back(e, "PWD", str2);
			ft_strdel(&str2);
		}
	}
	else
		ft_printf(2, "cd: no such file or directory: %s\n", exe->cmd[1]);
	ft_strdel(&str);
	return (e);
}

void			ft_home(t_exec *exe, t_env *pwd, t_env *oldpwd, t_env *home)
{
	char	*str;

	str = ft_strjoin(home->value, &(exe->cmd)[1][1]);
	if (chdir(str) == 0)
	{
		ft_strdel(&(oldpwd->value));
		oldpwd->value = ft_strdup(pwd->value);
		ft_strdel(&(pwd->value));
		pwd->value = getcwd(NULL, 1024);
	}
	else
		ft_printf(2, "cd: no such file or directory: %s\n", exe->cmd[1]);
	ft_strdel(&str);
}

t_env			*ft_modif_path(t_exec *exe, t_env *pwd, t_env *oldpwd, t_env *e)
{
	char	*str;
	char	*clean;
	char	*str2;
	char	*str3;

	str3 = NULL;
	str2 = getcwd(NULL, 1024);
	clean = ft_strjoin(str2, "/");
	str = ft_strjoin(clean, exe->cmd[1]);
	ft_strdel(&clean);
	if (chdir(str) == 0)
	{
		str3 = getcwd(NULL, 1024);
		e = ft_path_oldpwd(oldpwd, str2, e);
		e = ft_path_pwd(pwd, str3, e);
		ft_strdel(&str3);
	}
	else
		ft_printf(2, "cd: no such file or directory: %s\n", exe->cmd[1]);
	ft_strdel(&str);
	ft_strdel(&str2);
	return (e);
}
