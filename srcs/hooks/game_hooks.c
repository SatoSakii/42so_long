/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 02:18:06 by albernar          #+#    #+#             */
/*   Updated: 2024/10/24 02:18:07 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	window_hook(int event, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (event == 0)
		mlx_loop_end(game->mlx);
	return (NO_GAME_ERROR);
}

int	game_keydown_hook(int key, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (key == 41)
		mlx_loop_end(game->mlx);
	if (key == 22)
		game->keys.down = 1;
	if (key == 26)
		game->keys.up = 1;
	if (key == 4)
		game->keys.left = 1;
	if (key == 7)
		game->keys.right = 1;
	return (NO_GAME_ERROR);
}

int	game_keyup_hook(int key, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (key == 22)
		game->keys.down = 0;
	if (key == 26)
		game->keys.up = 0;
	if (key == 4)
		game->keys.left = 0;
	if (key == 7)
		game->keys.right = 0;
	return (NO_GAME_ERROR);
}

void	collide_and_movement(t_game *game)
{
	float	new_x;
	float	new_y;

	new_x = game->player.x;
	new_y = game->player.y;
	if (game->keys.up)
		new_y -= game->player.speed;
	if (game->keys.down)
		new_y += game->player.speed;
	if (game->keys.left)
		new_x -= game->player.speed;
	if (game->keys.right)
		new_x += game->player.speed;
	if (!check_map_collision(game, new_x, game->player.y))
		game->player.x = new_x;
	if (!check_map_collision(game, game->player.x, new_y))
		game->player.y = new_y;
}

int	update_game(void *param)
{
	static int	anim_time = 0;
	t_game		*game;

	game = (t_game *)param;
	collide_and_movement(game);
	camera_update(game);
	mlx_clear_window(game->mlx, game->window);
	render_map(game, &game->camera, &game->tilemap);
	update_sprite(&game->player, anim_time);
	update_enemy(game, &game->enemy);
	update_enemy_sprite(&game->enemy, anim_time);
	render_player(game, &game->player);
	render_enemy(game, &game->enemy);
	update_move_count(game, &game->player, game->tilemap.tile_size);
	collect_collectibles(game, &game->map, &game->player);
	exit_map(game, &game->map, &game->player);
	kill_player(game, &game->player, &game->enemy);
	anim_time++;
	return (NO_GAME_ERROR);
}
