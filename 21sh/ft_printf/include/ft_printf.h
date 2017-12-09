/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 14:57:47 by nbeny             #+#    #+#             */
/*   Updated: 2017/03/22 13:10:48 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/include/libft.h"
# include <stdarg.h>
# include <stdlib.h>

typedef struct	s_list
{
	char			buf[4096];
	size_t			i;
	struct s_list	*next;
}				t_list;

typedef struct	s_err
{
	size_t			i;
	int				a;
}				t_err;

typedef struct	s_flag
{
	int				ret;
	char			*format;
	size_t			i;
	char			c;
	char			*arg;
	wchar_t			*warg;
	char			sign;
	va_list			ap;
	int				flag[14];
	size_t			size;
	char			ox[3];
	size_t			x;
	size_t			p;
	int				free;
	int				wc[2];
	int				what;
	int				pre;
	int				neg;
}				t_flag;

typedef struct	s_spec
{
	int				(*ptr)();
	char			c;
}				t_spec;
/*
**multibuf
*/
char			*ft_cpynchar(char *dest, int c, size_t n);
size_t			ft_booster(const char *format, size_t i, t_list **begin_lst);
int				ft_multibuf_nchar(t_list **begin_lst, int c, size_t size);
int				ft_multibuf_arg(t_flag *f, t_list **begin_lst, size_t size);
int				ft_multibuf_ox(t_flag *f, t_list **begin_lst, size_t size);
int				ft_booster2(const char *format, size_t i,
		t_list *lst, size_t n);
int				ft_multibuf_nchar2(t_list *lst, int c, size_t size);
int				ft_multibuf_arg2(t_flag *f, t_list *lst, size_t size);
int				ft_multibuf_ox2(t_flag *f, t_list *lst, size_t size);
/*
**wchar
*/
int				ft_putwchar_in_char(wchar_t wchar, char *fresh,
		int i, t_flag *f);
int				ft_mask_wchar(int size, wchar_t wchar, char *fresh, int i);
char			*ft_transform_wchar_in_char(wchar_t *ws, t_flag *f);
void			ft_wint_to_char(wint_t wchar, t_flag *f);
/*
**printf
*/
int				ft_printf(int fd, const char *format, ...);
int				ft_fill_stdout(int fd, const char *format, va_list *ap);
int				ft_print_and_free(int fd, t_err *e, t_list *begin_lst,\
										t_flag *f);
void			ft_check_init(t_flag *f);
void			ft_init_specs1(t_spec *specs);
void			ft_init_specs2(t_spec *specs);
int				ft_dispatcher(t_flag *f, va_list *ap, t_list **begin_lst);
int				ft_pourcent_gestion(t_err *e, t_list **begin_lst,
		t_flag *f, va_list *ap);
int				ft_error_copy(t_err *e, const char *format, t_list **begin_lst);
/*
**check
*/
void			ft_check_flag(t_flag *f);
void			ft_check_width(t_flag *f);
void			ft_check_precision(t_flag *f);
void			ft_check_modifier(t_flag *f);
int				ft_check(t_flag *f);
/*
**handler
*/
int				ft_handler_wc(t_flag *f, va_list *ap, t_list **begin_lst);
int				ft_handler_c(t_flag *f, va_list *ap, t_list **begin_lst);
int				ft_handler_ws(t_flag *f, va_list *ap, t_list **begin_lst);
int				ft_handler_s(t_flag *f, va_list *ap, t_list **begin_lst);
int				ft_handler_p(t_flag *f, va_list *ap, t_list **begin_lst);
int				ft_handler(t_flag *f, t_list **begin_lst);
int				ft_handler_undefined(t_flag *f, t_list **begin_lst);
/*
**bonus
*/
int				ft_handler_b(t_flag *f, va_list *ap, t_list **begin_lst);
int				ft_handler_t(t_flag *f, va_list *ap, t_list **begin_lst);
int				ft_handler_q(t_flag *f, va_list *ap, t_list **begin_lst);
int				ft_handler_n(t_flag *f, va_list *ap, t_list **begin_lst);
int				ft_handler_v(t_flag *f, va_list *ap, t_list **begin_lst);
/*
**handler d
*/
int				ft_modifier_d(t_flag *f, va_list *ap, t_list **begin_lst);
int				ft_handler_wd(t_flag *f, va_list *ap, t_list **begin_lst);
int				ft_handler_d(t_flag *f, va_list *ap, t_list **begin_lst);
int				ft_handler_hhd(t_flag *f, va_list *ap, t_list **begin_lst);
int				ft_handler_hd(t_flag *f, va_list *ap, t_list **begin_lst);
int				ft_handler_lld(t_flag *f, va_list *ap, t_list **begin_lst);
int				ft_handler_ld(t_flag *f, va_list *ap, t_list **begin_lst);
int				ft_handler_jd(t_flag *f, va_list *ap, t_list **begin_lst);
int				ft_handler_zd(t_flag *f, va_list *ap, t_list **begin_lst);
/*
**handler u
*/
int				ft_modifier_u(t_flag *f, va_list *ap, t_list **begin_lst);
int				ft_handler_wu(t_flag *f, va_list *ap, t_list **begin_lst);
int				ft_handler_u(t_flag *f, va_list *ap, t_list **begin_lst);
int				ft_handler_hhu(t_flag *f, va_list *ap, t_list **begin_lst);
int				ft_handler_hu(t_flag *f, va_list *ap, t_list **begin_lst);
int				ft_handler_llu(t_flag *f, va_list *ap, t_list **begin_lst);
int				ft_handler_lu(t_flag *f, va_list *ap, t_list **begin_lst);
int				ft_handler_ju(t_flag *f, va_list *ap, t_list **begin_lst);
int				ft_handler_zu(t_flag *f, va_list *ap, t_list **begin_lst);
/*
**handler o
*/
int				ft_modifier_o(t_flag *f, va_list *ap, t_list **begin_lst);
int				ft_handler_wo(t_flag *f, va_list *ap, t_list **begin_lst);
int				ft_handler_o(t_flag *f, va_list *ap, t_list **begin_lst);
int				ft_handler_hho(t_flag *f, va_list *ap, t_list **begin_lst);
int				ft_handler_ho(t_flag *f, va_list *ap, t_list **begin_lst);
int				ft_handler_llo(t_flag *f, va_list *ap, t_list **begin_lst);
int				ft_handler_lo(t_flag *f, va_list *ap, t_list **begin_lst);
int				ft_handler_jo(t_flag *f, va_list *ap, t_list **begin_lst);
int				ft_handler_zo(t_flag *f, va_list *ap, t_list **begin_lst);
/*
**handler x
*/
int				ft_modifier_x(t_flag *f, va_list *ap, t_list **begin_lst);
int				ft_handler_wx(t_flag *f, va_list *ap, t_list **begin_lst);
int				ft_handler_x(t_flag *f, va_list *ap, t_list **begin_lst);
int				ft_handler_hhx(t_flag *f, va_list *ap, t_list **begin_lst);
int				ft_handler_hx(t_flag *f, va_list *ap, t_list **begin_lst);
int				ft_handler_llx(t_flag *f, va_list *ap, t_list **begin_lst);
int				ft_handler_lx(t_flag *f, va_list *ap, t_list **begin_lst);
int				ft_handler_jx(t_flag *f, va_list *ap, t_list **begin_lst);
int				ft_handler_zx(t_flag *f, va_list *ap, t_list **begin_lst);
/*
**gestion flag
*/
int				ft_flags_char(t_flag *f, t_list **begin_lst);
int				ft_flags_int(t_flag *f, t_list **begin_lst);
int				ft_precision(t_flag *f);
int				ft_flags_zero2(t_flag *f, int i, t_list **begin_lst);
int				ft_flags_zero3(t_flag *f, t_list **begin_lst);
int				ft_flags_moins2(t_flag *f, t_list **begin_lst);
int				ft_flags_moins3(int i, t_list **begin_lst);
int				ft_flags_plus2(t_flag *f, t_list **begin_lst);
int				ft_flags_plus3(t_flag *f, t_list **begin_lst);
int				ft_flags_int1(t_flag *f, t_list **begin_lst);
int				ft_flags_int2(t_flag *f, t_list **begin_lst);
int				ft_flags_int3(t_flag *f, t_list **begin_lst);
int				ft_flags_int4(t_flag *f, t_list **begin_lst);
int				ft_flags_int5(t_flag *f, t_list **begin_lst);
#endif
