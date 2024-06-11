SRCS = dicterror1.c ft_atoa.c ft_atoi.c ft_check_arg.c \
	ft_itoa.c ft_split.c ft_strcmp.c ft_strdup.c ft_strlcpy.c \
	ft_strlen.c ft_strncmp.c list_util2.c list_util3.c \
	list_utils.c main.c util1.c write1.c write2.c
NAME = rush-02
INC = includes
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	cc $(CFLAGS) $(SRCS) -o $(NAME) -I $(INC)

clean:

fclean:
	rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re
