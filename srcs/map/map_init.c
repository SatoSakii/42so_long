/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 02:39:55 by albernar          #+#    #+#             */
/*   Updated: 2024/10/24 02:39:55 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_points(int points[4][2], int new_x, int new_y, int tile_size)
{
	int	offset;

	offset = tile_size / 4;
	points[0][0] = new_x + offset;
	points[0][1] = new_y + offset;
	points[1][0] = new_x + tile_size - offset;
	points[1][1] = new_y + offset;
	points[2][0] = new_x + offset;
	points[2][1] = new_y + tile_size - offset;
	points[3][0] = new_x + tile_size - offset;
	points[3][1] = new_y + tile_size - offset;
}

int	map_border_init(void *mlx, t_tilemap *tilemap, int ts)
{
	tilemap->wall_img[1] = mlx_png_file_to_image(mlx,
			"./textures/wall/left_top_corner_wall.png", &ts, &ts);
	tilemap->wall_img[2] = mlx_png_file_to_image(mlx,
			"./textures/wall/top_wall.png", &ts, &ts);
	tilemap->wall_img[3] = mlx_png_file_to_image(mlx,
			"./textures/wall/right_top_corner_wall.png", &ts, &ts);
	tilemap->wall_img[4] = mlx_png_file_to_image(mlx,
			"./textures/wall/left_wall.png", &ts, &ts);
	tilemap->wall_img[5] = mlx_png_file_to_image(mlx,
			"./textures/wall/left_down_corner_wall.png", &ts, &ts);
	tilemap->wall_img[6] = mlx_png_file_to_image(mlx,
			"./textures/wall/down_wall.png", &ts, &ts);
	tilemap->wall_img[7] = mlx_png_file_to_image(mlx,
			"./textures/wall/right_down_corner_wall.png", &ts, &ts);
	tilemap->wall_img[8] = mlx_png_file_to_image(mlx,
			"./textures/wall/right_wall.png", &ts, &ts);
	if (!tilemap->wall_img[1] || !tilemap->wall_img[2] || !tilemap->wall_img[3]
		|| !tilemap->wall_img[4] || !tilemap->wall_img[5]
		|| !tilemap->wall_img[6] || !tilemap->wall_img[7]
		|| !tilemap->wall_img[7] || !tilemap->wall_img[8])
	{
		ft_printf("Error\nFailed to load Tiles.\n");
		return (INIT_ERROR);
	}
	return (NO_GAME_ERROR);
}

int	map_init(void *mlx, t_tilemap *tilemap, int ts)
{
	tilemap->floor_img = mlx_png_file_to_image(mlx,
			"./textures/floor/floor.png", &ts, &ts);
	tilemap->wall_img[0] = mlx_png_file_to_image(mlx,
			"./textures/wall/middle_wall.png", &ts, &ts);
	tilemap->spiderweb_img = mlx_png_file_to_image(mlx,
			"./textures/floor/spider_web.png", &ts, &ts);
	tilemap->player_spawn_img = mlx_png_file_to_image(mlx,
			"./textures/floor/player_spawn.png", &ts, &ts);
	tilemap->collectible_img = mlx_png_file_to_image(mlx,
			"./textures/floor/collectible.png", &ts, &ts);
	tilemap->exit_img = mlx_png_file_to_image(mlx,
			"./textures/floor/exit.png", &ts, &ts);
	if (map_border_init(mlx, tilemap, ts) == INIT_ERROR)
		return (INIT_ERROR);
	if (!tilemap->floor_img || !tilemap->wall_img[0] || !tilemap->spiderweb_img
		|| !tilemap->player_spawn_img || !tilemap->collectible_img
		|| !tilemap->exit_img)
	{
		ft_printf("Error\nFailed to load Tiles.\n");
		return (INIT_ERROR);
	}
	return (NO_GAME_ERROR);
}
