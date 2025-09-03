/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 18:44:43 by jnovoa-a          #+#    #+#             */
/*   Updated: 2025/09/03 19:04:56 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_READER_H
# define MAP_READER_H

#include <fcntl.h>   // open
#include <unistd.h>  // read, close
#include <stdlib.h>  // malloc, free
#include <stdio.h> // para printf

char	**read_map(char *filename);

int		check_rectangular(char **map);
int		check_walls(char **map);
int		count_elements(char **map, char c);
int		check_required_elements(char **map);
int		check_accessibility(char **map);
#endif
