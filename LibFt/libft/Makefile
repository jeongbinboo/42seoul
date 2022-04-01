CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME=libft.a
FILES =	ft_isprint.c \
		ft_strlen.c \
		ft_atoi.c \
		ft_isascii.c \
		ft_strlcat.c \
		ft_strncmp.c \
		ft_isdigit.c \
		ft_strlcpy.c \
		ft_isalpha.c \
		ft_isalnum.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c\
		ft_toupper.c\
		ft_tolower.c\
		ft_strchr.c\
		ft_strrchr.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_strnstr.c\
		ft_memccpy.c\
		ft_calloc.c\
		ft_strdup.c\
		ft_substr.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_split.c\
		ft_itoa.c\
		ft_strmapi.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\

BONUS_FILES =	ft_lstnew.c \
				ft_lstadd_front.c\
				ft_lstsize.c\
				ft_lstlast.c\
				ft_lstadd_back.c\
				ft_lstdelone.c\
				ft_lstclear.c\
				ft_lstiter.c\
				ft_lstmap.c\

FILES_OBJS=$(FILES:.c=.o)
BONUS_OBJS=$(BONUS_FILES:.c=.o)

ifdef WITH_BONUS
	OBJ_FILES = $(FILES_OBJS) $(BONUS_OBJS)
else
	OBJ_FILES = $(FILES_OBJS)
endif

all : $(NAME)

.c.o: $(FILES) $(BONUS_FILES)
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME) : $(OBJ_FILES)
	ar rc $(NAME) $(OBJ_FILES)

bonus:
	make WITH_BONUS=1 all

clean :
	rm -rf $(FILES_OBJS) $(BONUS_OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all bonus clean fclean re
