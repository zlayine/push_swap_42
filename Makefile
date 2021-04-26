# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zlayine <zlayine@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/14 12:07:00 by zlayine           #+#    #+#              #
#    Updated: 2021/04/26 12:41:13 by zlayine          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swape

SRC = push_swap/main.c

LIBFT = ./libft

LIBFT_LIB = $(LIBFT)/libft.a

PUSH_LIB = push_swap.a

OBJ = $(SRC:.c=.o)

# MAIN = srcs/main.c

NORMAL = $(PUSH_LIB)

all: $(NAME)


$(LIBFT_LIB):
	@make -C $(LIBFT)

$(NAME): $(OBJ) $(LIBFT_LIB)
	@ar rcs $(PUSH_LIB) $(OBJ)
	@gcc $(PUSH_LIB) $(LIBFT_LIB) -o $(NAME)
	@echo "SUCCESS! NO WWW PLEAAAAAAASE ADDDDDD --------------------------------------"

%.o: %.c
	@gcc -c $< -o $@

	# @gcc -Wall -Wextra -Werror -c $< -o $@

clean:
	@make clean -C $(LIBFT)
	@rm -rf $(OBJ)

fclean: clean
	@make fclean -C $(LIBFT)
	@rm -rf $(PUSH_LIB)
	@rm -rf $(NAME)

re: fclean all
