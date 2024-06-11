NAME = philo

CC = cc

CFLAGS = -Wall -Werror -Wextra

SOURCES = 	main.c \
			cleanup.c \
			ft_atol.c \
			ft_atoi.c \
			grim.c \
			init.c \
			mutex_utils.c \
			philosopher_action.c \
			philosopher.c 

OBJECTS = $(SOURCES:.c=.o)

HEADERS = phi.h

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(SOURCES:.c=.o)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus:
	$(MAKE) all BONUS_FLAG=yes

.PHONY: all clean fclean re bonus
