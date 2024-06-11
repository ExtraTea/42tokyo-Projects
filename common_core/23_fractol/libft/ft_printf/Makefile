LIBNAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

SOURCES = ft_printf.c \
		  ft_printf_utils.c \
		  case_char.c \
		  case_string.c \
		  case_pointer.c \
		  case_signed.c \
		  case_unsigned.c \
		  ft_putnbr.c \
		  get_format.c

BONUS_SOURCES = ft_printf_bonus.c \
				ft_printf_utils_bonus.c \
				case_char_bonus.c \
				case_string_bonus.c \
				case_pointer_bonus.c \
				case_signed_bonus.c \
				case_unsigned_bonus.c \
				ft_putnbr_bonus.c \
				get_format_bonus.c

ifeq ($(BONUS_FLAG), yes)
	OBJECTS = $(BONUS_SOURCES:.c=.o)
	RM_OBJECTS = $(SOURCES:.c=.o)
else
	OBJECTS = $(SOURCES:.c=.o)
	RM_OBJECTS = $(BONUS_SOURCES:.c=.o)
endif

ALL_OBJECTS = $(SOURCES:.c=.o) $(BONUS_SOURCES:.c=.o)

LIBRARY = libft/libft.a

all: $(LIBNAME)

$(LIBNAME): $(OBJECTS)
	$(MAKE) -C libft
	rm -f $(RM_OBJECTS)
	cp libft/libft.a $@
	ar rcs $@ $(OBJECTS)

$(LIBRARY):
	$(MAKE) -c libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -Ilibft

clean:
	rm -f $(ALL_OBJECTS)

fclean: clean
	rm -f $(LIBNAME)

re: fclean all

bonus:
	rm -f $(OBJECTS)
	$(MAKE) all BONUS_FLAG=yes

# ダミーターゲット
.PHONY: all clean fclean re libft bonus
