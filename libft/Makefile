# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zlayine <zlayine@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/18 09:48:59 by zlayine           #+#    #+#              #
#    Updated: 2021/04/28 12:28:33 by zlayine          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_memccpy.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_split.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_pow.c \
	ft_putnbr.c \
	ft_putstr.c \
	ft_putchar.c \
	ft_hex_digit.c \
	ft_nblen.c \
	ft_nblen_un.c \
	ft_putnbr_un.c \
	ft_get_next_line.c \
	ft_get_newln_len.c \
	ft_new_str.c \
	ft_del.c \
	ft_strstr.c \
	ft_strcmp.c \
	ft_strcpy.c \
	ft_strcat.c \
	ft_arr_dup.c \
	ft_strlower.c \
	ft_arr_len.c \
	ft_lstadd_back.c \
	ft_lstadd_front.c \
	ft_lst_sort.c \
	ft_lstclear.c \
	ft_lstdelone.c \
	ft_lstlast.c \
	ft_lstnew.c \
	ft_arr_del.c \
	ft_lstsize.c
	
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
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all