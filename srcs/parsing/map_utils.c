/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 15:24:01 by albernar          #+#    #+#             */
/*   Updated: 2024/10/20 15:24:02 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/map.h"

void	map_look_for_exit(t_map *map, int x, int y)
{
	map->exit_posx = x;
	map->exit_posy = y;
	map->exit_count++;
}

void	map_add_player_pos(t_map *map, int x, int y)
{
	map->playerpos_x = x;
	map->playerpos_y = y;
	map->playerpos_count++;
}

int	map_isber(char *map_path)
{
	size_t	map_pathlen;

	map_pathlen = ft_strlen(map_path);
	if (map_pathlen - 4 <= 0)
		return (INVALID_FILE_FORMAT);
	map_pathlen -= 4;
	map_path += map_pathlen;
	if (!map_path)
		return (INVALID_FILE_FORMAT);
	if (ft_strncmp(map_path, ".ber", 4) == 0)
		return (NO_ERROR);
	return (INVALID_FILE_FORMAT);
}

void	map_init_elements(t_map *map)
{
	map->playerpos_count = 0;
	map->collectible_count = 0;
	map->exit_count = 0;
	map->exit_posx = 0;
	map->exit_posy = 0;
	map->playerpos_x = 0;
	map->playerpos_y = 0;
}
