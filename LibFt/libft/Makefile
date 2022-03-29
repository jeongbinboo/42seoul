CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME=libft.a
FILES = ft_isprint.c \
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
		
FILES_OBJS=$(FILES:.c=.o)

all : $(NAME)

$(NAME) : $(FILES_OBJS)
	ar rc $(NAME) $(FILES_OBJS)
 
%.o : %.c
	$(CC) $(CFLAGS) -c $<

clean :
	rm -rf $(FILES_OBJS)

fclean :
	rm -rf $(NAME) $(FILES_OBJS)

re :
	fclean all
