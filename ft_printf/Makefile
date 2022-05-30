# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avillar <avillar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/06 11:34:20 by avillar           #+#    #+#              #
#    Updated: 2021/09/06 11:51:56 by avillar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libprintf.a

SRCS		=	ft_printf.c			\
				ft_printf_utils1.c	\
				ft_convert_base1.c	\
				ft_convert_base2.c	\
				ft_printf_utils2.c	\
				ft_printf_utils3.c	\
				struct_utils.c		\

OBJS		= $(addprefix src/, ${SRCS:.c=.o})

.c.o:
			gcc -Wall -Wextra -Werror -c -I./includes/header.h $< -o $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar -rcs $@ $^

all:		${NAME}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re