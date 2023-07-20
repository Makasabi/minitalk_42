# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrony <mrony@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/06 10:52:14 by mrony             #+#    #+#              #
#    Updated: 2023/06/13 11:32:16 by mrony            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf.a

SRC = 	src/ft_printf.c \
		src/ft_format.c \
		src/ft_utils.c \
		src/c_format.c \
		src/s_format.c \
		src/di_format.c \
		src/u_format.c \
		src/mod_format.c \
		src/x_format.c \
		src/xx_format.c \
		src/p_format.c \
		src/ft_itoa.c \
		src/ft_strlen.c

CC = gcc

CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $^

$(NAME) : $(OBJ)
	ar -rcs $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:
	make clean
	make all

.PHONY: all clean fclean re
