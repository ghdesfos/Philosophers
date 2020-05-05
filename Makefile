# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghdesfos <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/21 17:45:42 by ghdesfos          #+#    #+#              #
#    Updated: 2020/01/25 20:56:36 by ghdesfos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
NCURSES		= -lncurses
RM			= /bin/rm -rf

INCLUDES	= -I includes\
				-I b_printf
HEADERS		= includes/philo.h
LIBFTPRINTF	= b_printf/libftprintf.a
LIB			= -L b_printf/ -lftprintf

FUNCTIONS	= philo.c\
				init.c\
				chopstick.c\
				thread.c\
				visualizer.c\
				support.c
FILES		= $(addprefix sources/, $(FUNCTIONS))
OBJECTS		= $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS) $(HEADERS) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) $(NCURSES) $(INCLUDES) $(LIB) $(OBJECTS) -o $@

g: $(OBJECTS) $(HEADERS) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) $(NCURSES) $(INCLUDES) $(LIB) $(OBJECTS) -o $@ -g

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFTPRINTF):
	make -C b_printf

clean:
	make clean -C b_printf
	$(RM) $(OBJECTS)
	$(RM) *.gch
	$(RM) *.dSYM

fclean: clean
	make fclean -C b_printf
	$(RM) $(NAME)

re: fclean all
	make re -C b_printf

.PHONY: all clean fclean re
