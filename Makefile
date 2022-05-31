# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avillar <avillar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/21 11:11:31 by avillar           #+#    #+#              #
#    Updated: 2022/05/31 16:05:43 by avillar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex

SRCS		=		pipex.c			\
					ft_split.c		\
					utils1.c		\
					utils2.c		\
					utils3.c		\
					ft_strjoin.c	\

SRCS_BONUS	=		pipex_bonus.c	\
					ft_split.c		\
					utils1.c		\
					utils2.c		\
					utils3.c		\
					utils_bonus.c	\
					ft_strjoin.c	\

CFLAG = -Wall -Wextra -Werror

FSAN = -g3 -fsanitize=address

OBJS = $(addprefix src/, ${SRCS:.c=.o})

OBJS_BONUS = $(addprefix src/, ${SRCS_BONUS:.c=.o})

CC	= gcc

all: ft_printf/libprintf.a ${NAME}

.c.o:
	$(CC) $(CFLAG) -Ift_printf -c -I/includes/includes.h $< -o $@

${NAME}: ${OBJS}
	${CC} ${OBJS} -g3 -Lft_printf -lprintf -o $(NAME)

bonus: clean all ${OBJS_BONUS}
	${CC} ${OBJS_BONUS} -g3 -I/includes/includes_bonus.h -Lft_printf -lprintf -o $(NAME)

ft_printf/libprintf.a:
	make -C ft_printf

clean:
		rm -f ${OBJS} ${OBJS_BONUS}

fclean:	clean
	make -C ft_printf fclean
	rm -f ${NAME}

re:	fclean all

.PHONY:	all clean fclean re bonus