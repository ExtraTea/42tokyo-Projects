#include "pipex.h"

char	*read_stdin_to_string(char *limiter)
{
	char	*ret;
	char	*tmp;
	int		read_bytes;
	int		total_read;
	char	buf[1024];

	read_bytes = 1;
	ret = NULL;
	while (read_bytes != 0)
	{
		ft_printf("> ");
		read_bytes = read(0, buf, 1023);
		if (read_bytes == -1)
			return ((char *)handle_error_and_free(strerror(errno), ret, ""));
		buf[read_bytes] = 0;
		if (ft_strncmp(buf, limiter, ft_strlen(limiter) + 1) == 10)
			break ;
		total_read += read_bytes;
		tmp = ret;
		ret = ft_strjoin(tmp, buf);
		free(tmp);
	}
	return (ret);
}

char	*read_file_to_string(int fd, char *filename)
{
	char	*ret;
	char	*tmp;
	int		read_bytes;
	int		total_read;
	char	buf[1024];

	if (fd == -1)
		return (NULL);
	read_bytes = 1;
	ret = NULL;
	while (read_bytes != 0)
	{
		read_bytes = read(fd, buf, 1023);
		if (read_bytes == -1)
			return ((char *)handle_error_and_free(strerror(errno), ret, filename));
		buf[read_bytes] = 0;
		total_read += read_bytes;
		tmp = ret;
		ret = ft_strjoin(tmp, buf);
		free(tmp);
	}
	close(fd);
	return (ret);
}

int	open_file_readonly(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		handle_error_and_free(strerror(errno), NULL, filename);
		return (-1);
	}
	return (fd);
}
