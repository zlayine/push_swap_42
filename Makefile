# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zlayine <zlayine@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/14 12:07:00 by zlayine           #+#    #+#              #
#    Updated: 2021/04/29 11:33:09 by zlayine          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SWAP = push_swap

CHECKER = checker

SWAP_SRC = push/main.c \
	push/swaps.c \
	push/helpers.c \
	push/median.c \
	push/rotate.c

CHECKER_SRC = check/main.c

UTILS_SRC = utils/utils.c \
	utils/debug.c \
	utils/lst_fun.c \
	utils/swap_fun.c \
	utils/validation.c

LIBFT = ./libft

LIBFT_LIB = $(LIBFT)/libft.a

SWAP_LIB = puash_swap.a

UTILS_OBJ = $(UTILS_SRC:.c=.o)

all: $(CHECKER) $(SWAP)

$(LIBFT_LIB):
	@make -C $(LIBFT)

$(SWAP): $(SWAP_SRC) $(UTILS_OBJ) $(LIBFT_LIB)
	@ar rcs $(SWAP_LIB) $(UTILS_OBJ)
	@gcc $(SWAP_LIB) $(LIBFT_LIB) $(SWAP_SRC) -o $(SWAP)
	@echo "SWAP IS READY!"

$(CHECKER): $(CHECKER_SRC) $(UTILS_OBJ) $(LIBFT_LIB)
	@ar rcs $(SWAP_LIB) $(UTILS_OBJ)
	@gcc $(SWAP_LIB) $(LIBFT_LIB) $(CHECKER_SRC) -o $(CHECKER)
	@echo "CHECKER IS READY!"

bonus: $(CHECKER) $(SWAP)

%.o: %.c
	@gcc -Wall -Wextra -Werror -c $< -o $@

clean:
	@make clean -C $(LIBFT)
	@rm -rf $(UTILS_OBJ)

fclean: clean
	@make fclean -C $(LIBFT)
	@rm -rf $(SWAP_LIB) $(SWAP) $(CHECKER)

re: fclean all
