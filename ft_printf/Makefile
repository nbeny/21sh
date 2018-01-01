# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/16 14:57:18 by nbeny             #+#    #+#              #
#    Updated: 2017/03/15 02:22:09 by nbeny            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

N_INC	=	ft_printf.h
N_SRC	=	ft_printf.c		ft_check.c\
		ft_dispatcher.c		ft_handler_c.c\
		ft_handler_s.c		ft_handler_p.c\
		ft_handler_d.c		ft_handler_o.c\
		ft_handler_u.c		ft_handler_x.c\
		ft_handler.c		ft_flag_hhlld.c\
		ft_flag_hhllo.c		ft_flag_hhllu.c\
		ft_flag_hhllx.c		ft_flag_jzd.c\
		ft_flag_jzo.c		ft_flag_jzu.c\
		ft_flag_jzx.c		ft_flags_char.c\
		ft_flags_int.c		ft_precision.c\
		ft_flags_int2.c		ft_flags_int3.c\
		ft_gestion_wchar.c	ft_handler_undefined.c\
		ft_flags_int4.c		ft_handler_b.c\
		ft_handler_t.c		ft_handler_q.c\
		ft_handler_n.c		ft_handler_v.c\
		ft_buffer.c		ft_buffer2.c\
		ft_printf2.c

CC	=	gcc
CC_FLAG	=	-Wall -Wextra -Werror #-fsanitize=address -g3

T_SRC	=	./src/
T_INC	=	./include/
T_OBJ	=	./obj/
T_LFT	=	./libft/

I_INC	=	./include/
I_LFT	=	./libft/include/
L_LFT	=	-L ./ft_printf/ -lftprintf

CL_N	=	\033[0m
CL_R	=	\033[31m
CL_V	=	\033[32m
CL_J	=	\033[33m
CL_B	=	\033[34m
CL_C	=	\033[36m

CL_NS	=	\033[0;4m
CL_RS	=	\033[31;4m
CL_VS	=	\033[32;4m
CL_JS	=	\033[33;4m
CL_BS	=	\033[34;4m
CL_CS	=	\033[36;4m

CL_NG	=	\033[0;1m
CL_RG	=	\033[31;1m
CL_VG	=	\033[32;1m
CL_JG	=	\033[33;1m
CL_BG	=	\033[34;1m
CL_CG	=	\033[36;1m

SRC	=	$(addprefix $(T_SRC), $(N_SRC))
OBJ	=	$(addprefix $(T_OBJ), $(N_OBJ))
INC	=	$(addprefix -I, $(I_INC) $(I_LFT))

N_OBJ	=	$(N_SRC:.c=.o)

.PHONY: all clean fclean re

all: mlib $(NAME)

$(NAME): $(OBJ)
		@echo "\n>$(CL_V)Build: $(CL_VG)$(NAME)$(CL_N)"
		@ar rc $(NAME) $(OBJ)
		@echo ">$(CL_J)Ranlib booster..$(CL_N)"
		@ranlib $(NAME)

$(T_OBJ)%.o: $(T_SRC)%.c
		@echo ">$(CL_V)Creat: Objects files..$(CL_N)"
		@mkdir -p $(T_OBJ)
		@$(CC) $(CC_FLAG) -o $@ -c $^ $(INC)

clean:
		@make -C $(T_LFT) clean
		@echo ">$(CL_R)clean: $(CL_B)$(NAME) objects$(CL_N)"
		@rm -f $(OBJ)
		@rm -Rf $(T_OBJ)

fclean: clean
		@make -C $(T_LFT) fclean
		@echo ">$(CL_R)Delete: $(CL_B)$(NAME)$(CL_N)"
		@rm -f $(NAME)
mlib:
	@make -C $(T_LFT)
re: fclean all
