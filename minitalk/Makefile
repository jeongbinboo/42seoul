CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = server \
	   client
	   
SERVER_SRCS = server.c
CLIENT_SRCS = client.c ft_atoi.c ft_strjoin.c

SERVER_OBJS = server.o
CLIENT_OBJS = client.o ft_atoi.o ft_strjoin.o

LIB_DIR = ./ft_printf
LIB_NAME = libftprintf
LIB = $(LIB_DIR)/$(LIB_NAME).a

all: $(NAME)

server: $(SERVER_OBJS) $(LIB)
	$(CC) $(CFLAGS) -o $@ $^

client: $(CLIENT_OBJS) $(LIB)
	$(CC) $(CFLAGS) -o $@ $^

	
$(LIB):
	make -C $(LIB_DIR)

clean:
	rm -f $(SERVER_OBJS)
	rm -f $(CLIENT_OBJS)
	make -C $(LIB_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIB_DIR) fclean

re: fclean all

.PHONY: fclean all clean re