# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iharchi <iharchi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/29 10:24:43 by iharchi           #+#    #+#              #
#    Updated: 2021/06/26 16:37:58 by iharchi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CHECKER = checker
PS = push_swap

SRC_UTILS = srcs/stackutils/*.c
CH_SRC = srcs/checker/*.c
PS_SRC = srcs/push_swap/*.c
SRC = srcs/*.c
GNL = gnl/*.c 
LIBFT = libft/libft.a
FLAG = -Wall -Werror -Wextra

all: $(NAME)
$(NAME) : 
			@echo "\033[0;33mMaking LIBFT"
			@$(MAKE) -C libft/
			@$(MAKE) -C libft/ clean
			@gcc push_swap.c -g $(SRC_UTILS) $(PS_SRC) $(SRC) $(LIBFT) $(FLAG)  -o $(NAME)
clean:
	@/bin/rm -f $(OBJECT) $(BONUS_OBJECT)

fclean: clean
	@$(MAKE) -C libft/ fclean
	@/bin/rm -f $(NAME) $(CHECKER)

bonus:
	@gcc checker.c -g $(CH_SRC) $(SRC_UTILS) $(SRC) $(GNL) $(FLAG) -D BUFFER_SIZE=32 $(LIBFT) -o $(CHECKER)

re : fclean all
