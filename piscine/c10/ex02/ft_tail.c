/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:52:52 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/22 20:52:53 by dtakamat         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	int	index;
	int	first;

	if (argc == 2)
		no_arg_error(argv[0]);
	else if (is_number(argv[2]) == 0)
		illegal_arg_error(argv[0], argv[2]);
	else if (argc == 3)
		case_blank(ft_atoi(argv[2]));
	else if (argc == 4)
		case_one(ft_atoi(argv[2]), argv[3], argv[0]);
	else if (argc > 4)
	{
		index = 3;
		first = 0;
		while (index < argc)
		{
			if (first == 0)
				first += case_more(ft_atoi(argv[2]), argv[index++], argv[0], 0);
			else
				first += case_more(ft_atoi(argv[2]), argv[index++], argv[0], 1);
		}
	}
}

void	no_arg_error(char *execname)
{
	const char	err1[] = ": option requires an argument -- c\nusage: tail [-F ";
	const char	err2[] = "| -f | -r] [-q] [-b # | -c # | -n #] [file ...]\n";

	write(1, basename(execname), ft_strlen(basename(execname)));
	write(1, err1, 51);
	write(1, err2, 48);
}

int	print_error(char *name, char *f_name)
{
	write(2, basename(name), ft_strlen(basename(name)));
	write(2, ": ", 2);
	write(2, f_name, ft_strlen(f_name));
	write(2, ": ", 2);
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	write(2, "\n", 1);
	return (-1);
}

int	print_file(int fd)
{
	int		flag;
	char	buffer[1024];

	flag = 1024;
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
