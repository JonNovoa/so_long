/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jon <jon@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 18:44:40 by jnovoa-a          #+#    #+#             */
/*   Updated: 2025/09/04 13:42:14 by jon              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_reader.h" // aquí irían las funciones que te di
#include "map_validator.h"

/* int main(void)
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
} */
#include "map_reader.h"
#include "map_validator.h"
#include <stdio.h> // Para printf
#include <stdlib.h> // Para exit

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		printf("Uso: %s <mapa.ber>\n", argv[0]);
		return (1);
	}

	// Leer el mapa desde archivo
	game.map = read_map(argv[1]);
	if (!game.map)
	{
		printf("Error: No se pudo cargar el mapa\n");
		return (1);
	}

	// Validar el mapa
	if (!validate_map(&game))
	{
		printf("Error: Mapa inválido\n");
		free_map(game.map);
		return (1);
	}

	printf("Mapa válido y accesible\n");

	// Aquí iría tu lógica del juego...

	free_map(game.map);
	return (0);
}

