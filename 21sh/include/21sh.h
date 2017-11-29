/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 10:09:56 by nbeny             #+#    #+#             */
/*   Updated: 2017/05/20 10:10:52 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../ft_printf/include/ft_printf.h"
# include <unistd.h>
# include <termios.h>
# include <term.h>
# include <curses.h>
# include <sys/ioctl.h>
# include <fcntl.h>
# include <signal.h>

typedef struct	s_term
{
	char			*name;
	struct termios	term_clean;
	struct termios	term;
	char			*quot;
	int				prompt;
	struct s_hty	*hty;
	int				h;
	int				hmax;
	char			*line;
	int				last;
	int				i;
	int				p[2];
	int				pos;
	int				mlen;
	int				x;
	int				y;
	int				fd;
	char			*cmstr;
	int				ws_y;
	int				ws_x;
	char			*clear;
	char			*cursor;
	char			*shadow;
	char			*mask;
	char			*error;
}				t_term;
typedef struct	s_quot
{
	char			*arg;
	struct s_quot	*next;
}				t_quot;
typedef struct	s_red
{
	char			*mask;
	char			*file;
	int				fd1;
	int				fd2;
	int				fd_open;
	struct s_red	*next;
}				t_red;
typedef struct	s_hty
{
	char			*cmd;
	struct s_hty	*next;
	struct s_hty	*prev;
}				t_hty;
typedef struct	s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}				t_env;
typedef struct	s_fd
{
	int				fd0;
	int				fd1;
	int				fd2;
	int				ffd0;
	int				ffd1;
	int				ffd2;
}				t_fd;
typedef struct	s_cmd
{
	char			*str;
	struct s_cmd	*next;
}				t_cmd;
typedef struct	s_exec
{
	char			**cmd;
	struct s_cmd	*c;
	char			*mask;
	int				wait;
	char			*error;
	struct s_quot	*quot;
	struct s_red	*red;
	struct s_fd		fd;
	int				i[4];
	int				jp_nxt;
	struct s_exec	*next;
	struct s_exec	*prev;
}				t_exec;
/*
**typedef static struct	s_sign
**{
**	struct t_term	*term;
**}						t_sign;
*/
/*
**main
*/
t_exec			*ft_init_exe(t_exec *exe);
t_env			*ft_shlvl(t_env *e);
void			ft_print_env(t_env *e, int nb, int i, int free);
int				main(int ac, char **av, char **env);
/*
**tools
*/
int				ft_listsize(t_env *e);
int				ft_equal(char *s);
char			*ft_getenv(t_env *e, char *str, int i);
char			**ft_list_to_tab(t_env *e);
t_env			*ft_tab_to_list(char **env);
/*
**free
*/
void			ft_free_exe(t_exec *exe);
void			ft_free_c(t_cmd *c);
void			ft_free_env(t_env *e);
t_env			*ft_free_oneenv(t_env *e, t_env *s, t_env *b);
void			ft_free_tabstr(char **tstr);
/*
**free1
*/
void			ft_free_quot(t_quot *quot);
void			ft_free_red(t_red *r);
void			ft_free_hty(t_hty *hty);
void			ft_free_term(t_term *t);
/*
**execute
*/
char			*ft_path_istrue(char **cmd, t_env *e);
void			ft_execute_path(char *str, char **cmd, t_env *e);
void			ft_execute(char **cmd, t_env *e);
void			ft_exit(t_exec *exe, t_env *e);
t_env			*ft_make_cmd(t_exec *exe, t_env *e);
/*
**execute2
*/
//void	   		ft_exe_red(t_exec *exe, t_env *e);
//t_red			*ft_dup(t_red *red);
//t_red			*ft_close_dup(t_red *red);
//void    		ft_execute_fd(t_exec *cmd, t_env *e);
//void    		ft_execute_path_fd(char *str, t_exec *cmd, t_env *e);
/*
**bultin
*/
t_env			*ft_cd(t_exec *exe, t_env *e);
t_env			*ft_setenv(t_exec *exe, t_env *e);
t_env			*ft_unsetenv(t_exec *exe, t_env *e);
void			ft_env(t_exec *exe, t_env *e);
void			ft_echo(t_exec *exe, t_env *e);
/*
**cd
*/
t_env			*ft_old(t_exec *exe, t_env *oldpwd, t_env *pwd, t_env *e);
t_env			*ft_null(t_env *pwd, t_env *oldpwd, t_env *home, t_env *e);
t_env			*ft_slash(t_exec *exe, t_env *pwd, t_env *oldpwd, t_env *e);
void			ft_home(t_exec *exe, t_env *pwd, t_env *oldpwd, t_env *home);
t_env			*ft_modif_path(t_exec *exe, t_env *pwd, t_env *oldpwd, t_env *e);
/*
**env
*/
t_env			*ft_moove_env(t_env *env, char *str, int i);
t_env			*ft_env_opt_i(t_env *e, int size);
t_env			*ft_add_env(t_exec *exe, t_env *e, int i, int size);
t_env			*ft_create_elem(char *name, char *value);
t_env			*ft_list_push_back(t_env *begin_list, char *name, char *value);
/*
**signal
*/
void			sig_exe(int sig);
void			sig_init(int sig);
/*
**norme
*/
void			ft_error_cd(t_env *pwd, t_env *oldpwd, t_env *home,\
							t_exec *exe);
char			*ft_string_return(t_env *e, char **cmd);
void			ft_error_and_make_exe(t_exec *exe, t_env *e);
t_exec			*ft_first_struct_exe(char **split);
t_exec			*ft_all_struct_exe(t_exec *exe, char **split);
/*
**maj
*/
t_env			*ft_multi_setenv(t_exec *exe, char *str, t_env *e, t_env *s);
void			ft_env_success(t_exec *exe, t_env *s);
void			ft_putecho(char *s, char **tstr, int i);
t_env			*ft_path_oldpwd(t_env *oldpwd, char *str2, t_env *e);
t_env			*ft_path_pwd(t_env *pwd, char *str3, t_env *e);
/*
**termcaps
*/
int				ft_init_term(t_term *term);
void			ft_update_window(t_term *term);
void			ft_edit_line(t_term *term);
//void			ft_creatline(t_term *term, t_hty *hty);
t_hty			*ft_get_command(t_term *term, t_hty *hty);
/*
**arrow_gestion
*/
//t_term			*ft_write_and_position(t_term *term, char buff[6]);
void			ft_left_arrow(t_term *term);
void			ft_right_arrow(t_term *term);
void			ft_delete(t_term *term);
void			ft_optleft_arrow(t_term *term);
void			ft_optright_arrow(t_term *term);
void			ft_optup_arrow(t_term *term);
void			ft_optdown_arrow(t_term *term);
void			ft_move_home(t_term *term);
void			ft_move_end(t_term *term);
/*
**termcaps_tools.c
*/
void			ft_rotchar(t_term *term);
void			ft_strjoin_v2(t_term *term, int c);
void			ft_putnchar(int c, int len);
void			ft_clear_mlen(t_term *term, t_hty *hty);
void			ft_modif_screen(t_term *term, t_hty *hty);
/*
**utils_termcaps
*/
void			ft_tabulation(t_term *term);
/*
**line_tools
*/
char            *ft_multi_strchr(const char *line);
/*
**tools2
*/
void			ft_insert_char(t_term *term, int c);
void			ft_multiligne_insert_char(t_term *term);
void			ft_multiligne_insert(t_term *term, int c);
/*
**history
*/
t_hty			*ft_add_history(t_term *term);
t_hty			*ft_mem_cmd(t_term *term, t_hty *hty);
t_hty			*ft_rollback_history(t_term *term,t_hty *hty);
t_hty           *ft_up_arrow(t_term *term, t_hty *hty);
t_hty           *ft_down_arrow(t_term *term, t_hty *hty);
/*
**parse
*/
t_exec          *ft_new_exe(void);
t_exec          *ft_get_arg(t_term *term, t_exec *exe);
t_exec          *ft_quot_separation(t_term *term, t_exec *exe);
t_exec          *ft_num_redirection(t_term *term, t_exec *exe);
t_exec          *ft_parse_quot(t_term *term);
t_exec			*ft_cmd_parcing(t_term *term);
/*
**parse_tools
*/
char			*get_mask(int a, int b, int c, int d);
int             ft_listsize_quot(t_quot *quot);
char            **ft_cmd_building(t_term *term, t_exec *exe);
t_quot          *ft_add_arg(t_term *term);
t_exec			*ft_build_quot(t_term *term, t_exec *exe);
/*
**parse_mask
*/
t_exec			*ft_push_mask(t_term *term, t_exec *exe, char *str);
t_exec          *ft_push_mask_v1(t_term *term, t_exec *exe, char *str);
t_exec          *ft_push_mask_v2(t_term *term, t_exec *exe, char *str);
t_exec          *ft_push_mask_v3(t_term *term, t_exec *exe, char *str);
t_exec          *ft_push_mask_v4(t_term *term, t_exec *exe, char *str);
/*
**parse_tri
*/
t_exec  *tri_and(t_term *term, t_exec *e);
t_exec  *tri_pipe(t_term *term, t_exec *e);
t_exec  *tri_right_redirection(t_term *term, t_exec *e);
t_exec  *tri_left_redirection(t_term *term, t_exec *e);
/*
**parse_triav
*/
t_exec          *tri_av_redirection(t_term *term, t_exec *e);
/*
**parse_redirection
*/
t_red   *creat_redirection();
t_exec  *ft_push_red_file(t_term *term, t_exec *e, char *str);
t_exec  *ft_push_red_fd12(t_term *term, t_exec *e, char *str);
t_exec  *ft_push_red_fd1(t_term *term, t_exec *e, char *str);
t_exec  *ft_push_red_error(t_term *term, t_exec *e, char *str);
t_exec  *ft_push_red_fd1file(t_term *term, t_exec *e, char  *str);
/*
**quot
*/
void	ft_dquot(t_term *term, t_exec *exe);
void	ft_quot(t_term *term, t_exec *exe);
/*
**creat_new_exe
*/
t_exec          *ft_background(t_term *term, t_exec *exe);
t_exec          *ft_new_semicolon(t_term *term, t_exec *exe);
t_exec          *ft_pipe(t_term *term, t_exec *exe);
t_exec          *ft_right_redirection(t_term *term, t_exec *exe);
t_exec          *ft_left_redirection(t_term *term, t_exec *exe);
/*
**tools_redirection
*/
t_exec  *ft_double_right(t_term *term, t_exec *exe);
t_exec  *ft_double_left(t_term *term, t_exec *exe);
t_exec  *ft_merge_output(t_term *term, t_exec *exe);
t_exec  *ft_merge_input(t_term *term, t_exec *exe);
/*
**arrow_opt
*/
void    ft_optup_arrow(t_term *term);
void    ft_optdown_arrow(t_term *term);
void    ft_optright_arrow(t_term *term);
void    ft_optleft_arrow(t_term *term);
void	ft_supp(t_term *term);
/*
**parse_execute
*/
int		ft_isbultin(t_exec *exe, t_env *e);
t_env	*make_bultin(t_exec *exe, t_env *e);
t_env   *ft_right_red(t_exec *exe, t_env *e);
t_env   *ft_left_red(t_term *term, t_exec *exe, t_env *e);
t_env   *ft_parse_mask(t_term *term, t_exec *exe, t_env *e);
/*
**make1
*/
t_env   *make_semicolon(t_term *term, t_exec *exe, t_env *e);
t_env   *make_numeric_or(t_term *term, t_exec *exe,t_env *e);
t_env   *make_numeric_and(t_term *term, t_exec *exe, t_env *e);
t_env   *make_pipe(t_term *term, t_exec *exe, t_env *e);
/*
**make2
*/
t_red   *make_right_red(t_exec *exe, t_red *r, t_env *e);
t_red   *make_left_red(t_term *term, t_exec *exe, t_red *r, t_env *e);
t_red   *make_digit(t_exec *exe, t_red *r, t_env *e);
t_env   *make_redirection(t_term *term, t_exec *exe, t_env *e);
/*
**make3
*/
t_red   *make_rightaddrless(t_exec *exe, t_red *r, t_env *e);
t_red   *make_doubleright_redirection(t_exec *exe, t_red *r, t_env *e);
t_red   *make_rightpipe(t_exec *exe, t_red *r, t_env *e);
t_red   *make_right(t_exec *exe, t_red *r, t_env *e);
/*
**make4
*/
t_red   *make_leftaddr(t_exec *exe, t_red *r, t_env *e);
t_red   *make_trileft_redirection(\
								t_exec *exe, t_red *r, t_env *e);
t_red   *make_doubleleftless(t_term *term, t_exec *exe, t_red *r, t_env *e);
t_red   *make_doubleleft(t_term *term, t_exec *exe, t_red *r, t_env *e);
t_red   *make_leftpipe(t_exec *exe, t_red *r, t_env *e);
/*
**make5
*/
t_red   *make_right(t_exec *exe, t_red *r, t_env *e);
t_red   *make_fdrightaddrfd(t_exec *exe, t_red *r, t_env *e);
t_red   *make_fdrightaddrless(t_exec *exe, t_red *r, t_env *e);
t_red   *make_fddoubleright(t_exec *exe, t_red *r, t_env *e);
t_red   *make_fdright(t_exec *exe, t_red *r, t_env *e);
/*
**make6
*/
t_red   *make_fdleftaddrfd(t_exec *exe, t_red *r, t_env *e);
t_red   *make_fdleftaddrless(t_exec *exe, t_red *r, t_env *e);
t_red   *make_fddoubleleft(t_term *term, t_exec *exe, t_red *r, t_env *e);
t_red   *make_fdleft(t_exec *exe, t_red *r, t_env *e);
t_red   *make_left(t_exec *exe, t_red *r, t_env *e);
/*
**make_digit
*/
void	init_redirection(t_exec *exe);
t_red   *make_digit_right(t_exec *exe, t_red *r, t_env *e);
t_red   *make_digit_left(t_term *term, t_exec *exe, t_red *r, t_env *e);
/*
**tools_mask
*/
char	*ft_add_path(char *path, char *file);
t_env	*boucle_numeric_and(t_term *term, t_exec *exe, t_env *e);
t_env	*boucle_numeric_or(t_term *term, t_exec *exe, t_env *e);
t_env	*boucle_pipe(t_term *term, t_exec *exe, t_env *e);
/*
**tools_fd
*/
void	save_fd(t_exec *exe);
void	reload_fd(t_exec *exe);
/*
**execute_fd
*/
void ft_exe_red(t_exec *exe, t_env *e);
t_red *ft_dup(t_red *red);
t_red *ft_close_dup(t_red *red);
void    ft_execute_fd(t_exec *exe, t_env *e);
void    ft_execute_path_fd(char *str, t_exec *exe, t_env *e);
/*
**tools_cmd
*/
char    **ft_list_to_tab_cmd(t_cmd *e);
t_cmd   *ft_tab_to_list_cmd(char **env);
void    free_cmd_str(char **cmd);
void    free_list_cmd_str(t_cmd *c);
t_cmd   *add_cmd_str(t_cmd *c, char *str);
/*
**tools_cmd2
*/
int     ft_listsize_cmd(t_cmd *e);
int     ft_cmp_tabstr(char **cmd);
t_red  	*creat_fd_or_file(char *quot, t_exec *exe, t_red *r);
#endif
