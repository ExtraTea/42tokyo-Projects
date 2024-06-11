/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dochiai <dochiai@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:34:36 by dochiai           #+#    #+#             */
/*   Updated: 2024/02/25 14:38:08 by dochiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_error(void)
{
	write(1, "Error\n", 6);
	return (NULL);
}

char	*ft_not_file(char *file)
{
	char	buffer[4];
	int		fd;
	int		flag;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_error());
	flag = read(fd, buffer, 4);
	if (flag == -1)
		return (ft_error());
	close(fd);
	return (file);
}

char	*ft_convert_numbers(char *str_nums)
{
	int	i;

	if (!str_nums[0])
		return (ft_error());
	if (*str_nums == '+')
		str_nums++;
	i = 0;
	if (str_nums[i] == '0' && ft_strlen(str_nums) > 1)
		return (ft_error());
	while (str_nums[i])
	{
		if (str_nums[i] > '9' || str_nums[i] < '0')
			return (ft_error());
		i++;
	}
	return (str_nums);
}

char	*ft_check_arg(int argc, char **argv)
{
	if (argc == 1 || argc > 3)
		return (ft_error());
	if (argc == 2)
		return (ft_convert_numbers(argv[1]));
	if (ft_not_file(argv[1]) == NULL)
		return (NULL);
	return (ft_convert_numbers(argv[2]));
}
