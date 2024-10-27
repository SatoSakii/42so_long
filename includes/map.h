/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 15:23:57 by albernar          #+#    #+#             */
/*   Updated: 2024/10/20 15:23:58 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include "../lib/libft/libft.h"
# include <stdlib.h>

typedef struct s_game	t_game;

typedef struct s_map
{
	char	**grid;
	int		w;
	int		h;
	int		playerpos_count;
	int		collectible_count;
	int		exit_count;
	int		playerpos_x;
	int		playerpos_y;
	int		exit_posx;
	int		exit_posy;
}	t_map;

typedef enum e_map_err
{
	NO_ERROR,
	INVALID_FILE_FORMAT,
	MAP_READ_FAIL,
	MAP_INVALID_CHAR,
	INVALID_WIDTH,
	INVALID_HEIGHT,
	SQUARE_MAP,
	NOT_SURROUNDED_BY_WALLS,
	NO_PLAYER_POS,
	INVALID_PLAYER_POS,
	TOO_MANY_PLAYER_POS,
	NO_EXIT,
	TOO_MANY_EXIT,
	UNREACHABLE_EXIT,
	NO_COLLECTIBLES,
	NO_REACHABLE_COLLECTIBLES,
	MEM_ERROR
}	t_map_err;

void	map_add_player_pos(t_map *map, int x, int y);
void	map_look_for_exit(t_map *map, int x, int y);
void	*parse_map(char *map_path, t_game *game);
void	free_map(t_map *map);
int		floodfill_valid_move(int **visited, char **grid,
			int coord[2], t_map *map);
void	floodfill_stack_fill(int **stack, int **visited, int *top, t_map *map);
void	floodfill_stack_pop(int **stack, int *top, int *x, int *y);
void	floodfill_stack_push(int **stack, int *top, int x, int y);
int		**floodfill_stack_init(int size);
void	floodfill_stack_free(int **stack, int size);
void	free_floodfill(int **visited, int size);
int		map_isber(char *map_path);
int		map_isrect(t_map *map);
int		map_surrounded_by_walls(t_map *map);
int		map_getwidth(t_map *map);
int		map_getheight(t_map *map);
int		map_check_elements(t_map *map);
int		map_check_elements_count(t_map *map);
void	map_init_elements(t_map *map);
int		map_start_floodfill(t_map *map);
void	map_error_handler(t_map_err type);

#endif