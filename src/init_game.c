/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 18:50:40 by jnovoa-a          #+#    #+#             */
/*   Updated: 2025/09/05 18:52:46 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	init_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	game->win = mlx_new_window(game->mlx,
			game->cols * game->tile_size,
			game->rows * game->tile_size,
			"so_long");
	if (!game->win)
		return (0);
	return (1);
}

int	init_game(t_game *game, char *map_file)
{
	game->map = read_map(map_file);
	if (!game->map)
		return (0);
	if (!validate_map(game))
	{
		free_map(game->map);
		return (0);
	}
	game->rows = ft_matrix_len(game->map);
	game->cols = ft_strlen(game->map[0]);
	find_player(game->map, &game->player_x, &game->player_y);
	game->tile_size = 64;
	game->collect_total = count_elements(game->map, 'C');
	game->collect_taken = 0;
	game->moves = 0;
	if (!init_window(game))
	{
		free_map(game->map);
		return (0);
	}
	return (1);
}