/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:20:46 by dtakamat          #+#    #+#             */
/*   Updated: 2024/05/03 19:45:54 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_sort_small_case_3(t_stack **stack_b)
{
	int	num[3];

	num[0] = (*stack_b)->num;
	num[1] = (*stack_b)->next->num;
	num[2] = (*stack_b)->next->next->num;
	if (num[2] < num[0] && num[0] < num[1])
		ft_stack_swap(*stack_b, "sb\n");
	else if (num[0] < num[2] && num[2] < num[1])
		ft_stack_swap(*stack_b, "sb\n");
}

void	ft_sort_small_finish(t_stack **stack_a, t_stack **stack_b, int elem_num)
{
	if (elem_num == 1)
	{
		ft_stack_rev_rotate(stack_b, "rrb\n");
		ft_stack_push(stack_a, stack_b, "pa\n");
	}
	else if (elem_num == 2)
	{
		ft_stack_rev_rotate(stack_b, "rrb\n");
		ft_stack_rev_rotate(stack_b, "rrb\n");
		ft_stack_push(stack_a, stack_b, "pa\n");
		ft_stack_push(stack_a, stack_b, "pa\n");
		if ((*stack_a)->num > (*stack_a)->next->num)
			ft_stack_swap(*stack_a, "sa\n");
	}
	else if (elem_num == 3)
	{
		ft_stack_rev_rotate(stack_b, "rrb\n");
		ft_stack_rev_rotate(stack_b, "rrb\n");
		ft_stack_rev_rotate(stack_b, "rrb\n");
		ft_sort_small_case_3(stack_b);
		ft_stack_push(stack_a, stack_b, "pa\n");
		ft_stack_push(stack_a, stack_b, "pa\n");
		ft_stack_push(stack_a, stack_b, "pa\n");
		ft_sort_case_3a(stack_a);
	}
}

void	ft_sort_small_loop(t_stack **stack_a, t_stack **stack_b,
		int elem_num, int nums[3])
{
	int		i;
	int		pipots[2];
	t_stack	*b_bottom;

	i = 0;
	find_median_sorted_from_end(
		ft_stack_get_bottom(*stack_b), elem_num, &pipots[0]);
	while (i < elem_num)
	{
		b_bottom = ft_stack_get_bottom(*stack_b);
		if (b_bottom->num < pipots[0])
		{
			nums[0]++;
			ft_stack_rev_rotate(stack_b, "rrb\n");
		}
		else
		{
			b_bottom = b_bottom ->prev;
			ft_stack_rev_rotate(stack_b, "rrb\n");
			ft_stack_push(stack_a, stack_b, "pa\n");
			nums[1]++;
		}
		i++;
	}
}

void	ft_sort_small(t_stack **stack_a, t_stack **stack_b, int elem_num)
{
	int	nums[3];

	nums[0] = 0;
	nums[1] = 0;
	nums[2] = 0;
	if (0 <= elem_num && elem_num <= 3)
	{
		ft_sort_small_finish(stack_a, stack_b, elem_num);
		return ;
	}
	ft_sort_small_loop(stack_a, stack_b, elem_num, nums);
	ft_sort_large(stack_a, stack_b, nums[1]);
	ft_sort_middle(stack_a, stack_b, nums[0]);
}
