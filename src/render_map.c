/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 18:12:35 by jnovoa-a          #+#    #+#             */
/*   Updated: 2025/09/12 18:37:07 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_tile(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img,
		x * game->tile_size, y * game->tile_size);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->cols)
		{
			put_tile(game, game->img.floor, x, y);
			if (game->map[y][x] == '1')
				put_tile(game, game->img.wall, x, y);
			else if (game->map[y][x] == 'P')
				put_tile(game, game->img.player, x, y);
			else if (game->map[y][x] == 'C')
				put_tile(game, game->img.collect, x, y);
			else if (game->map[y][x] == 'E')
				put_tile(game, game->img.exit, x, y);
			x++;
		}
		y++;
	}
}

int	count_rows(char **map)
{
	int	rows;

	rows = 0;
	while (map[rows])
		rows++;
	return (rows);
}

