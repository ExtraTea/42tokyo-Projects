/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:53:06 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/22 20:53:07 by dtakamat         ###   ########.fr       */
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

long	count_file_len(char *name, char *f_name)
{
	int		fd;
	int		result;
	long	len;
	char	buffer[1029];

	fd = open(name, O_RDONLY);
	if (fd == -1)
		return (print_error(f_name, name));
	len = 0;
	while (1)
	{
		result = read(fd, buffer, 1024);
		if (result == -1)
			return (print_error(f_name, name));
		len += result;
		if (result == 0)
			break ;
	}
	close(fd);
	return (len);
}

int	proc2offset(char *name, char *f_name, int offset)
{
	int	mod_div[2];
	int	fd;
	int	trash[1025];
	int	index;

	mod_div[0] = offset % 1024;
	mod_div[1] = offset / 1024;
	fd = open(name, O_RDONLY);
	if (fd == -1)
		return (print_error(f_name, name));
	read(fd, trash, mod_div[0]);
	index = 0;
	while (index < mod_div[1])
	{
		read(fd, trash, 1024);
		index++;
	}
	return (fd);
}

void	case_blank(long int offset)
{
	long	bytes_r;
	char	*buffer;
	char	*result;

	buffer = (char *)malloc(sizeof (char) * (offset + 4));
	result = (char *)malloc(sizeof (char) * (offset + 4));
	bytes_r = 1;
	result[0] = '\0';
	while (bytes_r > 0)
	{
		bytes_r = read(STDIN_FILENO, buffer, offset);
		buffer[bytes_r] = '\0';
		result = ft_strdup(result + ft_min((ft_max((ft_strlen(result)
								+ bytes_r), offset) - offset), offset), offset);
		ft_strcat(result, buffer);
		result[offset] = '\0';
		if (bytes_r == 0)
			break ;
	}
	write(1, result, ft_strlen(result));
}

int	ft_max(long int a, long int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

int	ft_min(long int a, long int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}
