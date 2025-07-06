/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopizzo <mlopizzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 15:26:41 by elhirond          #+#    #+#             */
/*   Updated: 2025/07/05 19:51:09 by mlopizzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sources.h"

int	is_invalid_input(char **argv, int x)
{
	char	*input;
	int		i;

	input = argv[1];
	i = 0;
	while (i < (x * 4 * 2) - 1)
	{
		if (i % 2 == 0)
		{
			if (input[i] < '1' || input[i] > (x + '0'))
				return (1);
		}
		else
		{
			if (input[i] != ' ')
				return (1);
		}
		i++;
	}
	return (0);
}

int	check_argc_len(int argc, char **argv)
{
	int	len;
	int	x;

	if (argc != 2)
		return (1);
	len = 0;
	while (argv[1][len] != '\0')
		len++;
	x = ((len + 1) / 2) / 4;
	if (len == 55 || len == 31 || len == 39 || len == 63
		|| len == 71 || len == 47)
		return (x);
	return (1);
}

int	main(int argc, char **argv)
{
	int	**grid;
	int	*clues;
	int	pos;
	int	x;

	pos = 0;
	x = check_argc_len(argc, argv);
	if (x == 1)
		return (err_manager());
	if (is_invalid_input(argv, x))
		return (err_manager());
	clues = parsing(argv[1], x);
	grid = init_grid(x);
	if (ft_solver_from_pos(pos, grid, clues, x) == 0)
		disp_grid(grid, x);
	else if (ft_solver_from_pos(pos, grid, clues, x) == 1)
		return (err_manager());
	free(grid);
	free(clues);
	return (0);
}

//clues = parsing("3 1 4 2 2 2 1 2 2 2 1 3 2 1 3 2"); 4x4
//clues = parsing("4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"); 4x4
//clues = parsing("3 2 2 1 2 3 1 2 3 2 1 3 1 3 3 2"); 4x4
//"3 3 2 4 3 1 2 4 3 2 2 5 2 1 5 3 2 3 4 2 5 4 2 3 1 6 3 4 2 3 1 4 3 4 2 2"9x9
// "3 6 1 4 5 3 2 1 2 3 2 3 3 4 2 6 4 3 4 2 1 2 1 2 3 2 3 5" 7x7
// "3 2 1 8 2 2 3 6 2 4 2 1 3 6 3 2 3 2 2 3 6 1 5 3 5 3 3 2 2 3 1 3" 8x8
// "4 3 4 3 1 2 2 2 1 3 4 4 3 3 2 2 1 2 2 1 3 5 4 3" 6x6
// "1 4 2 3 3 3 2 3 1 2 1 3 3 2 2 4 3 1 2 2" 5 x5