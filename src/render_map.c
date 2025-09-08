/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 19:21:30 by jnovoa-a          #+#    #+#             */
/*   Updated: 2025/09/08 20:39:46 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_image(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		img, x * game->tile_size, y * game->tile_size);
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
			if (game->map[y][x] == '1')
				put_image(game, game->img.wall, x, y);
			else if (game->map[y][x] == '0')
				put_image(game, game->img.floor, x, y);
			else if (game->map[y][x] == 'P')
				put_image(game, game->img.player, x, y);
			else if (game->map[y][x] == 'C')
				put_image(game, game->img.collect, x, y);
			else if (game->map[y][x] == 'E')
				put_image(game, game->img.exit, x, y);
			x++;
		}
		y++;
	}
}

static void	*get_image(t_game *game, char c)
{
	if (c == '1')
		return (game->img.wall);
	if (c == '0')
		return (game->img.floor);
	if (c == 'P')
		return (game->img.player);
	if (c == 'C')
		return (game->img.collect);
	if (c == 'E')
		return (game->img.exit);
	return (game->img.floor);
}

void	draw_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->cols)
		{
			mlx_put_image_to_window(game->mlx, game->win,
				get_image(game, game->map[y][x]),
				x * game->tile_size, y * game->tile_size);
			x++;
		}
		y++;
	}
}

