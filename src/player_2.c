/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 20:06:50 by jnovoa-a          #+#    #+#             */
/*   Updated: 2025/09/15 20:07:53 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Cierra el juego
void	close_game(t_game *game)
{
	if (game->mlx && game->win)
		mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

// Adaptador para mlx_hook de la X
int	close_game_event(void *param)
{
	t_game *game = (t_game *)param;
	close_game(game);
	return (0);
}

// Manejo del teclado
int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == 65307)            // ESC
		close_game(game);
	else if (keycode == 119)         // W → arriba
		move_player(game, 0, -1);
	else if (keycode == 115)         // S → abajo
		move_player(game, 0, 1);
	else if (keycode == 97)          // A → izquierda
		move_player(game, -1, 0);
	else if (keycode == 100)         // D → derecha
		move_player(game, 1, 0);
	return (0);
}

// Encuentra la posición inicial del jugador
void	find_player_position(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x; // columna
				game->player_y = y; // fila
				return ;
			}
			x++;
		}
		y++;
	}
}
int	count_collectibles(char **map)
{
	int	i, j;
	int	count = 0;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}
