/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 12:57:23 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/18 12:57:24 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	validate_fromleft(int *array, int visibleCount)
{
	int	max;
	int	count;
	int	i;

	max = 0;
	count = 0;
	i = 0;
	while (i < 4)
	{
		if (array[i] > max)
		{
			max = array[i];
			count++;
		}
		i++;
	}
	return (count == visibleCount);
}

int	validate_fromright(int *array, int visibleCount)
{
	int	max;
	int	count;
	int	i;

	max = 0;
	count = 0;
	i = 3;
	while (i >= 0)
	{
		if (array[i] > max)
		{
			max = array[i];
			count++;
		}
		i--;
	}
	return (count == visibleCount);
}

int	validate_fromtop(int **grid, int col, int visibleCount)
{
	int	max;
	int	count;
	int	i;

	max = 0;
	count = 0;
	i = 0;
	while (i < 4)
	{
		if (grid[i][col] > max)
		{
			max = grid[i][col];
			count++;
		}
		i++;
	}
	return (count == visibleCount);
}

int	validate_frombottom(int **grid, int col, int visibleCount)
{
	int	max;
	int	count;
	int	i;

	max = 0;
	count = 0;
	i = 3;
	while (i >= 0)
	{
		if (grid[i][col] > max)
		{
			max = grid[i][col];
			count++;
		}
		i--;
	}
	return (count == visibleCount);
}

int	validatepuzzle(int **grid, int infos[4][4])
{
	int	i;
	int	j;
	int	row[4];
	int	col[4];

	i = 0;
	while (i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			row[j] = grid[i][j];
			col[j] = grid[j][i];
		}
		if (!validate_fromleft(row, infos[2][i]))
			return (0);
		if (!validate_fromright(row, infos[3][i]))
			return (0);
		if (!validate_fromtop(grid, i, infos[0][i]))
			return (0);
		if (!validate_frombottom(grid, i, infos[1][i]))
			return (0);
		i++;
	}
	return (1);
}
