# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/12 14:53:30 by ebarguil          #+#    #+#              #
#    Updated: 2021/11/19 13:59:51 by ebarguil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED		=	"\033[1;31m"
GREEN	=	"\033[1;32m"
YELLOW	=	"\033[1;33m"
BLUE	=	"\033[1;34m"
PURPLE	=	"\033[1;35m"
CYAN	=	"\033[1;36m"
GREY	=	"\033[1;37m"
RESET	=	"\033[0m"

NAME	=	push_swap

SRC		=	main.c \
			list_main.c \
			free.c \
			ope.c \
			opesup.c \
			checker.c \
			algo/algo.c \
			algo/algo-utils.c \
			algo/3num.c \
			algo/4num.c \
			algo/5num.c \
			algo/bignum.c \
			utils/ft_atoi.c \
			utils/ft_split.c \
			utils/ft_strlen.c \

OBJ		=	$(SRC:.c=.o)

N		=	norminette

CC		=	gcc

CF		=	-Wall -Wextra -Werror -fsanitize=address -g3

RM		=	rm -rf

all		:	$(NAME)

$(NAME)	:	$(OBJ)
			$(CC) $(CF) -o $(NAME) $(SRC)

clean	:
			$(RM) $(OBJ)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

n		:
			$(N)

perso	: fclean n all clean

.PHONY	:	all fclean clean re n perso
