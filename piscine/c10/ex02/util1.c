/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:53:00 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/22 20:53:02 by dtakamat         ###   ########.fr       */
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

char	*ft_strcpy(char *dest, char *src)
{
	int	index;

	index = 0;
	while (src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	return (dest);
}

char	*ft_strcat(char *dest, char *src)
{
	int	index;
	int	srcindex;

	index = 0;
	while (dest[index] != '\0')
		index++;
	srcindex = 0;
	while (src[srcindex] != '\0')
	{
		dest[index] = src[srcindex];
		index++;
		srcindex++;
	}
	dest[index] = '\0';
	return (dest);
}

long int	ft_atoi(char *str)
{
	long int	index;
	long int	sign;
	long int	num;

	index = 0;
	sign = 1;
	num = 0;
	while (str[index] == ' ' || (9 <= str[index] && str[index] <= 13))
		index++;
	while (str[index] == '+' || str[index] == '-')
	{
		if (str[index] == '-')
			sign *= -1;
		index++;
	}
	while ('0' <= str[index] && str[index] <= '9')
	{
		num *= 10;
		num += sign * (str[index] - '0');
		index++;
	}
	return (num);
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

char	*ft_strdup(char *src, int corigin)
{
	char	*dest;
	int		len;
	int		index;

	len = 0;
	while (src[len] != 0)
		len++;
	dest = (char *) malloc((corigin + 1) * sizeof (char));
	index = 0;
	while (index < len)
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}
