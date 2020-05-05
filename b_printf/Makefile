# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghdesfos <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/20 15:44:22 by ghdesfos          #+#    #+#              #
#    Updated: 2019/02/15 15:58:47 by ghdesfos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
SRC = b_printf.c print_functions.c
NAME = libftprintf.a
INCL = libft.h

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRC) -I $(INCL)
	ar rc $(NAME)  *.o
	ranlib $(NAME)

clean:
	/bin/rm -f *.o
	/bin/rm -f *.gch

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all
