/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 06:40:51 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/18 06:40:52 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	val_col_top(int *nums, int top, int dim)
{
	int	topcount;
	int	currenttop;
	int	index;

	topcount = 1;
	currenttop = nums[0];
	index = 1;
	while (index < dim)
	{
		if (currenttop < nums[index])
		{
			currenttop = nums[index];
			topcount++;
		}
		index++;
	}
	if (top == topcount)
		return (1);
	else
		return (0);
}

int	val_col_bottom(int *nums, int bottom, int dim)
{
	int	bottomcount;
	int	currentbottom;
	int	index;

	bottomcount = 1;
	currentbottom = nums[dim - 1];
	index = dim - 2;
	while (index >= 0)
	{
		if (currentbottom < nums[index])
		{
			currentbottom = nums[index];
			bottomcount++;
		}
		index--;
	}
	if (bottom == bottomcount)
		return (1);
	else
		return (0);
}

int	val_col(int *nums, int top, int bottom, int dim)
{
	int	validtop;
	int	validbottom;

	validtop = val_col_top(nums, top, dim);
	validbottom = val_col_bottom(nums, bottom, dim);
	if (validtop && validbottom)
		return (1);
	else
		return (0);
}
