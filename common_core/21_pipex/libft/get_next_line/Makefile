LIBNAME = libgetnl.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SOURCES = 	get_next_line_bonus.c \
			get_next_line_utils_bonus.c \

OBJECTS = $(SOURCES:.c=.o)

all: $(LIBNAME)

$(LIBNAME): $(OBJECTS)
	ar rcs $@ $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(LIBNAME)

re: fclean all

.PHONY: all clean fclean re
