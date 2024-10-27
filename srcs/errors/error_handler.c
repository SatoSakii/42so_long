/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 07:22:38 by albernar          #+#    #+#             */
/*   Updated: 2024/10/21 07:22:39 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	map_error_handler(t_map_err type)
{
	static char	*map_error_str[] = {
		"NO_ERROR",
		"Invalid map format.",
		"Failed to read map.",
		"Invalid char found in the map.",
		"Invalid map width.",
		"Invalid map height.",
		"Invalid map shape (square).",
		"Map is not surrounded by walls.",
		"No player position set.",
		"Invalid player position.",
		"Too many player position.",
		"No exit in the map.",
		"Too many exit in the map.",
		"No reachable exit in the map.",
		"No collectibles in the map.",
		"No reachable collectibles in the map.",
		"Memory Error (malloc checking)"
	};

	ft_printf("Error\n%s\n", map_error_str[type]);
	exit(1);
}

void	game_error_handler(t_error_code type)
{
	static char	*game_error_str[] = {
		"NO_GAME_ERROR",
		"Some init failed.",
		"Init MLX failed.",
		"Init MLX Window failed."
	};

	ft_printf("Error\n%s\n", game_error_str[type]);
	exit (1);
}
