# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pguitar <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/11 19:41:43 by pguitar           #+#    #+#              #
#    Updated: 2019/02/20 23:26:20 by pguitar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = BSQ

CFLAGS = -Wall -Wextra -Werror

SRCS = functions_1.c \
	   functions_2.c \
	   functions_3.c \
	   functions_4.c \
	   functions_5.c \
	   main.c

HDR = -I ft.h

BIB = -L. libft.a

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) $(HDR) $(SRCS) $(BIB)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
