/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 20:02:39 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/27 20:02:40 by dtakamat         ###   ########.fr       */
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

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
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
			if (cmp(tab[index], tab[index + 1]) > 0)
				swap (&tab[index], &tab[index + 1]);
			index++;
		}
		last_index--;
	}
}

/* #include <stdio.h>

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
	char *tab[] = {"banana", "apple", "orange", "mango", 0};

	printf("Before sorting:\n");
	print_strs(tab);

	ft_advanced_sort_string_tab(tab, &ft_strcmp);

	printf("After sorting:\n");
	print_strs(tab);

	return (0);
} */
