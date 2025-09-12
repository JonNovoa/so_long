/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 18:44:40 by jnovoa-a          #+#    #+#             */
/*   Updated: 2025/09/12 18:38:36 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define TILE_SIZE 64


#include "so_long.h"

int main(int argc, char **argv)
{
    t_game game;

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

    if (init_game(&game))
        return (1);

    render_map(&game);
    mlx_loop(game.mlx);
    return (0);
}





