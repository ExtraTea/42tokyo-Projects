/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 12:50:08 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/18 12:50:10 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	validateFromLeft(int *array, int visibleCount);
int	validateFromRight(int *array, int visibleCount);
int	validateFromTop(int **grid, int col, int visibleCount);
int	validateFromBottom(int **grid, int col, int visibleCount);
int	validatepuzzle(int **grid, int infos[4][4]);

void	print_2darray(int **array)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c = array[i][j] + '0';
			write(1, &c, 1);
			if(j != 4 - 1)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}


int	is_valid(int **grid, int row, int col, int num)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (grid[row][i] == num || grid[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}

int	solve(int **grid, int row, int col, int infos[4][4])
{
	int	nextrow;
	int	nextcol;
	int	index;

	nextrow = row + (col + 1) / 4;
	nextcol = (col + 1) % 4;
	if (row == 4)
		return (validatepuzzle(grid, infos));
	index = 1;
	while (index <= 4)
	{
		if (is_valid(grid, row, col, index))
		{
			grid[row][col] = index;
			if (solve(grid, nextrow, nextcol, infos))
				return (1);
			grid[row][col] = 0;
		}
		index++;
	}
	return (0);
}

int main() {
	 int infos[4][4] = {
		 {1,3,2,4},  // top
		 {2,2,2,1},  // bottom
		 {1,3,2,2},  // left
		 {3,2,2,1}   // right
	 };

	 // 4x4のパズルを初期化
	 int **grid = (int **)malloc(4 * sizeof(int *));
	 for (int i = 0; i < 4; i++) {
		 grid[i] = (int *)malloc(4 * sizeof(int));
		 for (int j = 0; j < 4; j++) {
			 grid[i][j] = 0;  // セルを空にする
		 }
	 }

	 // パズルを解く
	 if (solve(grid, 0, 0, infos)) {
		 printf("Puzzle solved:\n");
		print_2darray(grid);
	 } else {
		 printf("No solution found.\n");
	 }

	 // メモリ解放
	 for (int i = 0; i < 4; i++) {
		 free(grid[i]);
	 }
	 free(grid);

	 return 0;
}
