/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_stdin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:57:57 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/27 14:57:58 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hex.h"

void	flusher_c_stdin(t_data_c_stdin *data, char **argv)
{
	int	result;

	result = 0;
	if (result != -1)
	{
		hex_counter(data->total_read - data->bytes_read);
		write(1, "  ", 2);
		put_16_hexes(data->bytes_read, data->buffer);
		write_raw_ascii(data->bytes_read, data->buffer);
		write(1, "\n", 1);
	}
	else
		print_error(argv[0], argv[data->index - 1]);
}

void	c_stdin_init(t_data_c_stdin *data)
{
	data->buffer[16] = '\0';
	data->bytes_read = 0;
	data->total_read = 0;
	data->index = 0;
}

void	c_stdin(char **av)
{
	t_data_c_stdin	data;

	c_stdin_init(&data);
	while (1)
	{
		data.bytes_read %= 16;
		data.total_read -= data.bytes_read;
		data.read_now = read(STDIN_FILENO, data.buffer
				+ data.bytes_read, 16 - data.bytes_read);
		data.bytes_read += data.read_now;
		if (data.read_now != -1)
			data.error = 0;
		data.total_read += data.bytes_read;
		if (data.read_now == 0)
			break ;
		if (data.bytes_read < 16)
			continue ;
		flusher_c_stdin(&data, av);
	}
	if (data.total_read == 0)
		return ;
	if (data.bytes_read)
		flusher_c_stdin(&data, av);
	hex_counter(data.total_read);
	write(1, "\n", 1);
}
