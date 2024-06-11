/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:32:43 by dtakamat          #+#    #+#             */
/*   Updated: 2024/05/03 20:07:11 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_stack_swap(t_stack *stack, char *str)
{
	int	tmp;

	if (stack == NULL || stack->next == NULL)
		return (0);
	tmp = stack->num;
	stack->num = stack->next->num;
	stack->next->num = tmp;
	if (str != NULL)
		ft_stack_print_merge(str);
	return (0);
}

int	ft_stack_swap_dual(t_stack *stack1, t_stack *stack2, char *str)
{
	ft_stack_swap(stack1, NULL);
	ft_stack_swap(stack2, NULL);
	if (str != NULL)
		ft_stack_print_merge(str);
	return (0);
}
