/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_large.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:14:22 by dtakamat          #+#    #+#             */
/*   Updated: 2024/05/03 20:28:12 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_sort_large_finish(t_stack **stack_a, int elem_num)
{
	if (elem_num == 0)
		return ;
	else if (elem_num == 1)
		return ;
	else if (elem_num == 2)
	{
		if ((*stack_a)->num > (*stack_a)->next->num)
			ft_stack_swap(*stack_a, "sa\n");
		return ;
	}
	else if (elem_num == 3)
	{
		if (ft_stack_count_elem(*stack_a) == 3)
			ft_sort_case_just_3a(stack_a);
		else
			ft_sort_case_3a(stack_a);
		return ;
	}
}

void	ft_sort_large_loop(t_stack **stack_a,
			t_stack **stack_b, int e_num, int nums[3])
{
	int	i;
	int	pipots[2];

	i = 0;
	find_one_third_two_thirds_sorted(*stack_a, e_num, &pipots[0], &pipots[1]);
	while (i++ < e_num)
	{
		if ((*stack_a)->num < pipots[0])
		{
			ft_stack_push(stack_b, stack_a, "pb\n");
			ft_stack_rotate(stack_b, "rb\n");
			nums[2]++;
		}
		else if (pipots[0] <= (*stack_a)->num && (*stack_a)->num < pipots[1])
		{
			ft_stack_push(stack_b, stack_a, "pb\n");
			nums[1]++;
		}
		else
		{
			ft_stack_rotate(stack_a, "ra\n");
			nums[0]++;
		}
	}
}

void	ft_sort_large(t_stack **stack_a, t_stack **stack_b, int elem_num)
{
	int	i;
	int	nums[3];

	nums[0] = 0;
	nums[1] = 0;
	nums[2] = 0;
	if (0 <= elem_num && elem_num <= 3)
	{
		ft_sort_large_finish(stack_a, elem_num);
		return ;
	}
	if (elem_num == 5 && ft_stack_count_elem(*stack_a) == 5)
	{
		ft_sort_case_5(stack_a, stack_b);
		return ;
	}
	ft_sort_large_loop(stack_a, stack_b, elem_num, nums);
	i = -1;
	if (nums[0] != ft_stack_count_elem(*stack_a))
		while (++i < nums[0])
			ft_stack_rev_rotate(stack_a, "rra\n");
	ft_sort_large(stack_a, stack_b, nums[0]);
	ft_sort_middle(stack_a, stack_b, nums[1]);
	ft_sort_small(stack_a, stack_b, nums[2]);
	return ;
}
