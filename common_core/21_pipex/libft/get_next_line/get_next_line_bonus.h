#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
void	ft_strlcpycat(char *dst, const char *src1,
			const char *src2, size_t dstsize);
void	*ft_mve(void *dest, const void *src, size_t n);

typedef struct s_data
{
	char	*result;
	char	*tmp;
	int		read_bytes;
	int		total_read;
	int		f_l;
	int		br_co;
}	t_data;

typedef struct s_list
{
	int				fd;
	char			buf[BUFFER_SIZE + 1];
	struct s_list	*next;
}	t_list;

#endif