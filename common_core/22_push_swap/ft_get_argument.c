/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_argument.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:44:13 by dtakamat          #+#    #+#             */
/*   Updated: 2024/05/03 20:29:56 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_stack	*ft_arg_to_stack(int ac, char **av);

t_stack	*ft_get_stack(int ac, char **av)
{
	t_stack	*stack_a;

	if (!ft_is_all_digit(ac, av))
		return (0);
	stack_a = ft_arg_to_stack(ac, av);
	return (stack_a);
}

int	ft_arg_is_duplicagte(t_stack *stack, int num)
{
	while (stack != NULL)
	{
		if (stack->num == num)
			return (1);
		stack = stack->next;
	}
	return (0);
}

t_stack	*ft_arg_to_stack(int ac, char **av)
{
	long	num;
	int		i;
	t_stack	*ret;

	ret = NULL;
	i = ac - 1;
	while (i > 0)
	{
		num = ft_atol(av[i]);
		if (num < (long)INT_MIN || (long)INT_MAX < num)
			return (ft_stack_free(&ret), NULL);
		if (ft_arg_is_duplicagte(ret, (int)num) == 1)
			return (ft_stack_free(&ret), NULL);
		if (ft_stack_add(&ret, (int)num) == -1)
			return (ft_stack_free(&ret), NULL);
		i--;
	}
	return (ret);
}

int	ft_is_all_digit(int ac, char **av)
{
	int	i;
	int	j;
	int	len;

	i = 1;
	while (i < ac)
	{
		j = 0;
		len = ft_strlen(av[i]);
		if (len == 0)
			return (0);
		if (av[i][0] == '-')
		{
			if (len == 1)
				return (0);
			j = 1;
		}
		while (j < len)
			if (!ft_isdigit(av[i][j++]))
				return (0);
		i++;
	}
	return (1);
}
