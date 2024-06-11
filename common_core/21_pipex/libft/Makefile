# ライブラリ名（出力ファイル名）
LIBNAME = libft.a

# コンパイラ
CC = gcc

# コンパイル時のオプション
CFLAGS = -Wall -Werror -Wextra

# ソースディレクトリ
SUBDIRS = libft ft_printf get_next_line

# 静的ライブラリのパス
LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a
GETNL = get_next_line/libgetnl.a
LIBRARIES = $(LIBFT) $(PRINTF) $(GETNL)

# デフォルトターゲット
all: $(LIBNAME)

# 静的ライブラリを合成
$(LIBNAME): subs $(LIBRARIES)
	rm -f $@
	ar -cqT $@ $(LIBRARIES)
	ranlib $@

# 各サブディレクトリのビルドを強制実行
subs:
	$(MAKE) -C libft
	$(MAKE) -C ft_printf
	$(MAKE) -C get_next_line

# 'make clean' と 'make fclean' を実行したときにサブディレクトリの掃除も行う
clean fclean:
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir $@; \
	done
	rm -f $(LIBNAME)

re: fclean all

bonus: all

# ダミーターゲット
.PHONY: all clean fclean re bonus subs
