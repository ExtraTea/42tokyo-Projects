/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_case_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:58:40 by dtakamat          #+#    #+#             */
/*   Updated: 2024/05/03 16:58:40 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_sort_case_just_3a(t_stack **stack)
{
	int	num[3];

	num[0] = (*stack)->num;
	num[1] = (*stack)->next->num;
	num[2] = (*stack)->next->next->num;
	if (num[0] < num[2] && num[2] < num[1])
	{
		ft_stack_rev_rotate(stack, "rra\n");
		ft_stack_swap(*stack, "sa\n");
	}
	else if (num[2] < num[0] && num[0] < num[1])
		ft_stack_rev_rotate(stack, "rra\n");
	else if (num[1] < num[0] && num[0] < num[2])
		ft_stack_swap(*stack, "sa\n");
	else if (num[1] < num[2] && num[2] < num[0])
		ft_stack_rotate(stack, "ra\n");
	else if (num[2] < num[1] && num[1] < num[0])
	{
		ft_stack_swap(*stack, "sa\n");
		ft_stack_rev_rotate(stack, "rra\n");
	}
}

void	ft_sort_rsrra(t_stack **stack)
{
	ft_stack_rotate(stack, "ra\n");
	ft_stack_swap(*stack, "sa\n");
	ft_stack_rev_rotate(stack, "rra\n");
}

void	ft_sort_case_3a(t_stack **stack)
{
	int	num[3];

	num[0] = (*stack)->num;
	num[1] = (*stack)->next->num;
	num[2] = (*stack)->next->next->num;
	if (num[0] < num[2] && num[2] < num[1])
		ft_sort_rsrra(stack);
	else if (num[2] < num[0] && num[0] < num[1])
	{
		ft_sort_rsrra(stack);
		ft_stack_swap(*stack, "sa\n");
	}
	else if (num[1] < num[0] && num[0] < num[2])
		ft_stack_swap(*stack, "sa\n");
	else if (num[1] < num[2] && num[2] < num[0])
	{
		ft_stack_swap(*stack, "sa\n");
		ft_sort_rsrra(stack);
	}
	else if (num[2] < num[1] && num[1] < num[0])
	{
		ft_stack_swap(*stack, "sa\n");
		ft_sort_rsrra(stack);
		ft_stack_swap(*stack, "sa\n");
	}
}

void	ft_sort_rsrrb(t_stack **stack)
{
	ft_stack_rotate(stack, "rb\n");
	ft_stack_swap(*stack, "sb\n");
	ft_stack_rev_rotate(stack, "rrb\n");
}

void	ft_sort_case_3b(t_stack **stack)
{
	int	num[3];

	num[0] = (*stack)->num;
	num[1] = (*stack)->next->num;
	num[2] = (*stack)->next->next->num;
	if (num[0] < num[2] && num[2] < num[1])
		ft_sort_rsrrb(stack);
	else if (num[2] < num[0] && num[0] < num[1])
	{
		ft_sort_rsrrb(stack);
		ft_stack_swap(*stack, "sb\n");
	}
	else if (num[1] < num[0] && num[0] < num[2])
		ft_stack_swap(*stack, "sb\n");
	else if (num[1] < num[2] && num[2] < num[0])
	{
		ft_stack_swap(*stack, "sb\n");
		ft_sort_rsrrb(stack);
	}
	else if (num[2] < num[1] && num[1] < num[0])
	{
		ft_stack_swap(*stack, "sb\n");
		ft_sort_rsrrb(stack);
		ft_stack_swap(*stack, "sb\n");
	}
}
