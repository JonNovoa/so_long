/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 18:12:35 by jnovoa-a          #+#    #+#             */
/*   Updated: 2025/09/17 18:26:48 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_tile(t_game *game, char tile, int x, int y)
{
	if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.wall, x * game->tile_size,
			y * game->tile_size);
	else if (tile == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.floor, x * game->tile_size,
			y * game->tile_size);
	else if (tile == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.collect, x * game->tile_size,
			y * game->tile_size);
	else if (tile == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.exit, x * game->tile_size,
			y * game->tile_size);
}

void	render_map(t_game *game)
{
	int		x;
	int		y;
	char	tile;

	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->cols)
		{
			tile = game->map[y][x];
			draw_tile(game, tile, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.player,
		game->player_x * game->tile_size,
		game->player_y * game->tile_size);
}

int	count_rows(char **map)
{
	int	rows;

	rows = 0;
	while (map[rows])
		rows++;
	return (rows);
}
