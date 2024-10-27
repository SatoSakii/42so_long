/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_floor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:19:08 by albernar          #+#    #+#             */
/*   Updated: 2024/10/25 18:19:09 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_floor(t_game *game, int screen_x, int screen_y)
{
	t_tilemap	*tilemap;
	t_camera	*camera;

	camera = &game->camera;
	tilemap = &game->tilemap;
	ft_srand((screen_x + (int)camera->x) * (screen_y + (int)camera->y)
		* ft_atoi(&__TIME__[6]));
	mlx_put_image_to_window(game->mlx, game->window,
		tilemap->floor_img, screen_x, screen_y);
	if (ft_rand() % 30 == 0)
		mlx_put_image_to_window(game->mlx, game->window,
			tilemap->spiderweb_img, screen_x, screen_y);
}
