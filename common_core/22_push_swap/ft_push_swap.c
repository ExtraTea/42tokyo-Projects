/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:51:19 by dtakamat          #+#    #+#             */
/*   Updated: 2024/05/06 19:54:27 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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
	if (ft_is_sorted(stack_a) == 1)
	{
		ft_stack_free(&stack_a);
		return (0);
	}
	ft_sort_large(&stack_a, &stack_b, ac - 1);
	ft_stack_print_merge(NULL);
	ft_stack_free(&stack_a);
	ft_stack_free(&stack_b);
}
