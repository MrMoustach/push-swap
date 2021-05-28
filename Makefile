# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iharchi <iharchi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/29 10:24:43 by iharchi           #+#    #+#              #
#    Updated: 2021/05/28 12:31:26 by iharchi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = t

CHECKER = checker
PS = push_swap

SRC_UTILS = srcs/stackutils/*.c
CH_SRC = srcs/checker/*.c
PS_SRC = srcs/push_swap/*.c
SRC = srcs/*.c
GNL = gnl/*.c 
LIBFT = libft/libft.a
FLAG = -Wall -Werror -Wextra
ch: 
		@gcc checker.c -g $(CH_SRC) $(SRC_UTILS) $(SRC) $(GNL) -D BUFFER_SIZE=32 $(LIBFT) -o $(CHECKER)
ps:
		@gcc push_swap.c -g $(SRC_UTILS) $(PS_SRC) $(SRC) $(LIBFT)  -o $(PS)
all: $(NAME)
$(NAME) : 
			@gcc $(SRC) $(GNL) $(FLAG)
clean:
	@/bin/rm -f $(OBJECT) $(BONUS_OBJECT)

fclean: clean
	@/bin/rm -f $(NAME)

re : fclean all
