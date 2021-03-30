# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iharchi <iharchi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/29 10:24:43 by iharchi           #+#    #+#              #
#    Updated: 2021/03/29 11:32:50 by iharchi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = t

CHECKER = checker
PS = push_swap

SRC = srcs/*/*.c
GNL = gnl/*.c -D BUFFER_SIZE=32
LIBFT = libft/libft.a
FLAG = -Wall -Werror -Wextra
ch: 
		@gcc checker.c $(SRC) $(GNL) $(LIBFT) -o $(CHECKER)
all: $(NAME)
$(NAME) : 
			@gcc $(SRC) $(GNL) $(FLAG)
clean:
	@/bin/rm -f $(OBJECT) $(BONUS_OBJECT)

fclean: clean
	@/bin/rm -f $(NAME)

re : fclean all
