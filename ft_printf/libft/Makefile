#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbeny <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 21:11:22 by nbeny             #+#    #+#              #
#    Updated: 2017/03/15 02:22:22 by nbeny            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	=	libft.a

N_HDR	=	libft.h get_next_line.h
N_SRC	=	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c\
		ft_memmove.c ft_memchr.c ft_memcmp.c\
		ft_strlen.c ft_strdup.c	ft_strcpy.c ft_strncpy.c\
		ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c\
		ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c\
		ft_strncmp.c\
		ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c\
		ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c\
		ft_memalloc.c ft_memdel.c\
		ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c\
		ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c\
		ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c\
		ft_strsplit.c\
		ft_itoa.c ft_itoa_base.c ft_litoa_base.c ft_uitoa_base.c\
		ft_ulitoa_base.c ft_max_itoa_base.c ft_umax_itoa_base.c\
		ft_size_itoa_base.c ft_short_itoa_base.c ft_ushort_itoa_base.c\
		ft_char_itoa_base.c ft_uchar_itoa_base.c ft_llitoa_base.c\
		ft_ullitoa_base.c\
		ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c\
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
		ft_max.c ft_min.c ft_sort_integer_tab.c ft_sort_params.c\
		ft_sqrt.c\
		ft_putcstr.c ft_capitalizer.c ft_rotcstring.c ft_putnstr.c\
		ft_short_putnbr_base.c ft_ushort_putnbr_base.c ft_char_putnbr_base.c\
		ft_uchar_putnbr_base.c ft_putnbr_base.c ft_uputnbr_base.c\
		ft_lputnbr_base.c ft_ulputnbr_base.c ft_llputnbr_base.c\
		ft_ullputnbr_base.c ft_max_putnbr_base.c ft_umax_putnbr_base.c\
		ft_size_putnbr_base.c ft_power.c\
		ft_wbytelen.c ft_wcharlen.c ft_wstrlen.c\
		ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c\
		ft_lstmap.c ft_lstnew.c get_next_line.c\
		ft_space.c ft_word.c ft_countstr.c ft_tabstr.c\
		ft_putnstr_fd.c ft_split.c

CC	=	gcc
CC_FLAG	=	-Wall -Wextra -Werror

T_SRC	=	./src/
T_INC	=	./include/
T_OBJ	=	./obj/

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
INC	=	$(addprefix -I, $(I_INC))

N_OBJ	=	$(N_SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

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
		@echo ">$(CL_R)clean: $(CL_B)$(NAME) objects$(CL_N)"
		@rm -f $(OBJ)
		@rm -Rf $(T_OBJ)

fclean: clean
		@echo ">$(CL_R)Delete: $(CL_B)$(NAME)$(CL_N)"
		@rm -f $(NAME)

re: fclean all
