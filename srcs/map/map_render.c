/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 02:39:58 by albernar          #+#    #+#             */
/*   Updated: 2024/10/24 02:39:59 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_collision(t_game *game, float new_x, float new_y)
{
	int	i;
	int	tile_x;
	int	tile_y;
	int	points[4][2];

	i = -1;
	init_points(points, new_x, new_y, game->tilemap.tile_size);
	while (++i < 4)
	{
		tile_x = points[i][0] / game->tilemap.tile_size;
		tile_y = points[i][1] / game->tilemap.tile_size;
		if (tile_x < 0 || tile_x >= game->map.w
			|| tile_y < 0 || tile_y >= game->map.h)
			return (1);
		if (game->map.grid[tile_y][tile_x] == '1')
			return (1);
	}
	return (0);
}

void	render_floor_or_wall(t_game *game, char type,
	int screen_x, int screen_y)
{
	if (type == '1')
		render_wall(game, &game->camera, screen_x, screen_y);
	else if (type == '0')
		render_floor(game, screen_x, screen_y);
}

void	render_map(t_game *game, t_camera *camera, t_tilemap *tilemap)
{
	int	x;
	int	y;
	int	screen_x;
	int	screen_y;

	y = (int)(camera->y / tilemap->tile_size) - 1;
	while (++y <= (camera->y + camera->height) / tilemap->tile_size)
	{
		if (y < 0 || y > game->map.h)
			continue ;
		x = (int)(camera->x / tilemap->tile_size) - 1;
		while (++x <= (camera->x + camera->width) / tilemap->tile_size)
		{
			if (x < 0 || x > game->map.w)
				continue ;
			screen_x = x * tilemap->tile_size - (int)camera->x;
			screen_y = y * tilemap->tile_size - (int)camera->y;
			if (game->map.grid[y][x] == '1' || game->map.grid[y][x] == '0')
				render_floor_or_wall(game, game->map.grid[y][x],
					screen_x, screen_y);
			else if (game->map.grid[y][x] == 'P' || game->map.grid[y][x] == 'E'
				|| game->map.grid[y][x] == 'C')
				render_others(game, game->map.grid[y][x], screen_x, screen_y);
		}
	}
}
