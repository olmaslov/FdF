# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omaslov <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/16 09:47:36 by omaslov           #+#    #+#              #
#    Updated: 2018/03/16 09:47:41 by omaslov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, compile, clean, fclean, re

NAME = fdf
SRC = main.c reader.c drawer.c brezenham.c map_init.c spin.c keys.c
INC_LIBFT = ./libft/includes
CC = gcc
FLAG = -Wall -Wextra -Werror -L libft/ -lft
MLX_LINK = -lmlx -framework OpenGL -framework AppKit
OBJ = $(subst .c, .o, $(SRC))

all: compile

compile:
	make -C ./libft/
	@$(CC) $(FLAG) -o $(NAME) $(SRC) -I $(INC_LIBFT) $(MLX_LINK)
	@echo "Compiling" [ $(NAME) ]

clean:
	make clean -C libft/
	rm -f $(OBJ)

fclean:
	make fclean -C libft/
	rm -f $(NAME)

re: fclean all
