/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noc_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:58:26 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/27 14:58:27 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hex.h"

void	flusher_noc_arg(t_data_c_arg data, char **argv)
{
	char	c[2];
	int		result;

	result = 0;
	if (data.error == 0)
		result = read(data.fd, c, 0);
	if (result != -1)
	{
		hex_counter_noc(data.total_read - data.bytes_read);
		write(1, " ", 1);
		put_16_hexes_noc(data.bytes_read, data.buffer);
		write(1, "\n", 1);
	}
	else
		print_error(argv[0], argv[data.index - 1]);
}

void	noc_files_init(t_data_c_arg *data)
{
	data->buffer[16] = '\0';
	data->bytes_read = 0;
	data->total_read = 0;
	data->index = 0;
	data->error = 0;
}

void	noc_files2(t_data_c_arg *data)
{
	data->bytes_read = data->bytes_read % 16;
	data->total_read -= data->bytes_read;
	data->bytes_read += read(data->fd, data->buffer
			+ data->bytes_read, 16 - data->bytes_read);
	if (data->bytes_read != -1)
		data->error++;
	data->total_read += data->bytes_read;
}

void	noc_files3(t_data_c_arg *data, char **av)
{
	if (data->total_read % 16 != 0 || data->error == 0)
		flusher_noc_arg(*data, av);
	close(data->fd);
	if (data->total_read != 0 && data->error != 0)
	{
		hex_counter_noc(data->total_read);
		write(1, "\n", 1);
	}
}

void	noc_files(int ac, char **av)
{
	t_data_c_arg	data;

	noc_files_init(&data);
	while (++data.index < ac)
	{
		data.fd = open(av[data.index], O_RDONLY);
		if (data.fd == -1)
		{
			print_error(av[0], av[data.index]);
			continue ;
		}
		while (1)
		{
			noc_files2(&data);
			if (data.bytes_read < 16)
				break ;
			flusher_noc_arg(data, av);
			data.bytes_read = 0;
		}
	}
	noc_files3(&data, av);
}
