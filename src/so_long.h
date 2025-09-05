/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:07:12 by jon               #+#    #+#             */
/*   Updated: 2025/09/05 14:52:14 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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
/*map_reader*/
char	**read_map(char *filename);
void	free_map(char **map);
void	fill_map(int fd, char **map, int lines);
int		count_lines(char *filename);
/*map_validator*/
int		check_rectangular(char **map);
int		check_walls(char **map);
int		count_elements(char **map, char c);
int		check_required_elements(char **map);
int		validate_map(t_game *game);


/*map_validator_2*/
int		ft_matrix_len(char **matrix);
void	free_map_copy(char **copy);
char	**copy_map(char **map);
void	flood_fill(char **map, int x, int y, char target);
int		all_reached(char **map, char target);

/*map_validator_3*/
int		find_player(char **map, int *px, int *py);
int		target_reachable(char **map, char target);
int		check_accessibility(char **map);



#endif
