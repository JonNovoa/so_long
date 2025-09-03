/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 18:44:37 by jnovoa-a          #+#    #+#             */
/*   Updated: 2025/09/03 19:16:41 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_rectangular(char **map)
{
	int	len;
	int	i;
	int	j;

	if (!map || !map[0])
		return (0);
	len = 0;
	while (map[0][len])
		len++;
	i = 1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (j != len)
			return (0);
		i++;
	}
	return (1);
}

int	check_walls(char **map)
{
	int	i;
	int	len;

	if (!map)
		return (0);
	len = 0;
	while (map[0][len])
		len++;
	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (map[0][i])
	{
		if (map[0][i] != '1' || map[i][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	count_elements(char **map, char c)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	check_required_elements(char **map)
{
	int	player;
	int	exit;
	int	collect;

	player = count_elements(map, 'P');
	exit = count_elements(map, 'E');
	collect = count_elements(map, 'C');
	if (player != 1 || exit != 1 || collect < 1)
		return (0);
	return (1);
}


