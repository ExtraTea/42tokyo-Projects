/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:54:42 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/27 19:54:43 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_sort_string_tab(char **tab)
{
	int	index;
	int	len;
	int	last_index;

	len = 0;
	while (tab[len] != 0)
		len++;
	index = 0;
	last_index = len - 1;
	while (last_index >= 1)
	{
		index = 0;
		while (index < last_index)
		{
			if (ft_strcmp(tab[index], tab[index + 1]) > 0)
				swap (&tab[index], &tab[index + 1]);
			index++;
		}
		last_index--;
	}
}

/* #include <unistd.h>
#include <stdio.h>

// ここにswap関数を貼り付けます
// ここにft_strcmp関数を貼り付けます
// ここにft_sort_string_tab関数を貼り付けます

void	print_strs(char **tab)
{
	while (*tab != 0)
	{
		printf("%s\n", *tab);
		tab++;
	}
}

int	main(void)
{
	char *tab[] = {"banana", "apple", "orange", "Mango", 0};

	printf("Before sorting:\n");
	print_strs(tab);

	ft_sort_string_tab(tab);

	printf("After sorting:\n");
	print_strs(tab);

	return (0);
} */
