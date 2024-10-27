/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 07:40:52 by albernar          #+#    #+#             */
/*   Updated: 2024/10/26 07:40:53 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_enemy_sprites(t_game *game, t_enemy *enemy, int tilesize)
{
	enemy->sprites[0] = mlx_png_file_to_image(game->mlx,
			"./textures/character/enemy_1.png", &tilesize, &tilesize);
	enemy->sprites[1] = mlx_png_file_to_image(game->mlx,
			"./textures/character/enemy_2.png", &tilesize, &tilesize);
	enemy->sprites[2] = mlx_png_file_to_image(game->mlx,
			"./textures/character/enemy_3.png", &tilesize, &tilesize);
	enemy->sprites[3] = mlx_png_file_to_image(game->mlx,
			"./textures/character/enemy_4.png", &tilesize, &tilesize);
	if (!enemy->sprites[0] || !enemy->sprites[1] || !enemy->sprites[2]
		|| !enemy->sprites[3])
		return (INIT_ERROR);
	return (NO_GAME_ERROR);
}

int	init_enemy(t_game *game, t_enemy *enemy)
{
	float	start_x;
	float	start_y;

	enemy->speed = 0.15f;
	enemy->direction = ft_rand() % 4;
	if (load_enemy_sprites(game, &game->enemy,
			game->tilemap.tile_size) == INIT_ERROR)
		return (INIT_ERROR);
	enemy->frame_time = 150;
	enemy->last_frame_time = 0;
	enemy->current_sprite = 0;
	enemy->sprite_count = 4;
	start_x = game->map.exit_posx;
	start_y = game->map.exit_posy;
	enemy->x = start_x * game->tilemap.tile_size;
	enemy->y = start_y * game->tilemap.tile_size;
	return (NO_GAME_ERROR);
}
