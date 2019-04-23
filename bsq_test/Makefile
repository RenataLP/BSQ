# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pguitar <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/11 19:41:43 by pguitar           #+#    #+#              #
#    Updated: 2019/02/17 19:48:42 by pguitar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = eval_expr

CFLAGS = -Wall -Wextra -Werror

SRCS = 

HDR = -I 

BIB = -L. libft.a

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) $(HDR) $(SRCS) $(BIB)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

