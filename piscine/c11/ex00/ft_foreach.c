/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:30:40 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/27 17:30:42 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	index;

	index = 0;
	while (index < length)
	{
		f(tab[index++]);
	}
}

/* #include <stdio.h>
void	putnbr(int n)
{
	printf("%d\n", n);
}

int main(void)
{
	int nums[] = {1, 2, 3, 4};
	ft_foreach(nums, 4, putnbr);
} */
