/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 20:00:46 by jnovoa-a          #+#    #+#             */
/*   Updated: 2025/09/16 18:46:00 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	game.collect_taken = 0;
	game.collect_total = count_collectibles(game.map);
	game.moves = 0;
	find_player_position(&game);
	if (init_game(&game))
		return (1);
	render_map(&game);
	mlx_key_hook(game.win, handle_keypress, &game);
	mlx_hook(game.win, 17, 0, close_game_event, &game);
	mlx_loop(game.mlx);
	return (0);
}

