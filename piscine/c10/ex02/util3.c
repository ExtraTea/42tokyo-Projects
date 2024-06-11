/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:53:11 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/22 20:53:12 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include <libgen.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

long	ft_atoi(char *str);
int		ft_strcmp(char *s1, char*s2);
int		print_error(char *name, char *f_name);
long	count_file_len(char *name, char *f_name);
int		ft_strlen(char *str);
int		proc2offset(char *name, char *f_name, int offset);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strcat(char *dest, char *src);
char	*ft_strdup(char *src, int corigin);
void	case_blank(long int offset);
int		ft_max(long int a, long int b);
int		ft_min(long int a, long int b);
long	count_file_len(char *name, char *f_name);
int		print_file(int fd);
int		case_one(long int offset, char *filename, char *execname);
int		case_more(long int offset, char *filename, char *execname, int mode);
int		print_file_multi(int fd, char *filename);
void	no_arg_error(char *execname);
int		is_invalid(char *offset);
void	illegal_arg_error(char *execname, char *offset);
int		is_number(char *c);

void	illegal_arg_error(char *execname, char *offset)
{
	const char	err[] = ": illegal offset -- ";

	write(1, basename(execname), ft_strlen(basename(execname)));
	write(1, err, 20);
	write(1, offset, ft_strlen(offset));
	write(1, "\n", 1);
}

int	is_number(char *c)
{
	int	index;

	index = 0;
	while (c[index] != 0)
	{
		if (c[index] < '0' || '9' < c[index])
			return (0);
		index++;
	}
	return (1);
}

int	case_more(long int offset, char *filename, char *execname, int mode)
{
	char	*buffer;
	long	file_length;
	long	move_length;

	buffer = (char *)malloc(sizeof (char) * (offset + 1));
	file_length = count_file_len(filename, execname);
	if (file_length == -1)
		return (0);
	move_length = file_length - offset;
	if (mode == 1)
		write(1, "\n", 1);
	print_file_multi(proc2offset(filename, execname, move_length), filename);
	return (1);
}

int	case_one(long int offset, char *filename, char *execname)
{
	char	*buffer;
	long	file_length;
	long	move_length;

	buffer = (char *)malloc(sizeof (char) * (offset + 1));
	file_length = count_file_len(filename, execname);
	if (file_length == -1)
		return (-1);
	move_length = file_length - offset;
	print_file(proc2offset(filename, execname, move_length));
	return (0);
}

int	print_file_multi(int fd, char *filename)
{
	int		flag;
	char	buffer[1024];

	flag = 1024;
	write (1, "==> ", 4);
	write (1, filename, ft_strlen(filename));
	write (1, " <==\n", 5);
	while (flag != 0)
	{
		flag = read(fd, buffer, 1024);
		if (flag == -1)
			return (0);
		else if (flag > 0)
			write(1, buffer, flag);
	}
	close(fd);
	return (0);
}
