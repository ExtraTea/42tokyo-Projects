/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:03:56 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/27 18:03:57 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	index;
	int	is_sorted1;
	int	is_sorted2;

	index = 0;
	is_sorted1 = 1;
	is_sorted2 = 1;
	while (index < length - 1)
	{
		if (f(tab[index], tab[index + 1]) < 0)
			is_sorted1 = 0;
		index++;
	}
	index = 0;
	while (index < length - 1)
	{
		if (f(tab[index], tab[index + 1]) > 0)
			is_sorted2 = 0;
		index++;
	}
	if (is_sorted1 == 1 || is_sorted2 == 1)
		return (1);
	else
		return (0);
}

/* int	comp(int a, int b)
{
	if (a == b)
		return (0);
	else if (a > b)
		return (1);
	else
		return (-1);
}
#include <stdio.h>
int main() {
    int tab_sorted_asc[] = {1, 2, 3, 4, 3};
    int tab_sorted_desc[] = {5, 4, 3, 2, 1};
    int tab_not_sorted[] = {1, 3, 2, 5, 4};

    printf("tab is sorted: %d\n", ft_is_sort(tab_sorted_asc, 5, comp));
    printf("tab is sorted: %d\n", ft_is_sort(tab_sorted_desc, 5, comp));
    printf("tab is sorted: %d\n", ft_is_sort(tab_not_sorted, 5, comp));

    return 0;
} */
