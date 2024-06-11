# ライブラリ名（出力ファイル名）
LIBNAME = libftprintf.a

# コンパイラ
CC = gcc

# コンパイル時のオプション
CFLAGS = -Wall -Werror -Wextra

# ソースファイル (*.c) のリスト
SOURCES = ft_printf.c \
		  ft_printf_utils.c \
		  case_char.c \
		  case_string.c \
		  case_pointer.c \
		  case_signed.c \
		  case_unsigned.c \
		  ft_putnbr.c \
		  get_format.c

# オブジェクトファイル (*.o) のリストを生成
OBJECTS = $(SOURCES:.c=.o)

LIBRARY = ../libft/libft.a

# デフォルトターゲット
all: $(LIBNAME)

# 静的ライブラリを作成
$(LIBNAME): $(OBJECTS)
	ar rcs $@ $(OBJECTS)

# libftのビルド
$(LIBRARY): ../libft/Makefile ../libft/*.c ../libft/*.h
	$(MAKE) -C ../libft
	
# ソースファイルからオブジェクトファイルをコンパイル
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I../libft

# 'make clean' を実行した時に掃除する
clean:
	$(MAKE) -C ../libft clean
	rm -f $(OBJECTS)

fclean: clean
	$(MAKE) -C ../libft fclean
	rm -f $(LIBNAME)

re: fclean all

bonus: all

# ダミーターゲット
.PHONY: all clean fclean re libft bonus
