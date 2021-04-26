# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zlayine <zlayine@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/18 09:48:59 by zlayine           #+#    #+#              #
#    Updated: 2021/04/26 11:21:13 by zlayine          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_del.c \
	ft_isdigit.c \
	ft_atoi.c \
	ft_lstadd_back.c \
	ft_lstnew.c \
	ft_lstsize.c \
	ft_putnbr.c \
	ft_putstr.c \
	ft_putchar.c \
	
OBJ = $(SRC:.c=.o)
CC = gcc
INC = libft.h
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -c $<
	
clean:
	@rm -f $(OBJ) $(OBJ_B)

fclean: clean
	@rm -f $(NAME)

re: fclean all