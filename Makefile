# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/03 14:25:33 by jowoundi          #+#    #+#              #
#    Updated: 2025/02/04 19:01:08 by jowoundi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = main.c

OBJ = $(SRC:.c=.o)

INCLUDE = includes

CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE)
MLX_FLAGS = -lmlx -L./minilibx-linux -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): libft/libft.a minilibx-linux/libmlx.a $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(MLX_FLAGS)

minilibx-linux/libmlx.a:
	make -C ./minilibx-linux 2>/dev/null

libft/libft.a:
	make -C ./libft
	
%.o: %.c
	$(CC) $(CFLAGS) -O3 -c $< -o $@

clean:
	$(RM) $(OBJ)
	make -C ./libft clean
	make -C ./minilibx-linux clean

fclean: clean
	$(RM) $(NAME)
	
re: fclean all

.PHONY: all clean fclean re