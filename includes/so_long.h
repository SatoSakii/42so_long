/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 16:52:13 by albernar          #+#    #+#             */
/*   Updated: 2024/10/19 16:53:48 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../lib/libft/libft.h"
# include "./map.h"
# include "../lib/MacroLibX/includes/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef enum e_error_code
{
	NO_GAME_ERROR,
	INIT_ERROR,
	INIT_MLX_ERROR,
	INIT_WINDOW_ERROR
}	t_error_code;

typedef struct s_tilemap
{
	void	*wall_img[9];
	void	*floor_img;
	void	*spiderweb_img;
	void	*player_spawn_img;
	void	*collectible_img;
	void	*exit_img;
	int		tile_size;
}	t_tilemap;

typedef struct s_camera
{
	float	x;
	float	y;
	float	speed;
	int		width;
	int		height;
}	t_camera;

typedef struct s_enemy
{
	float	x;
	float	y;
	float	speed;
	int		direction;
	void	*sprites[4];
	int		current_sprite;
	int		sprite_count;
	int		last_frame_time;
	int		frame_time;
}	t_enemy;

typedef struct s_player
{
	float	x;
	float	y;
	float	speed;
	void	*sprites[4];
	void	*death_img[5];
	int		move_count;
	int		current_sprite;
	int		sprite_count;
	int		last_frame_time;
	int		frame_time;
}	t_player;

typedef struct s_game_keys
{
	int		up;
	int		down;
	int		right;
	int		left;
}	t_game_keys;

typedef struct s_game
{
	t_map			map;
	void			*mlx;
	void			*window;
	int				width;
	int				height;
	t_player		player;
	t_enemy			enemy;
	t_tilemap		tilemap;
	t_camera		camera;
	t_game_keys		keys;
}	t_game;

// UTILS
int		ft_printf(const char *s, ...);
char	*get_next_line(int fd);

// PLAYER
void	update_sprite(t_player *player, int current_time);
int		player_init(t_game *game, int x, int y, int tilesize);
void	render_player(t_game *game, t_player *player);
void	update_move_count(t_game *game, t_player *player, int tilesize);
void	collect_collectibles(t_game *game, t_map *map, t_player *player);
void	exit_map(t_game *game, t_map *map, t_player *player);

// ENEMY
int		init_enemy(t_game *game, t_enemy *enemy);
void	update_enemy(t_game *game, t_enemy *enemy);
void	update_enemy_sprite(t_enemy *enemy, int current_time);
void	render_enemy(t_game *game, t_enemy *enemy);
void	kill_player(t_game *game, t_player *player, t_enemy *enemy);

// MAP
int		map_init(void *mlx, t_tilemap *tilemap, int ts);
int		check_map_collision(t_game *game, float new_x, float new_y);
void	init_points(int points[4][2], int new_x, int new_y, int tile_size);
void	render_wall(t_game *game, t_camera *camera, int screen_x, int screen_y);
void	render_floor(t_game *game, int screen_x, int screen_y);
void	render_others(t_game *game, char type, int screen_x, int screen_y);
void	render_map(t_game *game, t_camera *camera, t_tilemap *tilemap);

// HOOKS
int		window_hook(int event, void *param);
int		game_keydown_hook(int key, void *param);
int		game_keyup_hook(int key, void *param);
int		update_game(void *param);

// CAMERA
void	camera_init(t_game *game, t_camera *camera);
void	camera_update(t_game *game);

// GAME
int		game_init(t_game *game);
void	init_key(t_game *game);

// ERRORS
void	game_error_handler(t_error_code type);

#endif
