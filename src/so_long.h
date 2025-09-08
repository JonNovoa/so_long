/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:07:12 by jon               #+#    #+#             */
/*   Updated: 2025/09/08 20:05:01 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"
# include "mlx.h"


typedef struct s_images
{
	void	*wall;
	void	*floor;
	void	*player;
	void	*exit;
	void	*collect;
}	t_images;

typedef struct s_game
{
	char		**map;
	int			rows;
	int			cols;
	int			player_x;
	int			player_y;
	int			tile_size;
	int			collect_total;
	int			collect_taken;
	int			moves;
	void		*mlx;
	void		*win;
	t_images	img;
}	t_game;
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

int		init_game(t_game *game, char *map_file);
int		load_images(t_game *game);
void	destroy_images(t_game *game);
void	draw_map(t_game *game);
int		handle_key(int keycode, void *param);
int		close_window(t_game *game);
int		move_player(t_game *game, int dx, int dy);

/*init_game*/
int		init_game(t_game *game, char *map_file);
/*render_map*/
void	render_map(t_game *game);
void	draw_map(t_game *game);
/*init_images*/
int		load_images(t_game *game);


#endif
