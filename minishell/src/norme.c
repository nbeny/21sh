/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 14:45:56 by nbeny             #+#    #+#             */
/*   Updated: 2017/05/26 14:45:58 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void	ft_error_cd(t_env *pwd, t_env *oldpwd, t_env *home, t_exec *exe)
{
	if (pwd == NULL || oldpwd == NULL || home == NULL)
		ft_printf(2, "cd: set your environ [PWD/OLDPWD/HOME]\n");
	else
		ft_printf(2, "cd: no such file or directory: %s\n", exe->cmd[1]);
}

char	*ft_string_return(t_env *e, char **cmd)
{
	char	*s;
	char	*str;

	str = NULL;
	s = NULL;
	if (cmd != NULL)
	{
		if (cmd[0][0] != '/')
		{
			str = ft_getenv(e, "PWD\0", 4);//getcwd(NULL, 1024);
			s = ft_strjoin(str, &cmd[0][1]);
			ft_strdel(&str);
		}
		else
			s = ft_strdup(cmd[0]);
	}
	return (s);
}

void	ft_error_and_make_exe(t_exec *exe, t_env *e)
{
	char	*str;

	str = NULL;
	if (!ft_strncmp(exe->cmd[0], "./", 2) ||\
			!ft_strncmp(exe->cmd[0], "/", 1))
		ft_execute(exe->cmd, e);
	else if ((str = ft_path_istrue(exe->cmd, e)))
		ft_execute_path(str, exe->cmd, e);
	else
		ft_printf(2, "command not found: %s\n", exe->cmd[0]);
}

t_exec	*ft_first_struct_exe(char **split)
{
	t_exec *exe;

	exe = NULL;
	if (split[0] != NULL)
	{
		if (!(exe = (t_exec *)malloc(sizeof(t_exec))))
			return (NULL);
		exe->cmd = ft_split(split[0]);
		exe->next = NULL;
	}
	return (exe);
}

t_exec	*ft_all_struct_exe(t_exec *exe, char **split)
{
	t_exec	*s;
	int		i;

	s = exe;
	i = 1;
	if (exe == NULL)
		return (NULL);
	while (split[i] != NULL)
	{
		if (!(s->next = (t_exec *)malloc(sizeof(t_exec))))
			return (NULL);
		s = s->next;
		s->cmd = ft_split(split[i]);
		i++;
	}
	s->next = NULL;
	return (exe);
}
