/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 22:59:25 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/15 13:23:10 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	index;

	if (max <= min)
	{
		*range = NULL;
		return (0);
	}
	*range = (int *)malloc((max - min) * sizeof (int));
	if (*range == NULL)
		return (-1);
	index = 0;
	while (min < max)
	{
		range[0][index++] = min++;
	}
	return (index);
}
/*
#include <stdio.h>
int	main(void)
{

	int *nums;
	int result = ft_ultimate_range(&nums, 1, 8);
	for (int i=0; i<7; i++){
		printf("%d, ", nums[i]);
	}
	free(nums);
	printf("\n%d", result);
}
*/
