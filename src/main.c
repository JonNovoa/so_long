/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 18:44:40 by jnovoa-a          #+#    #+#             */
/*   Updated: 2025/09/03 18:44:41 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_reader.h" // aquí irían las funciones que te di

int main(void)
{
    char **map;
    int i = 0;

    map = read_map("mapa.ber"); // pon el nombre de tu archivo
    if (!map)
    {
        printf("Error leyendo el mapa\n");
        return (1);
    }
    while (map[i])
    {
        printf("%s\n", map[i]);
        i++;
    }
    // liberar memoria
    i = 0;
    while (map[i])
        free(map[i++]);
    free(map);
    return (0);
}
