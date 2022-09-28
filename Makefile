# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aandric <aandric@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/03 15:35:01 by aandric           #+#    #+#              #
#    Updated: 2022/02/25 16:31:38 by aandric          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBFT = ./libft/libft.a \

MLX = ./mlx/libmlx.a \

SRCS =	so_long.c \
		get_map.c \
		main.c \
		parse_map.c \
		init_map.c \
		get_events.c \
		utils.c \
		move_pers.c \

OBJS = ${SRCS:.c=.o}

HEADER = so_long.h \

CMD = gcc
FLAGS = -Wall -Werror -Wextra -I mlx

%.o: %.c $(HEADER)
	$(CMD) $(FLAGS) -c $< -o $@ 

all: libft mlx $(NAME)

libft:
		make -C ./libft

mlx:
		make -C ./mlx

$(NAME): $(OBJS) $(LIBFT) $(MLX) Makefile
	$(CMD) $(OBJS) $(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -rf $(OBJS) 
	make clean -C ./libft
	make clean -C ./mlx
 
fclean: clean
	rm -rf $(NAME)
 
re: fclean all
 
.PHONY: libft mlx clean all re fclean