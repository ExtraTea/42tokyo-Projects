/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_median.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:48:51 by dtakamat          #+#    #+#             */
/*   Updated: 2024/05/03 18:35:19 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	compare_ints(const void *a, const void *b)
{
	int	arg1;
	int	arg2;

	arg1 = *(const int *)a;
	arg2 = *(const int *)b;
	return ((arg1 > arg2) - (arg1 < arg2));
}

void	find_one_third_two_thirds_sorted(t_stack *head, int num_elements,
			int *one_third_value, int *two_thirds_value)
{
	int		*values;
	t_stack	*current;
	int		i;
	int		one_third_position;
	int		two_thirds_position;

	values = (int *)malloc(num_elements * sizeof(int));
	if (!values)
		exit(EXIT_FAILURE);
	current = head;
	i = 0;
	while (current != NULL && i < num_elements)
	{
		values[i++] = current->num;
		current = current->next;
	}
	ft_sort_int_tab(values, num_elements, compare_ints);
	one_third_position = num_elements / 3;
	two_thirds_position = 2 * num_elements / 3;
	*one_third_value = values[one_third_position];
	*two_thirds_value = values[two_thirds_position];
	free(values);
}

void	find_median_sorted(t_stack *head, int elem_num, int *median)
{
	int		i;
	int		count;
	t_stack	*current;
	int		*values;

	count = 0;
	current = head;
	while (current != NULL && count < elem_num)
	{
		count++;
		current = current->next;
	}
	values = (int *)malloc(count * sizeof(int));
	if (!values)
		exit(EXIT_FAILURE);
	current = head;
	i = 0;
	while (i < count)
	{
		values[i++] = current->num;
		current = current->next;
	}
	ft_sort_int_tab(values, count, compare_ints);
	*median = values[count / 2];
	free(values);
}

void	find_median_sorted_from_end(t_stack *last, int elem_num, int *median)
{
	int		i;
	int		count;
	t_stack	*current;
	int		*values;

	count = 0;
	current = last;
	while (current != NULL && count < elem_num)
	{
		count++;
		current = current->prev;
	}
	values = (int *)malloc(count * sizeof(int));
	if (!values)
		exit(EXIT_FAILURE);
	current = last;
	i = 0;
	while (i < count)
	{
		values[i++] = current->num;
		current = current->prev;
	}
	ft_sort_int_tab(values, count, compare_ints);
	*median = values[count / 2];
	free(values);
}
