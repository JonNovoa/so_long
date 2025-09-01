/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 20:08:19 by jnovoa-a          #+#    #+#             */
/*   Updated: 2025/09/01 20:38:13 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	main(int argc, char **argv)
{
	char	**map;

	if (argc != 2)
	{
		write(2, "Usage: ./so_long <map_file.ber>\n", 33);
		return (1);
	}
	map = load_map(argv[1]);
	if (!map)
	{
		write(2, "Error: cannot load map\n", 24);
		return (1);
	}
	if (!validate_map(map))
		write(1, "Map is invalid\n", 16);
	else
		write(1, "Map is valid\n", 14);
	free_map(map);
	return (0);
}