/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_middle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:18:17 by dtakamat          #+#    #+#             */
/*   Updated: 2024/05/03 17:18:18 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_sort_middle_finish(t_stack **stack_a,
			t_stack **stack_b, int elem_num)
{
	if (elem_num == 0)
		return ;
	else if (elem_num == 1)
	{
		ft_stack_push(stack_a, stack_b, "pa\n");
		return ;
	}
	else if (elem_num == 2)
	{
		if ((*stack_b)->num < (*stack_b)->next->num)
			ft_stack_swap(*stack_b, "sb\n");
		ft_stack_push(stack_a, stack_b, "pa\n");
		ft_stack_push(stack_a, stack_b, "pa\n");
		return ;
	}
	else if (elem_num == 3)
	{
		ft_stack_push(stack_a, stack_b, "pa\n");
		ft_stack_push(stack_a, stack_b, "pa\n");
		ft_stack_push(stack_a, stack_b, "pa\n");
		ft_sort_case_3a(stack_a);
		return ;
	}
}

void	ft_sort_middle_loop(t_stack **stack_a,
			t_stack **stack_b, int elem_num, int nums[3])
{
	int	pipots[2];
	int	i;

	i = 0;
	find_median_sorted(*stack_b, elem_num, &pipots[0]);
	while (i < elem_num)
	{
		if ((*stack_b)->num < pipots[0])
		{
			ft_stack_rotate(stack_b, "rb\n");
			nums[0]++;
		}
		else
		{
			ft_stack_push(stack_a, stack_b, "pa\n");
			nums[1]++;
		}
		i++;
	}
}

void	ft_sort_middle(t_stack **stack_a, t_stack **stack_b, int elem_num)
{
	int	nums[3];

	nums[0] = 0;
	nums[1] = 0;
	nums[2] = 0;
	if (0 <= elem_num && elem_num <= 3)
	{
		ft_sort_middle_finish(stack_a, stack_b, elem_num);
		return ;
	}
	ft_sort_middle_loop(stack_a, stack_b, elem_num, nums);
	ft_sort_large(stack_a, stack_b, nums[1]);
	ft_sort_small(stack_a, stack_b, nums[0]);
	return ;
}
