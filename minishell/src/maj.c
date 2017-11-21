#include "21sh.h"

t_env	*ft_multi_setenv(t_exec *exe, char *str, t_env *e, t_env *s)
{
	str = ft_strsub(exe->cmd[exe->i[0]], 0, (exe->i[1] - 1));
	s = ft_moove_env(e, str, (ft_strlen(str) + 1));
	if (s == NULL)
		e = ft_list_push_back(e, str, &(exe->cmd)[exe->i[0]][exe->i[1]]);
	else
	{
		ft_strdel(&(s->value));
		s->value = ft_strdup(&(exe->cmd)[exe->i[0]][exe->i[1]]);
	}
	ft_strdel(&str);
	return (e);
}

void	ft_env_success(t_exec *exe, t_env *s)
{
	char	*str;

	str = NULL;
	if (!ft_strncmp(exe->cmd[exe->i[0]], "./", 2) ||\
		!ft_strncmp(exe->cmd[exe->i[0]], "/", 1))
		ft_execute(&(exe->cmd)[exe->i[0]], s);
	else if ((str = ft_path_istrue(&(exe->cmd)[exe->i[0]], s)))
		ft_execute_path(str, &(exe->cmd)[exe->i[0]], s);
	ft_print_env(s, exe->i[2], exe->i[3], 0);
}

void	ft_putecho(char *s, char **tstr, int i)
{
	ft_putstr(s);
	if (tstr[i + 1] != NULL)
		ft_putchar(' ');
}

t_env	*ft_path_oldpwd(t_env *oldpwd, char *str2, t_env *e)
{
	if (oldpwd != NULL)
	{
		ft_strdel(&(oldpwd->value));
		oldpwd->value = ft_strdup(str2);
	}
	else
		e = ft_list_push_back(e, "OLDPWD", str2);
	return (e);
}

t_env	*ft_path_pwd(t_env *pwd, char *str3, t_env *e)
{
	if (pwd != NULL)
	{
		ft_strdel(&(pwd->value));
		pwd->value = ft_strdup(str3);
	}
	else
		e = ft_list_push_back(e, "PWD", str3);
	return (e);
}
