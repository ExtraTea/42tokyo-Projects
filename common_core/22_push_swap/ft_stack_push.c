/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:34:44 by dtakamat          #+#    #+#             */
/*   Updated: 2024/05/03 20:07:28 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_stack_push(t_stack **stack_to, t_stack **stack_from, char *str)
{
	int	num;

	if (*stack_from == NULL)
		return (0);
	num = (*stack_from)->num;
	ft_stack_remove(stack_from);
	if (ft_stack_add(stack_to, num) == -1)
		return (-1);
	if (str != NULL)
		ft_stack_print_merge(str);
	return (0);
}

int	ft_stack_push_dual(t_stack **stack1, t_stack **stack2, char *str)
{
	int	num1;
	int	num2;

	if (*stack1 != NULL)
	{
		num1 = (*stack1)->num;
		ft_stack_remove(stack1);
	}
	if (*stack2 != NULL)
	{
		num2 = (*stack2)->num;
		ft_stack_remove(stack2);
	}
	if (stack1 != NULL)
		if (ft_stack_add(stack2, num1) == -1)
			return (-1);
	if (stack2 != NULL)
		if (ft_stack_add(stack1, num2) == -1)
			return (-1);
	if (str != NULL)
		ft_stack_print_merge(str);
	return (0);
}
