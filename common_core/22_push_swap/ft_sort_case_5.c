/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_case_5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:53:33 by dtakamat          #+#    #+#             */
/*   Updated: 2024/05/03 18:36:57 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_sort_case_5(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	int		arr[5];
	t_stack	*now;

	now = *stack_a;
	i = 0;
	while (now != NULL)
	{
		arr[i++] = now->num;
		now = now->next;
	}
	ft_sort_int_tab(arr, 5, compare_ints);
	i = -1;
	while (++i < 5)
	{
		if ((*stack_a)->num <= arr[1])
			ft_stack_push(stack_b, stack_a, "pb\n");
		else
			ft_stack_rotate(stack_a, "ra\n");
	}
	ft_sort_case_just_3a(stack_a);
	if ((*stack_b)->num < (*stack_b)->next->num)
		ft_stack_swap(*stack_b, "sb\n");
	ft_stack_push(stack_a, stack_b, "pa\n");
	ft_stack_push(stack_a, stack_b, "pa\n");
}
