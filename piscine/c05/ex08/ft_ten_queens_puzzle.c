/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:24:53 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/13 19:27:32 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_row_occupied(char *board, int col_index, int depth)
{
	int	index;

	index = 0;
	while (index < depth)
	{
		if (col_index == board[index] - '0')
			return (1);
		if (index - depth == col_index - (board[index] - '0')
			|| index - depth == (board[index] - '0') - col_index)
			return (1);
		index++;
	}
	return (0);
}

int	ft_ten_queens_puzzle_recursive(char *board, int depth, int *found)
{
	int	index;

	if (depth == 10)
	{
		write(1, board, 10);
		write(1, "\n", 1);
		*found += 1;
		return (*found);
	}
	index = 0;
	while (index < 10)
	{
		if (is_row_occupied(board, index, depth))
			write (1, "", 0);
		else
		{
			board[depth] = index + '0';
			ft_ten_queens_puzzle_recursive(board, depth + 1, found);
		}
		index++;
	}
	return (*found);
}

int	ft_ten_queens_puzzle(void)
{
	char	board[11];
	int		depth;
	int		found;

	depth = 0;
	found = 0;
	board[10] = '\0';
	ft_ten_queens_puzzle_recursive(board, depth, &found);
	return (found);
}
