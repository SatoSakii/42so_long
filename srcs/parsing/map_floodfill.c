/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_floodfill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 22:35:13 by albernar          #+#    #+#             */
/*   Updated: 2024/10/26 22:35:14 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	**floodfill_stack_init(int size)
{
	int	**stack;
	int	i;

	stack = malloc(sizeof(int *) * size);
	if (!stack)
		return (NULL);
	i = 0;
	while (i < size)
	{
		stack[i] = malloc(sizeof(int) * 2);
		if (!stack[i++])
		{
			while (--i >= 0)
				free(stack[i]);
			free(stack);
			return (NULL);
		}
	}
	return (stack);
}

void	floodfill_stack_push(int **stack, int *top, int x, int y)
{
	stack[*top][0] = x;
	stack[*top][1] = y;
	(*top)++;
}

void	floodfill_stack_pop(int **stack, int *top, int *x, int *y)
{
	(*top)--;
	*x = stack[*top][0];
	*y = stack[*top][1];
}

int	floodfill_valid_move(int **visited, char **grid, int coord[2], t_map *map)
{
	int	new_x;
	int	new_y;
	int	w;
	int	h;

	new_x = coord[0];
	new_y = coord[1];
	w = map->w;
	h = map->h;
	if (new_x < 0 || new_x >= w || new_y < 0 || new_y >= h)
		return (0);
	if (visited[new_y][new_x] || (grid[new_y][new_x] != '0'
			&& grid[new_y][new_x] != 'E' && grid[new_y][new_x] != 'C'))
		return (0);
	return (1);
}

void	floodfill_stack_fill(int **stack, int **visited, int *top, t_map *map)
{
	static int	directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	int			coord[2];
	int			new_coord[2];
	int			i;

	floodfill_stack_pop(stack, top, &coord[0], &coord[1]);
	i = -1;
	while (++i < 4)
	{
		new_coord[0] = coord[0] + directions[i][1];
		new_coord[1] = coord[1] + directions[i][0];
		if (floodfill_valid_move(visited, map->grid, new_coord, map))
		{
			floodfill_stack_push(stack, top, new_coord[0], new_coord[1]);
			visited[new_coord[1]][new_coord[0]] = 1;
		}
	}
}
