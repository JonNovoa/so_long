/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:16:07 by jnovoa-a          #+#    #+#             */
/*   Updated: 2025/09/16 17:52:11 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_player(char **map, int *px, int *py)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				*px = x;
				*py = y;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	target_reachable(char **map, char target)
{
	char	**copy;
	int		px;
	int		py;

	copy = copy_map(map);
	if (!copy || !find_player(copy, &px, &py))
	{
		if (copy)
			free_map_copy(copy);
		return (0);
	}
	flood_fill(copy, px, py, target);
	if (!all_reached(copy, target))
	{
		free_map_copy(copy);
		return (0);
	}
	free_map_copy(copy);
	return (1);
}

int	check_accessibility(char **map)
{
	if (!target_reachable(map, 'C'))
		return (0);
	if (!target_reachable(map, 'E'))
		return (0);
	return (1);
}

int	check_ber_extension(const char *filename)
{
	int	len;

	if (!filename)
		return (printf("Error: nombre de archivo nulo\n"), 0);
	len = strlen(filename);
	if (len < 4 || strcmp(filename + len - 4, ".ber") != 0)
		return (printf("Error: el archivo debe tener extensión .ber\n"), 0);
	return (1);
}