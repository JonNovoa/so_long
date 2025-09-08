/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 19:01:31 by jnovoa-a          #+#    #+#             */
/*   Updated: 2025/09/08 20:29:21 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* int	load_images(t_game *game)
{
	game->img.wall = mlx_png_file_to_image(game->mlx,
			"./sprites/wall.png", &game->tile_size, &game->tile_size);
	game->img.floor = mlx_png_file_to_image(game->mlx,
			"./sprites/floor.png", &game->tile_size, &game->tile_size);
	game->img.player = mlx_png_file_to_image(game->mlx,
			"./sprites/player.png", &game->tile_size, &game->tile_size);
	game->img.collect = mlx_png_file_to_image(game->mlx,
			"./sprites/collect.png", &game->tile_size, &game->tile_size);
	game->img.exit = mlx_png_file_to_image(game->mlx,
			"./sprites/exit.png", &game->tile_size, &game->tile_size);

	if (!game->img.wall || !game->img.floor || !game->img.player
		|| !game->img.collect || !game->img.exit)
		return (0);
	return (1);
} */

int	load_images(t_game *game)
{
	game->img.wall = mlx_xpm_file_to_image(game->mlx,
			"./sprites/wall.xpm", &game->tile_size, &game->tile_size);
	game->img.floor = mlx_xpm_file_to_image(game->mlx,
			"./sprites/floor.xpm", &game->tile_size, &game->tile_size);
	game->img.player = mlx_xpm_file_to_image(game->mlx,
			"./sprites/player.xpm", &game->tile_size, &game->tile_size);
	game->img.collect = mlx_xpm_file_to_image(game->mlx,
			"./sprites/collect.xpm", &game->tile_size, &game->tile_size);
	game->img.exit = mlx_xpm_file_to_image(game->mlx,
			"./sprites/exit.xpm", &game->tile_size, &game->tile_size);

	if (!game->img.wall || !game->img.floor || !game->img.player
		|| !game->img.collect || !game->img.exit)
		return (0);
	return (1);
}


