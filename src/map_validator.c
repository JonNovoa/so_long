/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jon <jon@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:07:48 by jon               #+#    #+#             */
/*   Updated: 2025/09/04 13:18:40 by jon              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_validator.h"

int	check_rectangular(char **map)
{
	int	len;
	int	i;
	int	j;

	if (!map || !map[0])
		return (0);
	len = 0;
	while (map[0][len])
		len++;
	i = 1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (j != len)
			return (0);
		i++;
	}
	return (1);
}

int	check_walls(char **map)
{
	int	rows;
	int	cols;
	int	i;

	if (!map || !map[0])
		return (0);
	rows = 0;
	while (map[rows])
		rows++;
	cols = 0;
	while (map[0][cols])
		cols++;
	/* comprobar primeras y últimas columnas */
	i = 0;
	while (i < rows)
	{
		if (map[i][0] != '1' || map[i][cols - 1] != '1')
			return (0);
		i++;
	}
	/* comprobar primera y última fila */
	i = 0;
	while (i < cols)
	{
		if (map[0][i] != '1' || map[rows - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	count_elements(char **map, char c)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	check_required_elements(char **map)
{
	int	player;
	int	exit;
	int	collect;

	player = count_elements(map, 'P');
	exit = count_elements(map, 'E');
	collect = count_elements(map, 'C');
	if (player != 1 || exit != 1 || collect < 1)
		return (0);
	return (1);
}

/* validate_map usa la estructura game si existe; si no, puedes
   llamar a validate_map pasando un puntero con .map = char ** */
int	validate_map(t_game *game)
{
	if (!game || !game->map)
		return (0);
	if (!check_rectangular(game->map))
		return (0);
	if (!check_walls(game->map))
		return (0);
	if (!check_required_elements(game->map))
		return (0);
	if (!check_accessibility(game->map))
		return (0);
	return (1);
}
