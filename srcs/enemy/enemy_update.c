/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_update.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 01:32:32 by albernar          #+#    #+#             */
/*   Updated: 2024/10/27 01:32:33 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <math.h>

void	update_enemy_sprite(t_enemy *enemy, int current_time)
{
	int	next_sprite;

	if (current_time - enemy->last_frame_time >= enemy->frame_time)
	{
		next_sprite = enemy->current_sprite + 1;
		enemy->current_sprite = (next_sprite) % enemy->sprite_count;
		enemy->last_frame_time = current_time;
	}
}

void	change_enemy_direction(t_enemy *enemy, int seed)
{
	ft_srand(seed);
	enemy->direction = ft_rand() % 4;
}

void	load_death_anim(t_game *game, t_player *player, int death_anim)
{
	if (death_anim >= 801 && death_anim <= 1200)
	{
		mlx_clear_window(game->mlx, game->window);
		mlx_put_image_to_window(game->mlx, game->window,
			player->death_img[0], 0, 0);
		mlx_put_image_to_window(game->mlx, game->window,
			player->death_img[2], game->width / 2 - 16, game->height / 2 - 16);
	}
	else if (death_anim >= 1201 && death_anim <= 1600)
	{
		mlx_clear_window(game->mlx, game->window);
		mlx_put_image_to_window(game->mlx, game->window,
			player->death_img[0], 0, 0);
		mlx_put_image_to_window(game->mlx, game->window,
			player->death_img[3], game->width / 2 - 16, game->height / 2 - 16);
	}
	else if (death_anim >= 1601 && death_anim <= 2000)
	{
		mlx_clear_window(game->mlx, game->window);
		mlx_put_image_to_window(game->mlx, game->window,
			player->death_img[0], 0, 0);
		mlx_put_image_to_window(game->mlx, game->window,
			player->death_img[4], game->width / 2 - 16, game->height / 2 - 16);
	}
}

void	kill_player(t_game *game, t_player *player, t_enemy *enemy)
{
	static int	death_anim = 0;
	int			ts;

	ts = game->tilemap.tile_size;
	if ((int)roundf(player->x / ts) == (int)roundf(enemy->x / ts)
		&& (int)roundf(player->y / ts) == (int)roundf(enemy->y / ts))
	{
		enemy->speed = 0.0f;
		player->speed = 0.0f;
		mlx_clear_window(game->mlx, game->window);
		mlx_put_image_to_window(game->mlx, game->window,
			player->death_img[0], 0, 0);
		if (death_anim >= 400 && death_anim <= 800)
		{
			mlx_put_image_to_window(game->mlx, game->window,
				player->death_img[1], game->width / 2 - 16,
				game->height / 2 - 16);
		}
		else if (death_anim >= 801 && death_anim <= 2000)
			load_death_anim(game, player, death_anim);
		else if (death_anim >= 2000)
			mlx_loop_end(game->mlx);
		death_anim++;
	}
}

void	update_enemy(t_game *game, t_enemy *enemy)
{
	static int	frame_counter = 0;
	float		new_x;
	float		new_y;

	new_x = enemy->x;
	new_y = enemy->y;
	frame_counter++;
	if (frame_counter % 1000 == 0)
		change_enemy_direction(enemy, frame_counter);
	if (enemy->direction == 0)
		new_y -= enemy->speed;
	else if (enemy->direction == 1)
		new_x += enemy->speed;
	else if (enemy->direction == 2)
		new_y += enemy->speed;
	else if (enemy->direction == 3)
		new_x -= enemy->speed;
	if (!check_map_collision(game, new_x, enemy->y))
		enemy->x = new_x;
	if (!check_map_collision(game, enemy->x, new_y))
		enemy->y = new_y;
}
