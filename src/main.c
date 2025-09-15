/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 20:00:46 by jnovoa-a          #+#    #+#             */
/*   Updated: 2025/09/15 20:07:27 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

#include "so_long.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (printf("Usage: %s map.ber\n", argv[0]), 1);

	game.map = read_map(argv[1]);
	if (!game.map)
		return (1);

	if (!validate_map(&game))
		return (1);

	game.rows = count_rows(game.map);
	game.cols = ft_strlen(game.map[0]);
	game.tile_size = 64;
	game.collect_taken = 0; // Inicializa
	game.collect_total = count_collectibles(game.map); // Función que cuenta 'C' en el mapa
	game.moves = 0;

	// Encuentra posición inicial del jugador
	find_player_position(&game);

	// Inicializa MinilibX y ventana
	if (init_game(&game))
		return (1);

	// Dibuja el mapa inicial
	render_map(&game);

	// Engancha teclado
	mlx_key_hook(game.win, handle_keypress, &game);

	// Engancha cierre de ventana (X)
	mlx_hook(game.win, 17, 0, close_game_event, &game);

	mlx_loop(game.mlx);
	return (0);
}

