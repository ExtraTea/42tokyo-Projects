/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:33:35 by dtakamat          #+#    #+#             */
/*   Updated: 2024/05/04 12:25:12 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_stack	*ft_stack_get_bottom(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next != NULL)
	{
		stack = stack->next;
	}
	return (stack);
}

int	ft_stack_rotate(t_stack **stack, char *str)
{
	int		num;
	t_stack	*last_elem;
	t_stack	*new_elem;

	if (*stack == NULL || (*stack)->next == NULL)
		return (0);
	num = ft_stack_remove(stack);
	last_elem = ft_stack_get_bottom(*stack);
	new_elem = ft_stack_create_elem(num);
	if (new_elem == NULL)
		return (-1);
	last_elem->next = new_elem;
	new_elem->prev = last_elem;
	if (str != NULL)
		ft_stack_print_merge(str);
	return (0);
}

int	ft_stack_rotate_dual(t_stack **stack1, t_stack **stack2, char *str)
{
	if (ft_stack_rotate(stack1, NULL) == -1
		|| ft_stack_rotate(stack2, NULL) == -1)
		return (-1);
	if (str != NULL)
		ft_stack_print_merge(str);
	return (0);
}

int	ft_stack_rev_rotate(t_stack **stack, char *str)
{
	int		num;
	t_stack	*last_elem;

	if (*stack == NULL || (*stack)->next == NULL)
		return (0);
	num = ft_stack_get_bottom(*stack)->num;
	if (ft_stack_add(stack, num) == -1)
		return (-1);
	last_elem = ft_stack_get_bottom(*stack);
	last_elem->prev->next = NULL;
	free(last_elem);
	if (str != NULL)
		ft_stack_print_merge(str);
	return (0);
}

int	ft_stack_rev_rotate_dual(t_stack **stack1, t_stack **stack2, char *str)
{
	if (ft_stack_rev_rotate(stack1, NULL) == -1
		|| ft_stack_rev_rotate(stack2, NULL) == -1)
		return (-1);
	if (str != NULL)
		ft_stack_print_merge(str);
	return (0);
}
