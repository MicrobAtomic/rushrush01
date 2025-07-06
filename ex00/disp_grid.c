/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopizzo <mlopizzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 17:38:18 by mlopizzo          #+#    #+#             */
/*   Updated: 2025/07/05 18:47:00 by mlopizzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sources.h"

void	disp_grid(int **grid, int x)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	while (i < x)
	{
		j = 0;
		while (j < x)
		{
			c = grid[i][j] + '0';
			ft_putchar(c);
			if (j < x - 1)
			{
				ft_putchar(' ');
			}
			++j;
		}
		ft_putchar('\n');
		++i;
	}
}
