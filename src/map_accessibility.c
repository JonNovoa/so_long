/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_accessibility.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jon <jon@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 10:56:56 by jon               #+#    #+#             */
/*   Updated: 2025/09/04 13:40:58 by jon              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_validator.h"

static int	ft_matrix_len(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix)
		return (0);
	while (matrix[i])
		i++;
	return (i);
}

static void	free_map_copy(char **copy)
{
	int	i;

	i = 0;
	while (copy && copy[i])
		free(copy[i++]);
	free(copy);
}

static char	**copy_map(char **map)
{
	int		i;
	char	**copy;

	i = 0;
	copy = malloc(sizeof(char *) * (ft_matrix_len(map) + 1));
	if (!copy)
		return (NULL);
	while (map[i])
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			free_map_copy(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static void	flood_fill(char **map, int x, int y, char target)
{
	if (x < 0 || y < 0 || !map[y] || x >= (int)ft_strlen(map[y]))
		return ;
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	if (target == 'C' && map[y][x] == 'E')
		return ;
	map[y][x] = 'F';
	flood_fill(map, x + 1, y, target);
	flood_fill(map, x - 1, y, target);
	flood_fill(map, x, y + 1, target);
	flood_fill(map, x, y - 1, target);
}

static int	all_reached(char **map, char target)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == target)
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

static int	find_player(char **map, int *px, int *py)
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

static int	target_reachable(char **map, char target)
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


