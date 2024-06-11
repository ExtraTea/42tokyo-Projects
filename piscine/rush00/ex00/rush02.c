/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 22:24:52 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/11 22:24:53 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	print_row(char left, char middle, char right, int num)
{
	int	index;

	index = 0;
	while (index < num)
	{
		if (index == 0)
			ft_putchar(left);
		else if (index == num - 1)
			ft_putchar(right);
		else
			ft_putchar(middle);
		index++;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	i;

	if (x < 0 || y < 0)
	{
		write(1, "Error: You put NEGATIVE number.\n", 35);
		return ;
	}
	if (x * y == 0)
		return ;
	i = 0;
	while (i < y)
	{
		if (i == 0)
			print_row('A', 'B', 'A', x);
		else if (i == y -1)
			print_row('C', 'B', 'C', x);
		else
			print_row('B', ' ', 'B', x);
		i++;
	}
}
