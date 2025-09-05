/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 10:56:56 by jon               #+#    #+#             */
/*   Updated: 2025/09/05 14:55:29 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_matrix_len(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix)
		return (0);
	while (matrix[i])
		i++;
	return (i);
}

void	free_map_copy(char **copy)
{
	int	i;

	i = 0;
	while (copy && copy[i])
		free(copy[i++]);
	free(copy);
}

char	**copy_map(char **map)
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

void	flood_fill(char **map, int x, int y, char target)
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

int	all_reached(char **map, char target)
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




