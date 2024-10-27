/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 02:46:45 by albernar          #+#    #+#             */
/*   Updated: 2024/10/24 02:46:46 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	start_game_init(t_game *game)
{
	int		game_err;

	game_err = player_init(game, game->map.playerpos_x,
			game->map.playerpos_y, game->tilemap.tile_size);
	if (game_err == INIT_ERROR)
		return (INIT_ERROR);
	game_err = map_init(game->mlx, &game->tilemap, game->tilemap.tile_size);
	if (game_err == INIT_ERROR)
		return (INIT_ERROR);
	game_err = init_enemy(game, &game->enemy);
	if (game_err == INIT_ERROR)
		return (INIT_ERROR);
	camera_init(game, &game->camera);
	init_key(game);
	return (game_err);
}

void	start_game_hooks(t_game *game)
{
	mlx_on_event(game->mlx, game->window, MLX_WINDOW_EVENT, window_hook, game);
	mlx_on_event(game->mlx, game->window, MLX_KEYDOWN, game_keydown_hook, game);
	mlx_on_event(game->mlx, game->window, MLX_KEYUP, game_keyup_hook, game);
	mlx_loop_hook(game->mlx, update_game, game);
}

void	init_window_size(t_game *game)
{
	game->width = 1024;
	game->height = 512;
	if (game->map.h * game->tilemap.tile_size < game->height)
		game->height = (game->map.h + 1) * game->tilemap.tile_size;
	if (game->map.w * game->tilemap.tile_size < game->width)
		game->width = (game->map.w + 1) * game->tilemap.tile_size;
}

void	free_game_assets(void *mlx, t_player *player,
	t_enemy *enemy, t_tilemap *tilemap)
{
	int	wall_count;
	int	death_img_count;

	wall_count = 9;
	death_img_count = 5;
	mlx_destroy_image(mlx, tilemap->collectible_img);
	mlx_destroy_image(mlx, tilemap->exit_img);
	mlx_destroy_image(mlx, tilemap->floor_img);
	mlx_destroy_image(mlx, tilemap->player_spawn_img);
	mlx_destroy_image(mlx, tilemap->spiderweb_img);
	while (player->sprite_count-- > 0)
		mlx_destroy_image(mlx, player->sprites[player->sprite_count]);
	while (enemy->sprite_count-- > 0)
		mlx_destroy_image(mlx, enemy->sprites[enemy->sprite_count]);
	while (enemy->sprite_count-- > 0)
		mlx_destroy_image(mlx, enemy->sprites[enemy->sprite_count]);
	while (death_img_count-- > 0)
		mlx_destroy_image(mlx, player->death_img[death_img_count]);
	while (wall_count-- > 0)
		mlx_destroy_image(mlx, tilemap->wall_img[wall_count]);
}

int	game_init(t_game *game)
{
	int	game_err;

	game->mlx = mlx_init();
	if (!game->mlx)
		return (INIT_MLX_ERROR);
	game->tilemap.tile_size = 32;
	init_window_size(game);
	game->window = mlx_new_window(game->mlx, game->width,
			game->height, "so_long");
	if (!game->window)
		return (INIT_WINDOW_ERROR);
	game_err = start_game_init(game);
	if (game_err != NO_GAME_ERROR)
		return (INIT_ERROR);
	start_game_hooks(game);
	mlx_loop(game->mlx);
	free_game_assets(game->mlx, &game->player, &game->enemy, &game->tilemap);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	return (game_err);
}
