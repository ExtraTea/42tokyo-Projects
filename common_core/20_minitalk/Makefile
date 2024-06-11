C_EXEC_FILE = client
S_EXEC_FILE = server

NAME = $(C_EXEC_FILE) $(S_EXEC_FILE)

CC = cc
CFLAGS = -Wall -Werror -Wextra

ifeq ($(BONUS_FLAG), yes)
	CLIENT_SOURCES = client.c
	SERVER_SOURCES = server.c
else
	CLIENT_SOURCES = client.c
	SERVER_SOURCES = server.c
endif

all: libft.a $(NAME)

$(C_EXEC_FILE): $(CLIENT_SOURCES)
	$(CC) $(CFLAGS) $^ -o $@ -L. -lft

$(S_EXEC_FILE): $(SERVER_SOURCES)
	$(CC) $(CFLAGS) $^ -o $@ -L. -lft

clean:
	rm -f $(C_EXEC_FILE) $(S_EXEC_FILE)

fclean: clean
	rm -rf libft.a

re: fclean all
	
bonus:
	$(MAKE) BONUS_FLAG=yes all

libft.a: libft/libft.a
	cp libft/libft.a .

libft/libft.a:
	$(MAKE) -C libft

.PHONY: all clean fclean re bonus
