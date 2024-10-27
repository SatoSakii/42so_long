/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:44:22 by albernar          #+#    #+#             */
/*   Updated: 2024/10/19 19:44:22 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/map.h"

void	floodfill_stack_free(int **stack, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(stack[i++]);
	free(stack);
}

void	free_map(t_map *map)
{
	char	**tmp_map;

	tmp_map = map->grid;
	while (*map->grid)
		free(*map->grid++);
	free(tmp_map);
}

void	free_floodfill(int **visited, int size)
{
	int	i;

	i = -1;
	while (++i < size + 1)
		free(*(visited + i));
	free(visited);
}
