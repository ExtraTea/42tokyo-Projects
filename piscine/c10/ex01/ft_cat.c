/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 22:51:02 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/20 22:51:04 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <libgen.h>

int	case_blank(void);
int	ft_strlen(char *str);
int	print_file(char *name, char *f_name);

int	main(int argc, char **argv)
{
	int	index;
	int	err_value;

	err_value = 0;
	if (argc == 1)
		case_blank();
	else if (argc > 1)
	{
		index = 1;
		while (index < argc)
		{
			if (ft_strlen(argv[index]) == 1 && argv[index][0] == '-')
				err_value += case_blank();
			else
				err_value += print_file(argv[0], argv[index]);
			index++;
		}
	}
	if (err_value > 0)
		return (1);
	else
		return (0);
}

int	print_error(char *name, char *f_name)
{
	write(2, basename(name), ft_strlen(basename(name)));
	write(2, ": ", 2);
	write(2, f_name, ft_strlen(f_name));
	write(2, ": ", 2);
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	write(2, "\n", 1);
	return (1);
}

int	print_file(char *name, char *f_name)
{
	int		fd;
	int		flag;
	char	buffer[1024];

	fd = open(f_name, O_RDONLY);
	if (fd == -1)
		return (print_error(name, f_name));
	flag = 1024;
	while (flag != 0)
	{
		flag = read(fd, buffer, 1024);
		if (flag == -1)
			return (print_error(name, f_name));
		else if (flag > 0)
			write(1, buffer, flag);
	}
	close(fd);
	return (0);
}

int	case_blank(void)
{
	char			buffer[1024];
	unsigned int	bytes_read;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(STDIN_FILENO, buffer, 1024);
		if (bytes_read < 0)
			return (-1);
		else if (bytes_read == 0)
			break ;
		else
			write(1, buffer, bytes_read);
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	if (str[0] != '\0')
	{
		count = ft_strlen(&str[1]) + 1;
	}
	return (count);
}
