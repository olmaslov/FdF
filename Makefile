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
SRC = main.c reader.c drawer.c
INC_LIBFT = ./libft/includes
CC = gcc
FLAG = -Wall -Wextra -Werror
MLX_LINK = -lmlx -lXext -l X11 -L libft/ -lft
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
