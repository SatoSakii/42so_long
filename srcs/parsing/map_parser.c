/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 17:58:12 by albernar          #+#    #+#             */
/*   Updated: 2024/10/19 17:58:13 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	read_map(char *map_path, t_map *map)
{
	int		read_diff;
	char	*map_buf;
	int		map_fd;
	char	*line;

	map_fd = open(map_path, O_RDONLY);
	line = get_next_line(map_fd);
	map_buf = ft_strdup("");
	read_diff = NO_ERROR;
	while (line)
	{
		map_buf = ft_strjoin(map_buf, line, 1, 1);
		line = get_next_line(map_fd);
	}
	map->grid = ft_split(map_buf, '\n');
	if (!map || !*map->grid)
		read_diff = MAP_READ_FAIL;
	close(map_fd);
	free(map_buf);
	return (read_diff);
}

int	parse_elements(t_map *map)
{
	int	check_1;
	int	check_2;

	if (map_surrounded_by_walls(map) == NOT_SURROUNDED_BY_WALLS)
		return (NOT_SURROUNDED_BY_WALLS);
	check_1 = map_check_elements(map);
	if (check_1 != NO_ERROR)
		return (check_1);
	check_2 = map_start_floodfill(map);
	if (check_2 != NO_ERROR)
		return (check_2);
	return (NO_ERROR);
}

void	*parse_map(char *map_path, t_game *game)
{
	t_map_err	map_err;

	map_err = NO_ERROR;
	if (map_isber(map_path) == INVALID_FILE_FORMAT)
		map_err = INVALID_FILE_FORMAT;
	else if (read_map(map_path, &game->map) == MAP_READ_FAIL)
		map_err = MAP_READ_FAIL;
	else if (map_getwidth(&game->map) == INVALID_WIDTH)
		map_err = INVALID_WIDTH;
	else if (map_getheight(&game->map) == INVALID_HEIGHT)
		map_err = INVALID_HEIGHT;
	else if (map_isrect(&game->map) == SQUARE_MAP)
		map_err = SQUARE_MAP;
	if (map_err == NO_ERROR)
		map_err = parse_elements(&game->map);
	if (map_err != NO_ERROR)
	{
		if (map_err > INVALID_FILE_FORMAT)
			free_map(&game->map);
		map_error_handler(map_err);
		return (NULL);
	}
	return ((void *)1);
}
