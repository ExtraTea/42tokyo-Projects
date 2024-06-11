/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 19:53:21 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/14 19:53:29 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*result;
	int	index;

	if (max <= min)
		return (0);
	result = (int *)malloc((max - min) * sizeof (int));
	index = 0;
	while (min < max)
		result[index++] = min++;
	return (result);
}
/*
#include <stdio.h>
int	main(void)
{
	int *nums = ft_range(-1, 4);
	for (int i=0; i<5; i++){
		printf("%d, ", nums[i]);
	}

}
*/
