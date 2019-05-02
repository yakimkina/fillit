# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enikole <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/28 14:44:59 by enikole           #+#    #+#              #
#    Updated: 2019/04/29 14:40:14 by enikole          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = fillit

HEAD = fillit.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = algorithm.c \
	  is_valid.c \
	  list.c \
	  map.c \
	  main.c

OBJ = $(SRC:%.c=%.o)

LIBA = ./libft/

LIB = $(LIBA)libft.a

INC = $(LIBA)includes/*.h

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) -I$(INC) -L$(LIBA) -lft

$(OBJ): $(SRC) $(HEAD)
	$(CC) $(CFLAGS) -I$(INC) -o $@ -c $<

$(LIB):
	make -C $(LIBA) fclean && make -C $(LIBA)

clean:
	/bin/rm -f $(OBJ)
	make clean -C $(LIBA)

fclean: clean
	/bin/rm -f $(NAME)
	make fclean -C $(LIBA)

re: fclean all
