/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:16:09 by jnovoa-a          #+#    #+#             */
/*   Updated: 2025/09/01 20:16:05 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static char	*read_line(int fd)
{
	char	*line;
	char	c;
	char	i;

	line = malloc(1024);
	if (!line)
		return (NULL);
	i = 0;
	while (read(fd, &c, 1) > 0 && c != '\n')
		line[i++] = c;
	line[i] = '\0';
	if (i == 0 && c != '\n')
	{
		free(line);
		return (NULL);
	}
	return (line);
}

int	count_lines(const char *filename)
{
	int		fd;
	int		count;
	char	c;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	count = 0;
	while (read(fd, &c, 1) > 0)
		if (c == '\n')
			count++;
	close(fd);
	return (count + 1);
}

char	**load_map(const char *filename)
{
	int		fd;
	int		lines;
	int		i;
	char	**map;

	lines = count_lines(filename);
	if (lines <= 0)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (!map)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		free(map);
		return (NULL);
	}
	i = 0;
	while (i < lines)
		map[i++] = read_line(fd);
	map[i] = NULL;
	close(fd);
	return (map);
}

