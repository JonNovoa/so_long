/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 19:14:19 by jnovoa-a          #+#    #+#             */
/*   Updated: 2025/09/01 20:16:02 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	map_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	map_is_closed(char **map)
{
	int	i;
	int	height;
	int	len;

	len = 0;
	while (map[0][len])
		len++;
	height = map_height(map);
	i = 0;
	while (map[0][i])
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	count_elements(char **map, char element)
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
			if (map[i][j] == element)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	validate_map(char **map)
{
	if (!map_is_closed(map))
		return (0);
	if (count_elements(map, 'P') != 1)
		return (0);
	if (count_elements(map, 'C') < 1)
		return (0);
	if (count_elements(map, 'E') != 1)
		return (0);
	return (1);
}