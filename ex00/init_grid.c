/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopizzo <mlopizzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 16:49:26 by mlopizzo          #+#    #+#             */
/*   Updated: 2025/07/05 18:59:34 by mlopizzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sources.h"

int	**init_grid(int x)
{
	int	**grid;
	int	i;
	int	j;

	grid = malloc (x * sizeof(int *));
	if (!grid)
		err_manager();
	i = 0;
	while (i < x)
	{
		j = 0;
		grid[i] = malloc(x * sizeof(int));
		while (j < x)
		{
			grid[i][j] = 0;
			++j;
		}
		++i;
	}
	return (grid);
}
