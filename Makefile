# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/08 16:23:03 by abelfany          #+#    #+#              #
#    Updated: 2023/03/24 15:40:29 by abelfany         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADR = fractol.h
NAME = fractol
SRC_M = fractol.c \
		ft_atoi.c \
		mandelbrot.c \
		Julia.c \
		handler.c \

OBJ_S = $(SRC_M:.c=.o)
CFLAG = -Wall -Wextra -Werror
CC = cc
RM = -@rm -rf 
MLX = -lmlx -framework OpenGL -framework AppKit
all : $(NAME)
	@echo "            \033[0;106m\033[\033[0;33m🄱 \033[0;106m 🅈  🄰 🄱_🄴 🄻 🄵 🄰 🄽 🅈 \033[0;33m"
	@echo "             \033[0;106m\033[1;94m🄱 🅈  🄰 🄱_🄴 🄻 🄵 🄰 🄽 🅈 \033[0;33m"
	@echo "             \033[0;106m\033[1;94m🄱 🅈  🄰 🄱_🄴 🄻 🄵 🄰 🄽 🅈 \033[0;33m"
	@echo "             \033[0;106m\033[1;94m🄱 🅈  🄰 🄱_🄴 🄻 🄵 🄰 🄽 🅈 \033[0;33m"
	@echo "             \033[0;106m\033[1;94m🄱 🅈  🄰 🄱_🄴 🄻 🄵 🄰 🄽 🅈 \033[0;33m"
%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJ_S)
	$(CC) $(MLX) $(OBJ_S) -o $(NAME)

clean:
	$(RM) $(OBJ_S)

fclean:clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all re fclean clean