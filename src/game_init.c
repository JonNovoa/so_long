/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 18:12:56 by jnovoa-a          #+#    #+#             */
/*   Updated: 2025/09/17 18:30:58 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	init_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (1);
	game->win = mlx_new_window(game->mlx,
			game->cols * game->tile_size,
			game->rows * game->tile_size,
			"so_long");
	if (!game->win)
		return (1);
	return (0);
}

static int	load_sprites(t_game *game)
{
	int	img_w;
	int	img_h;

	img_w = 0;
	img_h = 0;
	game->img.floor = mlx_xpm_file_to_image(game->mlx,
			"sprites/floor.xpm", &img_w, &img_h);
	game->img.wall = mlx_xpm_file_to_image(game->mlx,
			"sprites/wall.xpm", &img_w, &img_h);
	game->img.player = mlx_xpm_file_to_image(game->mlx,
			"sprites/player.xpm", &img_w, &img_h);
	game->img.collect = mlx_xpm_file_to_image(game->mlx,
			"sprites/collect.xpm", &img_w, &img_h);
	game->img.exit = mlx_xpm_file_to_image(game->mlx,
			"sprites/exit.xpm", &img_w, &img_h);
	if (!game->img.floor || !game->img.wall
		|| !game->img.player || !game->img.collect
		|| !game->img.exit)
		return (1);
	return (0);
}

int	init_game(t_game *game)
{
	if (init_window(game))
		return (1);
	if (load_sprites(game))
		return (1);
	return (0);
}
