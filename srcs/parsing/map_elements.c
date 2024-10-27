/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 21:27:59 by albernar          #+#    #+#             */
/*   Updated: 2024/10/20 21:28:00 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/map.h"
#include <stdio.h>

int	map_check_elements_count(t_map *map)
{
	if (map->playerpos_count == 0)
		return (NO_PLAYER_POS);
	if (map->playerpos_x <= 0 && map->playerpos_x >= map->h)
		return (INVALID_PLAYER_POS);
	if (map->playerpos_y <= 0 && map->playerpos_y >= map->w)
		return (INVALID_PLAYER_POS);
	if (map->playerpos_count > 1)
		return (TOO_MANY_PLAYER_POS);
	if (map->exit_count == 0)
		return (NO_EXIT);
	if (map->exit_count > 1)
		return (TOO_MANY_EXIT);
	if (map->collectible_count == 0)
		return (NO_COLLECTIBLES);
	return (NO_ERROR);
}

int	map_check_elements(t_map *map)
{
	int	map_diff;
	int	i;
	int	j;

	i = -1;
	map_init_elements(map);
	while (++i <= map->h)
	{
		j = -1;
		while (++j <= map->w)
		{
			if (*(*(map->grid + i) + j) == 'P')
				map_add_player_pos(map, j, i);
			else if (*(*(map->grid + i) + j) == 'C')
				map->collectible_count++;
			else if (*(*(map->grid + i) + j) == 'E')
				map_look_for_exit(map, j, i);
			else if (*(*(map->grid + i) + j) != '0'
				&& *(*(map->grid + i) + j) != '1')
				return (MAP_INVALID_CHAR);
		}
	}
	map_diff = map_check_elements_count(map);
	return (map_diff);
}

int	map_process_floodfill(t_map *map, int **visited)
{
	int	map_diff;
	int	i;
	int	j;

	i = -1;
	map_diff = NO_ERROR;
	while (++i < map->h)
	{
		j = -1;
		while (++j < map->w)
		{
			if (*(*(map->grid + i) + j) == 'C' && !*(*(visited + i) + j))
				map->collectible_count--;
			if (*(*(map->grid + i) + j) == 'E' && !*(*(visited + i) + j))
				map_diff = UNREACHABLE_EXIT;
		}
	}
	if (map_diff == NO_ERROR && map->collectible_count <= 0)
		map_diff = NO_REACHABLE_COLLECTIBLES;
	free_floodfill(visited, map->h);
	return (map_diff);
}

void	map_floodfill(t_map *map, int start_x, int start_y, int **visited)
{
	int	**stack;
	int	top;

	top = 0;
	stack = floodfill_stack_init(map->w * map->h);
	if (!stack)
	{
		free_floodfill(visited, map->h);
		return ;
	}
	floodfill_stack_push(stack, &top, start_x, start_y);
	visited[start_y][start_x] = 1;
	while (top > 0)
		floodfill_stack_fill(stack, visited, &top, map);
	floodfill_stack_free(stack, map->w * map->h);
}

int	map_start_floodfill(t_map *map)
{
	int	map_diff;
	int	i;
	int	j;
	int	**visited;

	visited = malloc(sizeof(int *) * (map->h + 1));
	if (!visited)
		return (MEM_ERROR);
	i = -1;
	map_diff = NO_ERROR;
	while (++i < map->h + 1)
	{
		j = -1;
		*(visited + i) = malloc(sizeof(int) * (map->w + 1));
		if (!*(visited + i))
		{
			free_floodfill(visited, i);
			return (MEM_ERROR);
		}
		while (++j < (map->w + 1))
			*(*(visited + i) + j) = 0;
	}
	map_floodfill(map, map->playerpos_x, map->playerpos_y, visited);
	map_diff = map_process_floodfill(map, visited);
	return (map_diff);
}
