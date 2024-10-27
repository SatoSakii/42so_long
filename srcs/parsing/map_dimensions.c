/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dimensions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:11:42 by albernar          #+#    #+#             */
/*   Updated: 2024/10/20 16:11:42 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/map.h"

int	map_isrect(t_map *map)
{
	if (map->h == map->w)
		return (SQUARE_MAP);
	return (NO_ERROR);
}

int	map_surrounded_by_walls(t_map *map)
{
	int	i;
	int	map_diff;

	map_diff = NO_ERROR;
	i = -1;
	while (++i <= map->w)
		if (*(*(map->grid) + i) != '1')
			map_diff = NOT_SURROUNDED_BY_WALLS;
	i = -1;
	while (++i <= map->w)
		if (*(*(map->grid + map->h) + i) != '1')
			map_diff = NOT_SURROUNDED_BY_WALLS;
	i = -1;
	while (++i <= map->h)
		if (*(*(map->grid + i)) != '1')
			map_diff = NOT_SURROUNDED_BY_WALLS;
	i = -1;
	while (++i <= map->h)
		if (*(*(map->grid + i) + map->w) != '1')
			map_diff = NOT_SURROUNDED_BY_WALLS;
	return (map_diff);
}

int	map_getwidth(t_map *map)
{
	char	**map_ptr;
	int		map_diff;
	size_t	w;

	w = ft_strlen(*map->grid);
	map_ptr = map->grid;
	map_diff = NO_ERROR;
	while (*map_ptr)
	{
		if (ft_strlen(*map_ptr) != w)
		{
			map_diff = INVALID_WIDTH;
			break ;
		}
		map_ptr++;
	}
	if (w <= 2)
		map_diff = INVALID_WIDTH;
	map->w = w - 1;
	return (map_diff);
}

int	map_getheight(t_map *map)
{
	char	**map_ptr;
	int		map_diff;
	size_t	h;

	map_ptr = map->grid;
	map_diff = NO_ERROR;
	h = 0;
	while (*map_ptr)
	{
		h++;
		map_ptr++;
	}
	if (h <= 2)
		map_diff = INVALID_HEIGHT;
	map->h = h - 1;
	return (map_diff);
}
