# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbarlow- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/04 12:01:16 by tbarlow-          #+#    #+#              #
#    Updated: 2017/07/04 12:01:26 by tbarlow-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tyron.filler

SRC = main.c reading.c piece.c
CC = gcc -o
FLAG = -Werror -Wextra -Wall

all: $(NAME)

$(NAME):
	$(CC) $(NAME) $(SRC) $(FLAG) libft/libft.a

clean:
	rm -f $(NAME)

re: clean all
