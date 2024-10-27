/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 17:43:57 by albernar          #+#    #+#             */
/*   Updated: 2024/10/21 17:34:31 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_key(t_game *game)
{
	game->keys.up = 0;
	game->keys.down = 0;
	game->keys.left = 0;
	game->keys.right = 0;
}

int	main(int argc, char **argv)
{
	t_game	game;
	int		game_err;

	if (argc != 2)
	{
		ft_printf("Error\nNot enough arguments.\n");
		return (1);
	}
	parse_map(argv[1], &game);
	game_err = game_init(&game);
	if (game_err != NO_GAME_ERROR)
	{
		game_error_handler(game_err);
		return (1);
	}
	free_map(&game.map);
	return (0);
}
