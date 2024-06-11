/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 22:24:06 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/11 22:24:08 by dtakamat         ###   ########.fr       */
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
			print_row('o', '-', 'o', x);
		else if (i == y -1)
			print_row('o', '-', 'o', x);
		else
			print_row('|', ' ', '|', x);
		i++;
	}
}
