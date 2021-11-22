# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/12 14:53:30 by ebarguil          #+#    #+#              #
#    Updated: 2021/11/22 12:01:39 by ebarguil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

SRC		=	main.c \
			list_main.c \
			free.c \
			ope.c \
			opesup.c \
			checker.c \
			algo/algo.c \
			algo/3num.c \
			algo/4num.c \
			algo/5num.c \
			algo/bignum.c \
			utils/ft_atoi.c \
			utils/ft_split.c \
			utils/ft_strlen.c \
			utils/ft_strjoin.c \

OBJ		=	$(SRC:.c=.o)

N		=	norminette

CC		=	gcc

CF		=	-Wall -Wextra -Werror

CFS		=	-fsanitize=address -g3

RM		=	rm -rf

all		:	$(NAME)

$(NAME)	:	$(OBJ)
			$(CC) $(CF) -o $(NAME) $(SRC)

clean	:
			$(RM) $(OBJ)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

f		:	$(OBJ)
			$(CC) $(CF) $(CFS) -o $(NAME) $(SRC)

fre		:	fclean f

n		:
			$(N)

perso	:	fre bfre allcl


# ================================ #
# ========== MAKE BONUS ========== #
# ================================ #


NAMEB	=	checker

SRCB	=	bonus/main.c \
			bonus/list_main.c \
			bonus/free.c \
			bonus/ope.c \
			bonus/opesup.c \
			bonus/checker.c \
			bonus/instru.c \
			bonus/gnl/get_next_line.c \
			bonus/gnl/get_next_line_utils.c \
			bonus/utils/ft_atoi.c \
			bonus/utils/ft_split.c \
			bonus/utils/ft_strlen.c \
			bonus/utils/ft_strjoin.c \

OBJB	=	$(SRCB:.c=.o)

bonus	:	$(NAMEB)

$(NAMEB):	$(OBJB)
			$(CC) $(CF) -o $(NAMEB) $(SRCB)

bclean	:
			$(RM) $(OBJB)

bfclean	:	bclean
			$(RM) $(NAMEB)

bre		:	bfclean bonus

bf		:	$(OBJB)
			$(CC) $(CF) $(CFS) -o $(NAMEB) $(SRCB)

bfre	:	bfclean bf


# ================================ #
# ========== UNIQUE FNC ========== #
# ================================ #

allcl	:	clean bclean

allfcl	:	fclean bfclean

.PHONY	:	all fclean clean re n perso bonus bclean fbclean bre bf bfre
