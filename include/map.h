/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 18:50:21 by jnovoa-a          #+#    #+#             */
/*   Updated: 2025/09/01 20:16:13 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H


# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

/*map*/
int		count_lines(const char *filename);
char	**load_map(const char *filename);


/*map_utils*/
int		map_height(char **map);
int		map_is_closed(char **map);
int		count_elements(char **map, char element);
int		validate_map(char **map);


#endif
