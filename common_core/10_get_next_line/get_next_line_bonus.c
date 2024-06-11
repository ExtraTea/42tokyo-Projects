/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 22:05:33 by dtakamat          #+#    #+#             */
/*   Updated: 2024/04/19 13:54:41 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	locate_char(char c, char *s)
{
	int	i;

	i = -1;
	while (s[++i] != 0)
		if (s[i] == c)
			return (i);
	return (i);
}

char	*init_data(t_data *data, char **buf)
{
	if (BUFFER_SIZE <= 0)
		return (NULL);
	data->total_read = 0;
	data->result = (char *)malloc(1);
	if (data->result == NULL)
		return (NULL);
	if (*buf == NULL)
	{
		*buf = (char *)malloc(sizeof (char) * (BUFFER_SIZE + 1));
		if (*buf == NULL)
		{
			free(data->result);
			return (NULL);
		}
		(*buf)[0] = 0;
	}
	data->result[0] = 0;
	return (data->result);
}

int	move_2_result(t_data *data, char **buf)
{
	data->f_l = locate_char('\n', *buf);
	if ((*buf)[data->f_l] == '\n')
		data->total_read += data->f_l + 1;
	else
		data->total_read += data->f_l;
	data->tmp = data->result;
	data->result = (char *)malloc(data->total_read + 1);
	if (data->result == NULL)
	{
		free(*buf);
		*buf = NULL;
		free(data->tmp);
		return (-1);
	}
	ft_strlcpycat(data->result, data->tmp, *buf, data->total_read + 1);
	free(data->tmp);
	return (0);
}

int	reload_buf(t_data *data, char **buf, int fd)
{
	if (data->total_read == 0 || data->result[data->total_read - 1] != '\n')
	{
		data->read_bytes = read(fd, *buf, BUFFER_SIZE);
		if (data->read_bytes == -1)
			return (-1);
		if (data->read_bytes == 0)
		{
			if (data->result[0] == 0)
				return (-1);
			(*buf)[0] = 0;
			free(*buf);
			*buf = NULL;
			return (1);
		}
		(*buf)[data->read_bytes] = 0;
		return (2);
	}
	else
		if (ft_mve(*buf, *buf + (data->f_l + 1), BUFFER_SIZE - data->f_l) || 1)
			return (1);
}

char	*get_next_line(int fd)
{
	t_data		data;
	static char	*buf[OPEN_MAX];

	if (fd < 0 || OPEN_MAX <= fd)
		return (NULL);
	if (init_data(&data, &(buf[fd])) == NULL)
		return (NULL);
	while (1)
	{
		if (move_2_result(&data, &(buf[fd])) == -1)
			return (NULL);
		data.br_co = reload_buf(&data, &(buf[fd]), fd);
		if (data.br_co == 1)
			break ;
		else if (data.br_co == 2)
			continue ;
		else
		{
			free(data.result);
			free(buf[fd]);
			buf[fd] = NULL;
			return (NULL);
		}
	}
	return (data.result);
}

/* #include <stdio.h>
int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;

	fd1 = open("test.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	fd3 = open("test3.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd2);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd3);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
} */