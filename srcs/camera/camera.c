/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 02:06:15 by albernar          #+#    #+#             */
/*   Updated: 2024/10/24 02:06:16 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	camera_init(t_game *game, t_camera *camera)
{
	camera->x = 0.0;
	camera->y = 0.0;
	camera->width = game->width;
	camera->height = game->height;
	camera->speed = 0.1f;
}

void	camera_update(t_game *game)
{
	float	target_x;
	float	target_y;
	int		max_x;
	int		max_y;

	target_x = game->player.x - (game->camera.width / 2);
	target_y = game->player.y - (game->camera.height / 2);
	game->camera.x += (target_x - game->camera.x) * game->camera.speed;
	game->camera.y += (target_y - game->camera.y) * game->camera.speed;
	max_x = ((game->map.w + 1) * game->tilemap.tile_size) - game->camera.width;
	max_y = ((game->map.h + 1) * game->tilemap.tile_size) - game->camera.height;
	if (game->camera.x < 0)
		game->camera.x = 0;
	if (game->camera.y < 0)
		game->camera.y = 0;
	if (game->camera.x > max_x)
		game->camera.x = max_x;
	if (game->camera.y > max_y)
		game->camera.y = max_y;
}
