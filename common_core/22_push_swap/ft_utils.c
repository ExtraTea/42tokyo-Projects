/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:31:31 by dtakamat          #+#    #+#             */
/*   Updated: 2024/05/04 12:15:58 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	ft_abs(int a)
{
	if (a > 0)
		return (a);
	else
		return (-a);
}

int	ft_is_sorted(t_stack *stack)
{
	int	now;

	if (stack == NULL)
		return (-1);
	now = INT_MIN;
	while (stack != NULL)
	{
		if (stack->num >= now)
		{
			now = stack->num;
			stack = stack->next;
		}
		else
		{
			return (0);
		}
	}
	return (1);
}

int	ft_bigger_than_stack(t_stack *stack, int num)
{
	while (stack != NULL)
	{
		if (stack->num < num)
			return (0);
		stack = stack->next;
	}
	return (1);
}
