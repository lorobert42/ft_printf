# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/10 14:40:57 by lorobert          #+#    #+#              #
#    Updated: 2022/10/21 08:27:15 by lorobert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:= libftprintf.a

SRCS			:= ft_printf.c
SRCSB			:= $(SRCS)
OBJS			:= $(SRCS:.c=.o)
OBJSB			:= $(SRCSB:.c=.o)

LIBFT_FOLDER	:= ./libft
LIBFT			:= libft.a

CC				:= gcc
CFLAGS			:= -Wall -Wextra -Werror

RM				:= rm -f

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	ar rc $(NAME) $(OBJS)

bonus: $(LIBFT) $(OBJSB)
	ar rc $(NAME) $(OBJSB)

$(LIBFT):
	make -C $(LIBFT_FOLDER) bonus

clean:
	make -C $(LIBFT_FOLDER) clean
	$(RM) $(OBJSB)

fclean: clean
	make -C $(LIBFT_FOLDER) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus libft clean fclean re
