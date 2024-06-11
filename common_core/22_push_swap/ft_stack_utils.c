/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:32:15 by dtakamat          #+#    #+#             */
/*   Updated: 2024/05/03 18:35:47 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_stack	*ft_stack_create_elem(int num)
{
	t_stack	*res;

	res = (t_stack *)malloc(sizeof (t_stack));
	if (res == NULL)
		exit(-1);
	res->num = num;
	res->next = NULL;
	res->prev = NULL;
	return (res);
}

int	ft_stack_add(t_stack **stack, int num)
{
	t_stack	*new_elem;

	new_elem = ft_stack_create_elem(num);
	if (new_elem == NULL)
		return (-1);
	if (*stack == NULL)
		*stack = new_elem;
	else
	{
		new_elem->next = *stack;
		(*stack)->prev = new_elem;
		*stack = new_elem;
	}
	return (0);
}

int	ft_stack_remove(t_stack **stack)
{
	t_stack	*now;
	int		n;

	if (*stack == NULL)
		return (-1);
	now = *stack;
	n = now->num;
	*stack = (*stack)->next;
	free(now);
	if (*stack)
		(*stack)->prev = NULL;
	return (n);
}

t_stack	*ft_stack_free(t_stack **stack)
{
	t_stack	*now;

	while (*stack != NULL)
	{
		now = (*stack);
		(*stack) = (*stack)->next;
		free(now);
	}
	return (NULL);
}

int	ft_stack_count_elem(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}
