/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:58:04 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/27 14:58:06 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEX_H
# define FT_HEX_H

# include <errno.h>
# include <string.h>
# include <libgen.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_data_c_stdin
{
	int		bytes_read;
	int		total_read;
	int		read_now;
	int		index;
	int		error;
	char	buffer[17];
}	t_data_c_stdin;

typedef struct s_data_c_arg
{
	int		bytes_read;
	int		total_read;
	int		index;
	int		fd;
	int		error;
	char	buffer[17];
}	t_data_c_arg;

int		ft_strlen(char *str);
void	hex_counter(long int count);
void	put_hex(char c);
void	put_16_hexes(int count, char *buf);
void	write_raw_ascii(int count, char *buf);
int		print_error(char *name, char *f_name);
void	c_stdin(char **av);
void	c_files(int ac, char **av);
int		ft_strcmp(char *s1, char*s2);
void	noc_files(int ac, char **av);
void	noc_stdin(char **av);
void	hex_counter_noc(long int count);
void	put_16_hexes_noc(int count, char *buf);
void	c_stdin_init(t_data_c_stdin *data);

#endif
