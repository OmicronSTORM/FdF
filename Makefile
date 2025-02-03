# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/03 14:25:33 by jowoundi          #+#    #+#              #
#    Updated: 2025/02/03 15:06:05 by jowoundi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdflib.a

SRC =

OBJS = $(SRC: .c=.o)

INCLUDE = includes

CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE)
LIB_FLAGS = 