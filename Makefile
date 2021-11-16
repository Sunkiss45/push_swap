# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/12 14:53:30 by ebarguil          #+#    #+#              #
#    Updated: 2021/11/16 13:33:00 by ebarguil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

SRC		=	main.c \
			list_main.c \
			free.c \
			swap.c \
			checker.c \
			algo/algo.c \
			algo/algo-utils.c \
			algo/3num.c \
			algo/4num.c \
			algo/5num.c \
			algo/mort.c \
			utils/ft_atoi.c \
			utils/ft_split.c \
			utils/ft_strlen.c \

OBJ		=	$(SRC:.c=.o)

N	=	norminette

CC		=	gcc

CF		=	-Wall -Wextra -Werror -fsanitize=address -g3

RM		=	rm -rf

all		:	$(NAME)

$(NAME)	:	$(OBJ)
			$(CC) $(CF) -o $(NAME) $(SRC)

n		:
			$(N)

clean	:
			$(RM) $(OBJ)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all
