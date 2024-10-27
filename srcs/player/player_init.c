/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 02:28:39 by albernar          #+#    #+#             */
/*   Updated: 2024/10/24 02:28:40 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	player_load_sprites(void *mlx, t_player *player, int tilesize)
{
	player->sprites[0] = mlx_png_file_to_image(mlx,
			"./textures/character/character_1.png", &tilesize, &tilesize);
	player->sprites[1] = mlx_png_file_to_image(mlx,
			"./textures/character/character_2.png", &tilesize, &tilesize);
	player->sprites[2] = mlx_png_file_to_image(mlx,
			"./textures/character/character_3.png", &tilesize, &tilesize);
	player->sprites[3] = mlx_png_file_to_image(mlx,
			"./textures/character/character_4.png", &tilesize, &tilesize);
	player->death_img[1] = mlx_png_file_to_image(mlx,
			"./textures/character/character_death_1.png", &tilesize, &tilesize);
	player->death_img[2] = mlx_png_file_to_image(mlx,
			"./textures/character/character_death_2.png", &tilesize, &tilesize);
	player->death_img[3] = mlx_png_file_to_image(mlx,
			"./textures/character/character_death_3.png", &tilesize, &tilesize);
	player->death_img[4] = mlx_png_file_to_image(mlx,
			"./textures/character/character_death_4.png", &tilesize, &tilesize);
	if (!player->sprites[0] || !player->sprites[1] || !player->sprites[2]
		|| !player->sprites[3] || !player->death_img[1] || !player->death_img[2]
		|| !player->death_img[3] || !player->death_img[4])
		return (INIT_ERROR);
	player->frame_time = 150;
	player->last_frame_time = 0;
	player->current_sprite = 0;
	player->sprite_count = 4;
	return (NO_GAME_ERROR);
}

int	player_init(t_game *game, int x, int y, int tilesize)
{
	static int	dx = 1024;
	static int	dy = 512;

	game->player.death_img[0] = mlx_jpg_file_to_image(game->mlx,
			"./textures/character/death_screen.jpg", &dx, &dy);
	game->player.move_count = -1;
	game->player.x = x * tilesize;
	game->player.y = y * tilesize;
	game->player.speed = 0.10f;
	if (player_load_sprites(game->mlx, &game->player, tilesize) == INIT_ERROR
		|| !game->player.death_img[0])
	{
		ft_printf("Error\nFailed to load Character.\n");
		return (INIT_ERROR);
	}
	return (NO_GAME_ERROR);
}
