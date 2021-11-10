# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: benmoham <benmoham@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/08 16:37:55 by benmoham          #+#    #+#              #
#    Updated: 2021/11/10 15:29:28 by benmoham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	SRCS/so_long.c\
				SRCS/aff_onlygame.c\
				SRCS/aff_onlymap.c\
				SRCS/ft_error.c\
				SRCS/ft_hook.c\
				SRCS/ft_move_ingame.c\
				SRCS/ft_move.c\
				SRCS/ft_checkmap.c\
				SRCS/get_next_line.c\
				SRCS/get_next_line_utils.c\
				SRCS/ft_split.c\
				SRCS/ft_strcat.c\
			

OBJS 		= ${SRCS:.c=.o}

UNAME		:= $(shell uname)
PATH_MLX	= mlx
CC 			= clang
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
NAME		= so_long
FLAGS		= -ldl -Imlx -Lmlx -lmlx -lm -lbsd -lXext -lX11

all: 		${NAME}

.c.o:
			${CC} ${CFLAGS} -Imlx -Ibass -c $< -o ${<:.c=.o}

$(NAME): 	$(OBJS)
			${CC} $(CFLAGS) -o $(NAME) $(OBJS) $(FLAGS)

clean:
			${RM} ${OBJS}

fclean: 	clean
			${RM} ${NAME}

re: 		fclean all