/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinkpad-wsl <thinkpad-wsl@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 22:05:36 by dtakamat          #+#    #+#             */
/*   Updated: 2024/05/07 14:12:51 by thinkpad-ws      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	locate_char(char c, char *s)
{
	int	i;

	i = -1;
	while (s[++i] != 0)
		if (s[i] == c)
			return (i);
	return (i);
}

char	*init_data(t_data *data)
{
	if (BUFFER_SIZE <= 0)
		return (NULL);
	data->total_read = 0;
	data->result = (char *)malloc(1);
	if (data->result == NULL)
		return (NULL);
	data->result[0] = 0;
	return (data->result);
}

int	move_2_result(t_data *data, char *buf)
{
	data->f_l = locate_char('\n', buf);
	if ((buf)[data->f_l] == '\n')
		data->total_read += data->f_l + 1;
	else
		data->total_read += data->f_l;
	data->tmp = data->result;
	data->result = (char *)malloc(data->total_read + 1);
	if (data->result == NULL)
	{
		free(data->tmp);
		return (-1);
	}
	ft_strlcpycat(data->result, data->tmp, buf, data->total_read + 1);
	free(data->tmp);
	return (0);
}

int	reload_buf(t_data *data, char *buf, int fd)
{
	if (data->total_read == 0 || data->result[data->total_read - 1] != '\n')
	{
		data->read_bytes = read(fd, buf, BUFFER_SIZE);
		if (data->read_bytes == -1)
		{
			free(data->result);
			return (-1);
		}
		if (data->read_bytes == 0)
		{
			if (data->result[0] == 0)
			{
				free(data->result);
				return (-1);
			}
			buf[0] = 0;
			return (1);
		}
		buf[data->read_bytes] = 0;
		return (2);
	}
	else
		if (ft_mve(buf, buf + (data->f_l + 1), BUFFER_SIZE - data->f_l) || 1)
			return (1);
}

char	*get_next_line(int fd)
{
	t_data		data;
	static char	buf[BUFFER_SIZE + 1] = {0};

	if (fd < 0 || 10240 <= fd || init_data(&data) == NULL)
		return (NULL);
	while (1)
	{
		if (move_2_result(&data, buf) == -1)
			return (NULL);
		data.br_co = reload_buf(&data, buf, fd);
		if (data.br_co == 1)
			break ;
		else if (data.br_co == 2)
			continue ;
		else
			return (NULL);
	}
	return (data.result);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	*line;
// 	int		i;
// 	int		fd1;

// 	fd1 = open("test.txt", O_RDONLY);
// 	i = 1;
// 	while (i < 7)
// 	{
// 		line = get_next_line(fd1);
// 		printf("line [%02d]: %s", i, line);
// 		free(line);
// 		i++;
// 	}
// 	close(fd1);
// 	return (0);
// }