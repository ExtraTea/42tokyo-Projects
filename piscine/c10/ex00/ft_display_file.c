/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:19:10 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/20 17:19:11 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int	is_arg_error(int argc)
{
	if (argc == 1)
	{
		write(2, "File name missing.\n", 19);
		return (-1);
	}
	else if (argc > 2)
	{
		write(2, "Too many arguments.\n", 20);
		return (-1);
	}
	else
		return (0);
}

int	main(int argc, char **argv)
{
	char	buffer[1024];
	int		fd;
	int		flag;

	if (is_arg_error(argc) == -1)
		return (-1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		write (2, "Cannot read file.\n", 18);
		return (-1);
	}
	flag = 1024;
	while (flag != 0)
	{
		flag = read(fd, buffer, 1024);
		if (flag > 0)
			write(1, buffer, flag);
		else if (flag == -1)
		{
			write (2, "\n", 1);
			return (-1);
		}
	}
	close(fd);
}
