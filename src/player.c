/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 20:06:33 by jnovoa-a          #+#    #+#             */
/*   Updated: 2025/09/15 20:06:35 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

// Comprueba si hay muro
static int	check_wall(char tile)
{
	return (tile == '1');
}

// Comprueba si estamos en la salida
static int	check_exit(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'E')
	{
		if (game->collect_taken == game->collect_total)
		{
			printf("¡Has ganado en %d movimientos!\n", game->moves + 1);
			close_game(game);
		}
		return (1);
	}
	return (0);
}

// Comprueba si hay coleccionable
static void	check_collectible(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'C')
	{
		game->collect_taken++;
		game->map[y][x] = '0'; // piso después de recoger
	}
}

// Mueve al jugador
void	move_player(t_game *game, int dx, int dy)
{
	int	new_x = game->player_x + dx;
	int	new_y = game->player_y + dy;

	if (check_wall(game->map[new_y][new_x]))
		return ;
	if (check_exit(game, new_x, new_y))
		return ;
	check_collectible(game, new_x, new_y);

	// Actualiza mapa: piso donde estaba el jugador
	game->map[game->player_y][game->player_x] = '0';
	game->map[new_y][new_x] = 'P';

	game->player_x = new_x;
	game->player_y = new_y;

	game->moves++;
	printf("Movimientos: %d\n", game->moves);
	render_map(game);
}
