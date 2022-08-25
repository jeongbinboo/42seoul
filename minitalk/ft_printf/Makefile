# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jboo <jboo@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/06 12:21:47 by jboo              #+#    #+#              #
#    Updated: 2022/06/06 12:21:48 by jboo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
FILES =	ft_printf.c\
		ft_printf_char.c\
		ft_printf_str.c\
		ft_printf_deci.c\
		ft_printf_unsigned.c\
		ft_printf_hex.c\
		ft_printf_pointer.c\
		_itoa.c\
		_strlen.c\

FILES_OBJS=$(FILES:.c=.o)

OBJ_FILES = $(FILES_OBJS)

all : $(NAME)

.c.o: $(FILES)
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME) : $(OBJ_FILES)
	ar rc $(NAME) $(OBJ_FILES)

clean :
	rm -rf $(FILES_OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
