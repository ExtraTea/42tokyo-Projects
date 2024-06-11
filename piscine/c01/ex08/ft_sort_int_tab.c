/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:36:26 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/08 19:36:30 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	last_index;
	int	current_index;

	last_index = size - 1;
	current_index = 0;
	while (0 <= last_index)
	{
		current_index = 0;
		while (current_index < last_index)
		{
			if (tab[current_index] > tab[current_index + 1])
				swap(&tab[current_index], &tab[current_index + 1]);
			current_index++;
		}
		last_index--;
	}
}
