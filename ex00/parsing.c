/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   parsing.c                                           :+:    :+:           */
/*                                                      +:+                   */
/*   By: wde-oliv <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/07/05 16:10:27 by wde-oliv       #+#    #+#                */
/*   Updated: 2025/07/05 17:26:59 by wde-oliv       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "sources.h"

int	*parsing(char *input, int x)
{
	int	*clues;
	int	idx;
	int	i;

	clues = malloc(sizeof(int) * (x * 4));
	if (!clues)
		err_manager();
	i = 0;
	idx = 0;
	while (input[i])
	{
		if (input[i] >= '1' && input[i] <= (x + '0'))
		{
			clues[idx] = input[i] - '0';
			idx++;
		}
		i++;
	}
	if (idx != x * 4)
		err_manager();
	return (clues);
}
