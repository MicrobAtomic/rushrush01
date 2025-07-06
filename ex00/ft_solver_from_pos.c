/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver_from_pos.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopizzo <mlopizzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 17:03:47 by elhirond          #+#    #+#             */
/*   Updated: 2025/07/05 19:18:17 by mlopizzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sources.h"

int	is_valid(int **grid, int pos, int val, int x)
{
	int	i;

	i = 0;
	while (i < pos / x)
	{
		if (grid[i][pos % x] == val)
			return (1);
		i++;
	}
	i = 0;
	while (i < pos % x)
	{
		if (grid[pos / x][i] == val)
			return (1);
		i++;
	}
	return (0);
}

void	prepose(int **grid, int *clues, int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (clues[i] == x && is_valid(grid, i, 1, x))
			grid[0][i] = 1;
		if (clues[i] == 1 && is_valid(grid, i, x, x))
			grid[0][i] = x;
		if (clues[i + x] == x && is_valid(grid, x - 1 + i, 1, x))
			grid[x - 1][i] = 1;
		if (clues[i + x] == 1 && is_valid(grid, x - 1 + i, x, x))
			grid[x - 1][i] = x;
		if (clues[i + (x * 2)] == x && is_valid(grid, i * x, 1, x))
			grid[i][0] = 1;
		if (clues[i + (x * 2)] == 1 && is_valid(grid, i * x, x, x))
			grid[i][0] = x;
		if (clues[i + (x * 3)] == x && is_valid(grid, (i * x) + x - 1, 1, x))
			grid[i][x - 1] = 1;
		if (clues[i + (x * 3)] == 1 && is_valid(grid, (i * x) + x - 1, x, x))
			grid[i][x - 1] = x;			
		i++;
	}
	disp_grid(grid, x);
	printf("\n");
}

int	ft_solver_from_pos(int pos, int **grid, int *clues, int x)
{
	int	row;
	int	col;
	int	val;

	prepose(grid, clues, x);
	//disp_grid(grid, x);
	//printf("\n");
	if (pos == x * x)
		return (0);
	row = pos / x;
	col = pos % x;
	val = 0;
	while (++val <= x)
	{
		if (is_valid(grid, pos, val, x) == 0)
		{
			grid[row][col] = val;
			if (check_clues(pos, clues, grid, x) == 0)
			{
				if (ft_solver_from_pos(pos + 1, grid, clues, x) == 0)
					return (0);
			}
			else
				grid[row][col] = 0;
		}
	}
	return (1);
}
