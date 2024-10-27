/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 02:27:16 by albernar          #+#    #+#             */
/*   Updated: 2024/10/25 02:27:17 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <math.h>

void	update_sprite(t_player *player, int current_time)
{
	int	next_sprite;

	if (current_time - player->last_frame_time >= player->frame_time)
	{
		next_sprite = player->current_sprite + 1;
		player->current_sprite = (next_sprite) % player->sprite_count;
		player->last_frame_time = current_time;
	}
}

void	collect_collectibles(t_game *game, t_map *map, t_player *player)
{
	int	x;
	int	y;

	x = (int)roundf(player->x / game->tilemap.tile_size);
	y = (int)roundf(player->y / game->tilemap.tile_size);
	if (x <= 0)
		x = 0;
	if (y <= 0)
		y = 0;
	if (map->grid[y][x] == 'C')
	{
		map->grid[y][x] = '0';
		map->collectible_count--;
		return ;
	}
}

void	exit_map(t_game *game, t_map *map, t_player *player)
{
	int	x;
	int	y;

	x = (int)roundf(player->x / game->tilemap.tile_size);
	y = (int)roundf(player->y / game->tilemap.tile_size);
	if (x <= 0)
		x = 0;
	if (y <= 0)
		y = 0;
	if (map->grid[y][x] == 'E' && map->collectible_count == 0)
	{
		map->grid[y][x] = '0';
		mlx_loop_end(game->mlx);
		return ;
	}
}

void	update_move_count(t_game *game, t_player *player, int tilesize)
{
	char		buf[12];
	static int	tile_x = 0;
	static int	tile_y = 0;
	int			new_tile_x;
	int			new_tile_y;

	new_tile_x = (int)roundf(player->x / tilesize);
	new_tile_y = (int)roundf(player->y / tilesize);
	if (new_tile_x != tile_x || new_tile_y != tile_y)
	{
		player->move_count++;
		tile_x = new_tile_x;
		tile_y = new_tile_y;
	}
	mlx_set_font_scale(game->mlx, game->window,
		"./textures/fonts/TextFont.ttf", 32.0f);
	mlx_string_put(game->mlx, game->window, 10,
		8, 0xFFFFFFFF, "Move");
	mlx_string_put(game->mlx, game->window, 90,
		8, 0xFFFC4C02, ft_itoa_b(player->move_count, buf + 5));
}
