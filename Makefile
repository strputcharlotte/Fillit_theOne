# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/29 16:32:57 by emoreau           #+#    #+#              #
#    Updated: 2018/02/22 14:18:34 by cfarjane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= fillit
SRC 	= main.c parser.c read.c
FLAGS 	= -Werror -Wall -Wextra -g
CC 		= gcc

OBJ = $(SRC:.c=.o)
	CL=\x1b[35m
	GREEN=\033[1;32m
	RED=\033[1;31m
	CL2=\x1b[36m
	NC=\033[0m

%.o: %.c
		@$(CC) -c $< -o $@ $(FLAGS)

all:  $(NAME)

$(NAME): $(OBJ)
	@make -C ./libft
	@echo "$(GREEN)[✓]$(NC)$(CL) Objects of libft compiled$(NC)"
	@$(CC) $(FLAGS) $(SRC) -o $(NAME) -I libft/ -L libft/ -lft
	@echo "$(GREEN)[✓]$(NC)$(CL) executable $(NAME) built$(NC)"

clean:
	@rm -f $(OBJ)
	@echo "$(RED)[-]$(NC)$(CL2) Objects of $(NAME) cleaned$(NC)"

fclean: clean
	@rm -rf fillit
	@echo "$(RED)[-]$(NC)$(CL2) Library $(NAME) cleaned$(NC)"

re: fclean all
