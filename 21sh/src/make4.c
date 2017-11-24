#include "21sh.h"

t_red	*make_leftaddr(t_exec *exe, t_red *r, t_env *e)
{
	return (r);
}

t_red	*make_trileft_redirection(t_exec *exe, t_red *r, t_env *e)
{
	return (r);
}

t_red	*make_doubleleftless(t_exec *exe, t_red *r, t_env *e)
{
	return (r);
}

t_red	*make_doubleleft(t_exec *exe, t_red *r, t_env *e)
{
	return (r);
}

t_red	*make_leftpipe(t_exec *exe, t_red *r, t_env *e)
{
	char	*tmp;
	char	*path;

	tmp = getcwd(NULL, 1024);
	path = ft_add_path(tmp, r->file);
	if (access(tmp, R_OK))
		exe->error = ft_strdup("21sh: no such file or directory\n");
	ft_strdel(&tmp);
	ft_strdel(&path);
	return (r);
}
