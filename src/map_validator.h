/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jon <jon@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:07:12 by jon               #+#    #+#             */
/*   Updated: 2025/09/04 13:37:10 by jon              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_VALIDATOR_H
# define MAP_VALIDATOR_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

typedef struct s_game
{
	char	**map;
	int		player_x;
	int		player_y;

}			t_game;


/* Validaciones del mapa */
int		check_rectangular(char **map);
int		check_walls(char **map);
int		count_elements(char **map, char c);
int		check_required_elements(char **map);
/* Comprueba que todos los C y la E sean alcanzables desde P */
int		check_accessibility(char **map);

int		validate_map(t_game *game);

#endif
