NAME = fractol

CC = cc

CFLAGS = -Wall -Werror -Wextra

SOURCES = 	ft_fractol.c \
			ft_coloring.c \
			ft_julia.c \
			ft_mandelbrot.c \
			ft_burning.c \
			ft_hook.c \

OBJECTS = $(SOURCES:.c=.o)

HEADERS = fractol.h

all: $(NAME)

$(NAME): $(OBJECTS) libft/libft.a
	$(CC) $(OBJECTS) -Imlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) libft/libft.a

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@ -Imlx

clean:
	rm -f $(SOURCES:.c=.o)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

bonus:
	$(MAKE) all BONUS_FLAG=yes

libft.a: libft/libft.a
	cp libft/libft.a .

libft/libft.a:
	$(MAKE) -C libft

.PHONY: all clean fclean re bonus
