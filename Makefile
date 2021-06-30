# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iharchi <iharchi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/29 10:24:43 by iharchi           #+#    #+#              #
#    Updated: 2021/06/30 13:46:24 by iharchi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= push_swap
CHECKER = checker
PS 		= push_swap

SRC_UTILS	= srcs/stackutils/stacklist_helpers.c srcs/stackutils/stacklist.c srcs/stackutils/stack_helpers.c srcs/stackutils/stack.c
PS_SRC		= srcs/push_swap/utils_helper2.c srcs/push_swap/utils.c srcs/push_swap/utils_helper.c
SRC			= srcs/ft_atol.c srcs/utlis.c
GNL			= get_next_line/get_next_line.c get_next_line/get_next_line_utils.c 
LIBFT		= libft/libft.a
FLAG		= -Wall -Werror -Wextra

all: $(NAME)
$(NAME) : 
			@echo "\033[0;33mMaking LIBFT\033[0m"
			@$(MAKE) -C libft/
			@$(MAKE) -C libft/ clean
			@echo "\033[0;33mMaking PUSH_SWAP\033[0m"
			@gcc push_swap.c $(SRC_UTILS) $(PS_SRC) $(SRC) $(LIBFT) $(FLAG)  -o $(NAME)
clean:
			@/bin/rm -f $(OBJECT) $(BONUS_OBJECT)

fclean: clean
			@$(MAKE) -C libft/ fclean
			@/bin/rm -f $(NAME) $(CHECKER)

bonus:
			@echo "\033[0;33mMaking CHECKER\033[0m"
			@gcc checker_bonus.c $(CH_SRC) $(SRC_UTILS) $(SRC) $(GNL) $(FLAG) -D BUFFER_SIZE=32 $(LIBFT) -o $(CHECKER)

re : fclean all
