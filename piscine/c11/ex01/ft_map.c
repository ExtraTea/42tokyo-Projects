/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:38:57 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/27 17:38:58 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*result;
	int	index;

	result = (int *)malloc(sizeof (int) * length);
	index = 0;
	while (index < length)
	{
		result[index] = f(tab[index]);
		index++;
	}
	return (result);
}

/* int sq(int n){
	return n*n;
}
#include <stdio.h>
int main(void)
{
	int nums[] = {1, 2, 3, 4, 5};
	int *re;
	re = ft_map(nums, 5, sq);
	for(int i = 0; i<5; i++){
		printf("%d, ", re[i]);
	}
} */
