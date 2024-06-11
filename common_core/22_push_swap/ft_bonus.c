/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:25:30 by dtakamat          #+#    #+#             */
/*   Updated: 2024/05/06 19:47:50 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_operation_bonus(t_stack **stack_a, t_stack **stack_b, char *order)
{
	if (ft_strncmp(order, "sa\n", 3) == 0)
		ft_stack_swap(*stack_a, NULL);
	else if (ft_strncmp(order, "sb\n", 3) == 0)
		ft_stack_swap(*stack_b, NULL);
	else if (ft_strncmp(order, "ss\n", 3) == 0)
		ft_stack_swap_dual(*stack_a, *stack_b, NULL);
	else if (ft_strncmp(order, "pa\n", 3) == 0)
		ft_stack_push(stack_a, stack_b, NULL);
	else if (ft_strncmp(order, "pb\n", 3) == 0)
		ft_stack_push(stack_b, stack_a, NULL);
	else if (ft_strncmp(order, "ra\n", 3) == 0)
		ft_stack_rotate(stack_a, NULL);
	else if (ft_strncmp(order, "rb\n", 3) == 0)
		ft_stack_rotate(stack_b, NULL);
	else if (ft_strncmp(order, "rr\n", 3) == 0)
		ft_stack_rotate_dual(stack_a, stack_b, NULL);
	else if (ft_strncmp(order, "rra\n", 4) == 0)
		ft_stack_rev_rotate(stack_a, NULL);
	else if (ft_strncmp(order, "rrb\n", 4) == 0)
		ft_stack_rev_rotate(stack_b, NULL);
	else if (ft_strncmp(order, "rrr\n", 4) == 0)
		ft_stack_rev_rotate_dual(stack_a, stack_b, NULL);
	else
		return (free(order), -1);
	return (free(order), 0);
}

void	ft_bonus(t_stack **stack_a, t_stack **stack_b)
{
	char	*order;

	while (1)
	{
		order = get_next_line(0);
		if (order == NULL)
			break ;
		if (ft_operation_bonus(stack_a, stack_b, order) == -1)
		{
			write(2, "Error\n", 6);
			ft_stack_free(stack_a);
			ft_stack_free(stack_b);
			exit(0);
		}
	}
	if (ft_is_sorted(*stack_a) == 1 && ft_stack_count_elem(*stack_b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_stack_free(stack_a);
	ft_stack_free(stack_b);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac == 1)
		return (1);
	stack_b = NULL;
	stack_a = ft_get_stack(ac, av);
	if (stack_a == NULL)
		return (write(2, "Error\n", 6));
	ft_bonus(&stack_a, &stack_b);
}
