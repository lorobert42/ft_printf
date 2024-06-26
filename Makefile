# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/10 14:40:57 by lorobert          #+#    #+#              #
#    Updated: 2022/10/26 15:17:05 by lorobert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	libftprintf.a

SRCS		:=	ft_printf.c \
				ft_printf_char.c \
				ft_printf_int.c \
				ft_printf_ptr.c \
				ft_printf_hex.c \
				ft_printf_string.c \
				ft_printf_uint.c \
				ft_itoa_unsigned.c \
				ft_itoa_hex.c \
				ft_itoa_ptr.c
OBJS		:=	$(SRCS:.c=.o)

LIBFT_DIR	:=	./libft
LIBFT		:=	$(addprefix $(LIBFT_DIR)/, libft.a)

CC			:=	gcc
CFLAGS		:=	-Wall -Wextra -Werror

RM			:=	rm -f

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) ./$(NAME)
	ar rc $(NAME) $(OBJS)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all libft clean fclean re
