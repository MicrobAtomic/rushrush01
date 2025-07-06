/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_count_visible.c                                  :+:    :+:           */
/*                                                      +:+                   */
/*   By: elhirond <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/07/05 17:56:30 by elhirond       #+#    #+#                */
/*   Updated: 2025/07/05 17:56:33 by elhirond       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "sources.h"

int	count_visible_from_top(int pos, int **grid, int *clues, int x)
{
	int	visible;
	int	max_h;
	int	i;

	visible = 0;
	max_h = 0;
	i = 0;
	while (i < x)
	{
		if (grid[i][pos % x] > max_h)
		{
			visible++;
			max_h = grid[i][pos % x];
		}
		i++;
	}
	if (visible > clues[pos % x])
		return (1);
	return (0);
}

int	count_visible_from_bottom(int pos, int **grid, int *clues, int x)
{
	int	visible;
	int	max_h;
	int	i;

	visible = 0;
	max_h = 0;
	i = x - 1;
	while (i >= 0)
	{
		if (grid[i][pos % x] > max_h)
		{
			visible++;
			max_h = grid[i][pos % x];
		}
		i--;
	}
	if (visible > clues[(pos % x) + x])
		return (1);
	return (0);
}

int	count_visible_from_left(int pos, int **grid, int *clues, int x)
{
	int	visible;
	int	max_h;
	int	i;

	visible = 0;
	max_h = 0;
	i = 0;
	if ((pos % x) == (x - 1))
	{
		while (i < x)
		{
			if (grid[pos / x][i] > max_h)
			{
				visible++;
				max_h = grid[pos / x][i];
			}
			i++;
		}
		if (visible != clues[(pos / x) + (x * 2)])
			return (1);
	}
	return (0);
}

int	count_visible_from_right(int pos, int **grid, int *clues, int x)
{
	int	visible;
	int	max_h;
	int	i;

	visible = 0;
	max_h = 0;
	i = x - 1;
	if ((pos % x) == (x - 1))
	{
		while (i >= 0)
		{
			if (grid[pos / x][i] > max_h)
			{
				visible++;
				max_h = grid[pos / x][i];
			}
			i--;
		}
		if (visible != clues[(pos / x) + (x * 3)])
			return (1);
	}
	return (0);
}

int	check_clues(int pos, int *clues, int **grid, int x)
{
	if (count_visible_from_top(pos, grid, clues, x) == 1)
		return (1);
	if (count_visible_from_bottom(pos, grid, clues, x) == 1)
		return (1);
	if (count_visible_from_left(pos, grid, clues, x) == 1)
		return (1);
	if (count_visible_from_right(pos, grid, clues, x) == 1)
		return (1);
	return (0);
}
