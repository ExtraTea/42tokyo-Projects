/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noc_stdin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:58:41 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/27 14:58:43 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hex.h"

void	flusher_noc_stdin(t_data_c_stdin *data, char **argv)
{
	int	result;

	result = 0;
	if (result != -1)
	{
		hex_counter_noc(data->total_read - data->bytes_read);
		write(1, " ", 1);
		put_16_hexes_noc(data->bytes_read, data->buffer);
		write(1, "\n", 1);
	}
	else
		print_error(argv[0], argv[data->index - 1]);
}

void	noc_stdin(char **av)
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
		if (data.bytes_read != -1)
			data.error = 0;
		data.total_read += data.bytes_read;
		if (data.read_now == 0)
			break ;
		if (data.bytes_read < 16)
			continue ;
		flusher_noc_stdin(&data, av);
	}
	if (data.total_read == 0)
		return ;
	if (data.bytes_read)
		flusher_noc_stdin(&data, av);
	hex_counter_noc(data.total_read);
	write(1, "\n", 1);
}
