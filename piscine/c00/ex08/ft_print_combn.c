/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:07:31 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/09 21:34:01 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	my_strcmp(char *str1, const char *str2)
{
	int	i;

	i = 0;
	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	if (str1[i] == '\0' && str2[i] == '\0')
		return (1);
	else
		return (0);
}

int	is_end(char *num, int nn)
{
	const char	end[10][11] = {
		"",
		"9000000000\0",
		"8900000000\0",
		"7890000000\0",
		"6789000000\0",
		"5678900000\0",
		"4567890000\0",
		"3456789000\0",
		"2345678900\0",
		"1234567890\0"
	};

	if (my_strcmp(num, end[nn]) == 1)
	{
		return (1);
	}
	return (0);
}

void	ft_recursive_combn(char *hist, int prev, int depth, int max_depth)
{
	char	digit;
	int		index;

	if (depth == max_depth)
	{
		write(1, hist, max_depth);
		if (is_end(hist, max_depth) != 1)
			write(1, ", ", 2);
		return ;
	}
	index = prev + 1;
	while (index <= 10 - max_depth + depth)
	{
		digit = '0' + index;
		hist[depth] = digit;
		ft_recursive_combn(hist, index, depth + 1, max_depth);
		if (depth == 0 && index == 10 - max_depth)
			break ;
		index++;
	}
}

void	ft_print_combn(int n)
{	
	char	hist[11];
	int		index;

	index = 0;
	while (index < 10)
	{
		hist[index] = '0';
		index++;
	}
	hist[10] = '\0';
	ft_recursive_combn(hist, -1, 0, n);
}
