/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:36:08 by dtakamat          #+#    #+#             */
/*   Updated: 2024/05/03 16:57:40 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_int_tab(int *tab, int size,
		int (*compare)(const void *, const void *))
{
	int	last_index;
	int	current_index;

	last_index = size - 1;
	while (0 <= last_index)
	{
		current_index = 0;
		while (current_index < last_index)
		{
			if (compare(&tab[current_index], &tab[current_index + 1]) > 0)
				swap(&tab[current_index], &tab[current_index + 1]);
			current_index++;
		}
		last_index--;
	}
}
