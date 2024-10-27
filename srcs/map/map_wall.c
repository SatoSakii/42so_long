/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_wall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:35:33 by albernar          #+#    #+#             */
/*   Updated: 2024/10/25 16:35:37 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*get_wall(int x, int y, t_tilemap *tilemap, t_map *map)
{
	void	*img;
	int		x_max;
	int		y_max;

	x_max = map->w * tilemap->tile_size;
	y_max = map->h * tilemap->tile_size;
	img = tilemap->wall_img[0];
	if (x == 0 && y == 0)
		img = tilemap->wall_img[1];
	else if (x == 0 && y != 0 && y != y_max)
		img = tilemap->wall_img[4];
	else if (x == 0 && y == y_max)
		img = tilemap->wall_img[5];
	else if (y == 0 && x != 0 && x != x_max)
		img = tilemap->wall_img[2];
	else if (y == 0 && x == x_max)
		img = tilemap->wall_img[3];
	else if (x == x_max && (y > 0 && y < y_max))
		img = tilemap->wall_img[8];
	else if (x == x_max && y == y_max)
		img = tilemap->wall_img[7];
	else if (y == y_max && (x > 0 && x < x_max))
		img = tilemap->wall_img[6];
	return (img);
}

void	render_wall(t_game *game, t_camera *camera, int screen_x, int screen_y)
{
	t_tilemap	*tilemap;
	void		*img;
	int			x;
	int			y;

	tilemap = &game->tilemap;
	x = screen_x + (int)camera->x;
	y = screen_y + (int)camera->y;
	img = get_wall(x, y, tilemap, &game->map);
	mlx_put_image_to_window(game->mlx, game->window, img, screen_x, screen_y);
}
