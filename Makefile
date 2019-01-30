# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/29 14:52:06 by tmaluh            #+#    #+#              #
#    Updated: 2019/01/30 16:37:55 by tmaluh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	MLXFLAGS := -L /usr/local/lib -I /usr/local/lib -lmlx -lXext -lX11 -lm
endif
ifeq ($(UNAME_S),Darwin)
	MLXFLAGS := -L /usr/local/lib -lmlx -lm -framework OpenGL -framework AppKit
endif

CC = gcc -march=native
CFLAGS = -Wall -Wextra -Werror -Ofast

SRC = srcs/main.c srcs/fl_init.c srcs/fl_key_hooks.c srcs/fl_free.c \
srcs/fl_refresh_screen.c srcs/fl_fractols.c srcs/fl_mouse_hooks.c srcs/fl_cir.c

OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a
LMAKE = make -C libft

WHITE=\033[0m
GREEN=\033[32m
RED=\033[31m

DEL = rm -rf

all: $(NAME)

$(OBJ): %.o: %.c
	@echo -n '+'
	@$(CC) -c $(CFLAGS) $< -o $@

$(LIBFT):
	@$(LMAKE)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(OBJ) $(MLXFLAGS) $(LIBFT) -o $(NAME)
	@echo "> $(GREEN)fractol$(WHITE)"

del:
	@$(DEL) $(OBJ)

clean:
	@$(DEL) $(OBJ)
	@$(LMAKE) clean

fclean: clean
	@$(LMAKE) fclean
	@$(DEL) $(NAME)
	@echo "$(RED)deleted$(WHITE): ./fdf"

re: fclean all

.PHONY: all fclean clean re
