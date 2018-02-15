# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mipham <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/27 15:48:09 by mipham            #+#    #+#              #
#    Updated: 2017/12/27 15:48:24 by mipham           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMECHECKER = checker
NAMEPUSHSWAP = push_swap

_GREEN = $'\x1b[32m
_CYAN = $'\x1b[36m
_RED = $'\x1b[31m
_YELLOW = $'\x1b[33m
_PURPLE = $'\x1b[35m
_BLUE = $'\x1b[34m

LIB = include/libft

#SRCCHECKER = src/checker.c src/methods.c src/methods2.c src/methods3.c\
						src/algos.c src/algos1.c\
						src/ops1.c src/ops2.c src/ops3.c src/ops4.c src/ops5.c
SRCPUSH = src/methods.c src/methods2.c\
						src/ops1.c src/ops2.c src/ops3.c src/ops4.c\
						src/ft_count_list.c\

INC = -I includes

#OBJCHECKER = $(SRCCHECKER:.c=.o)
OBJPUSH = $(SRCPUSH:.c=.o)

CC = gcc

LIBPATH =	include/libft/libft.a

CFLAGS = -Wall -Wextra -Werror

all: $(NAMEPUSHSWAP)

#$(NAMECHECKER): $(OBJCHECKER)
#	make -C $(LIB)
#	$(CC) -o $(NAMECHECKER) $(OBJCHECKER) $(LIBPATH)
#	@echo "${_YELLOW}pushswap generate${_END} ${_BLUE}[!${_END}]"

$(NAMEPUSHSWAP): $(OBJPUSH)
	make -C $(LIB)
	$(CC) -o $(NAMEPUSHSWAP) $(OBJPUSH) $(LIBPATH)
	@echo "${_YELLOW}pushswap generate${_END} ${_BLUE}[!${_END}]"


clean:
		#rm -f $(OBJCHECKER)
		rm -f $(OBJPUSH)
			make clean -C ./include/libft/
			@echo "${_CYAN}cleaning objects files${_END} ${_PURPLE}[!${_END}]"

fclean: clean
		#rm -f $(NAMECHECKER)
		rm -f $(NAMEPUSHSWAP)
			make fclean -C ./include/libft/
			@echo "${_RED}delete $(NAMECHECKER) $(NAMEPUSHSWAP) ${_END}${_GREEN}[!${_END}]"

re: fclean all

.PHONY : all, re, clean, fclean
