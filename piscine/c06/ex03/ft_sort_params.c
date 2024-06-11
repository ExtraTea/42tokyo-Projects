/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:20:10 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/14 13:25:00 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	swap(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	ft_strcmp(char *s1, char*s2)
{
	int	index;

	index = 0;
	while (s1[index] != '\0' && s2[index] != '\0')
	{
		if (s1[index] != s2[index])
			return (s1[index] - s2[index]);
		index++;
	}
	return (s1[index] - s2[index]);
}

void	print_argv(int argc, char **argv)
{
	int	index;
	int	len;

	index = 1;
	while (index < argc)
	{
		len = 0;
		while (argv[index][len] != '\0')
			len++;
		write (1, argv[index], len);
		index++;
		write(1, "\n", 1);
	}
}

int	main(int argc, char **argv)
{
	int	index;
	int	last_index;

	index = 1;
	last_index = argc - 1;
	while (last_index >= 1)
	{
		index = 1;
		while (index < last_index)
		{
			if (ft_strcmp(argv[index], argv[index + 1]) > 0)
				swap (&argv[index], &argv[index + 1]);
			index++;
		}
		last_index--;
	}
	print_argv(argc, argv);
}
