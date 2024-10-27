/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_others.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:24:51 by albernar          #+#    #+#             */
/*   Updated: 2024/10/25 20:24:52 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_others(t_game *game, char type, int screen_x, int screen_y)
{
	t_tilemap	*tilemap;
	t_camera	*camera;

	camera = &game->camera;
	tilemap = &game->tilemap;
	mlx_put_image_to_window(game->mlx, game->window,
		tilemap->floor_img, screen_x, screen_y);
	if (type == 'P')
		mlx_put_image_to_window(game->mlx, game->window,
			tilemap->player_spawn_img, screen_x, screen_y);
	else if (type == 'C')
		mlx_put_image_to_window(game->mlx, game->window,
			tilemap->collectible_img, screen_x, screen_y);
	else if (type == 'E')
		mlx_put_image_to_window(game->mlx, game->window,
			tilemap->exit_img, screen_x, screen_y);
}
