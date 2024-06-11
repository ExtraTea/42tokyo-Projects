CC = cc

CFLAGS = -Wall -Werror -Wextra

BASIC_SOURCES = 	ft_atol.c \
				ft_get_argument.c \
				ft_get_median.c \
				ft_push_swap.c \
				ft_sort_array.c \
				ft_sort_case_3.c \
				ft_sort_large.c \
				ft_sort_middle.c \
				ft_sort_small.c \
				ft_stack_push.c \
				ft_stack_rotate.c \
				ft_stack_swap.c \
				ft_stack_utils.c \
				ft_utils.c \
				ft_sort_case_5.c \
				ft_stack_merge.c

BONUS_SOURCES = ft_bonus.c \
				ft_atol.c \
				ft_get_argument.c \
				ft_stack_push.c \
				ft_stack_rotate.c \
				ft_stack_swap.c \
				ft_stack_utils.c \
				ft_utils.c \
				ft_stack_merge.c

ifeq ($(BONUS_FLAG),yes)
	SOURCES = $(BONUS_SOURCES)
	NAME = checker
else
	SOURCES = $(BASIC_SOURCES)
	NAME = push_swap
endif

OBJECTS = $(SOURCES:.c=.o)

HEADERS = ft_push_swap.h

all: $(NAME)

$(NAME): $(OBJECTS) libft/libft.a
	$(CC) $(OBJECTS) -o $(NAME) libft/libft.a

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(BASIC_SOURCES:.c=.o) $(BONUS_SOURCES:.c=.o)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME) checker
	$(MAKE) -C libft fclean

re: fclean all

bonus:
	$(MAKE) all BONUS_FLAG=yes

libft.a: libft/libft.a
	cp libft/libft.a .

libft/libft.a:
	$(MAKE) -C libft

.PHONY: all clean fclean re bonus
