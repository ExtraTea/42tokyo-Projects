# ライブラリ名（出力ファイル名）
LIBNAME = libft.a

# コンパイラ
CC = gcc

# コンパイル時のオプション
CFLAGS = -Wall -Werror -Wextra

# ソースファイル (*.c) のリスト
SOURCES = 	ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \

BONUSES =	ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \


# オブジェクトファイル (*.o) のリストを生成
OBJECTS = $(SOURCES:.c=.o)

BONUS_OBJECTS = $(BONUSES:.c=.o)

# デフォルトターゲット
all: $(LIBNAME)

# 静的ライブラリを作成
$(LIBNAME): $(OBJECTS) $(BONUS_OBJECTS)
	ar rcs $@ $(OBJECTS) $(BONUS_OBJECTS)

# ソースファイルからオブジェクトファイルをコンパイル
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# 'make clean' を実行した時に掃除する
clean:
	rm -f $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	rm -f $(LIBNAME)

re: fclean all

bonus: $(OBJECTS) $(BONUS_OBJECTS)
	ar rcs $(LIBNAME) $^

# ダミーターゲット
.PHONY: all clean fclean re bonus
