# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/05 14:26:39 by jowoundi          #+#    #+#              #
#    Updated: 2025/02/10 14:00:55 by jowoundi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror
GREEN   = "\\033[32m"
YELLOW	= "\\033[33m"
NC      = "\\033[0m"

LIBFT_DIR = ./libft
MINILIBX_DIR = ./minilibx-linux
LIBFT = $(LIBFT_DIR)/libft.a
MINILIB = $(MINILIBX_DIR)/libmlx.a
INCLUDES = -I ./inc -I $(LIBFT_DIR) -I $(MINILIBX_DIR)

SRC_DIR = src/
OBJ_DIR = obj/

# Source files from the src directory
SRCS =  main.c close_window.c

OBJS = $(patsubst %.c, $(OBJ_DIR)%.o, $(SRCS))

TOTAL_FILES := $(words $(SRCS))
CURRENT_FILE := 0

define progress_bar
	@$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE) + 1))))
	@printf "\r$(YELLOW)Compiling fdf... [%-$(TOTAL_FILES)s] %d/%d $(NC)" \
	$$(for i in $$(seq 1 $(CURRENT_FILE)); do printf "#"; done) $(CURRENT_FILE) $(TOTAL_FILES)
	@if [ $(CURRENT_FILE) -eq $(TOTAL_FILES)  ]; then echo ""; fi
endef

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	$(call progress_bar)


FDF_LOGO = "\033[5;36m\
███████╗██████╗ ███████╗     \n\
██╔════╝██╔══██╗██╔════╝     \n\
█████╗  ██║  ██║█████╗       \n\
██╔══╝  ██║  ██║██╔══╝       \n\
██║     ██████╔╝██║          \n\
╚═╝     ╚═════╝ ╚═╝          \n\
\033[0m"


all: $(LIBFT) $(MINILIB) $(NAME)

$(NAME): $(OBJS)
	@printf "\n"
	@printf $(FDF_LOGO)
	@echo "$(GREEN)Linking objects to create executable...$(NC)"
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -L$(MINILIBX_DIR) -lft -lmlx -lX11 -lXext -lm -o $(NAME)
	@echo "$(GREEN)Executable $(NAME) created!$(NC)"

$(LIBFT):
	@make -C $(LIBFT_DIR) -s

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean --no-print-directory

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean --no-print-directory

re: fclean all

.PHONY: all clean fclean re