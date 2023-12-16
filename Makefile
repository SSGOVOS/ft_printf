# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amoubine <amoubine@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/14 01:14:44 by amoubine          #+#    #+#              #
#    Updated: 2023/12/15 01:53:56 by amoubine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f



SRC = ft_printf.c  ft_putchar.c  ft_putnbr.c  ft_putstr.c ft_long.c ft_putnbr_base.c ft_strlen.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)
 
$(NAME): $(OBJ)
		ar rc $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all