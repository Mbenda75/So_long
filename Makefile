# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: benmoham <benmoham@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/08 16:37:55 by benmoham          #+#    #+#              #
#    Updated: 2021/11/09 20:40:08 by benmoham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	so_long.c\
				aff_onlygame.c\
				aff_onlymap.c\
				ft_error.c\
				ft_hook.c\
				ft_move_ingame.c\
				ft_move.c\
				ft_checkmap.c\
				get_next_line.c\
				get_next_line_utils.c\
				ft_split.c\
				ft_strcat.c\
			

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