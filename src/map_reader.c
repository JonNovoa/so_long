/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 18:44:34 by jnovoa-a          #+#    #+#             */
/*   Updated: 2025/09/17 14:51:55 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*append_char(char *line, char c, int *len)
{
	char	*new_line;
	int		i;

	new_line = malloc(*len + 2);
	if (!new_line)
	{
		free(line);
		return (NULL);
	}
	i = 0;
	while (line && line[i])
	{
		new_line[i] = line[i];
		i++;
	}
	new_line[i] = c;
	new_line[i + 1] = '\0';
	free(line);
	(*len)++;
	return (new_line);
}

static char	*read_line(int fd)
{
	char	c;
	char	*line;
	int		ret;
	int		len;

	line = NULL;
	len = 0;
	while (1)
	{
		ret = read(fd, &c, 1);
		if (ret <= 0)
			break ;
		if (c == '\n')
			break ;
		line = append_char(line, c, &len);
		if (!line)
			return (NULL);
	}
	if (!line && ret <= 0)
		return (NULL);
	return (line);
}

int	count_lines(char *filename)
{
	int		fd;
	int		lines;
	char	c;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	lines = 0;
	while (read(fd, &c, 1) > 0)
		if (c == '\n')
			lines++;
	close(fd);
	return (lines + 1);
}

void	fill_map(int fd, char **map, int lines)
{
	int	i;

	i = 0;
	while (i < lines)
	{
		map[i] = read_line(fd);
		if (!map[i])
			break ;
		i++;
	}
	map[i] = NULL;
}
