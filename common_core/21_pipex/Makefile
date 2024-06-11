EXECFILE = pipex

# コンパイラ
CC = gcc

# コンパイル時のオプション
CFLAGS = -Wall -Werror -Wextra

# ソースファイル (*.c) のリスト
SOURCES =	pipex.c \
			path_finder.c \
			handle_error.c \
			free_utils.c \
			fileio.c \
			command_exec.c \
			ft_split_mod.c

# オブジェクトファイル (*.o) のリスト
OBJECTS = $(SOURCES:.c=.o)

# ヘッダーファイルのディレクトリ
INCLUDES = -Ilibft -Ift/ft_printf -Iget_next_line

# ライブラリファイル
LIBFT = libft/libft.a
LIBRARIES = -Llibft -lft

# 実行ファイル生成ターゲット
all: $(EXECFILE)

# 実行ファイルのリンク
$(EXECFILE): $(OBJECTS) $(LIBFT)
	$(CC) $(OBJECTS) -o $@ $(LIBRARIES)

# オブジェクトファイルの生成
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# libftのビルド
$(LIBFT):
	$(MAKE) -C libft

# 'make clean' を実行した時に掃除する
clean:
	$(MAKE) -C libft clean
	rm -f $(OBJECTS)

fclean: clean
	$(MAKE) -C libft fclean
	rm -f $(EXECFILE)

re: fclean all

bonus: all

# ダミーターゲット
.PHONY: all clean fclean re bonus
