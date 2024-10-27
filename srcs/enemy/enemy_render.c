/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 02:15:00 by albernar          #+#    #+#             */
/*   Updated: 2024/10/27 02:15:01 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_enemy(t_game *game, t_enemy *enemy)
{
	int	screen_x;
	int	screen_y;

	screen_x = enemy->x - game->camera.x;
	screen_y = enemy->y - game->camera.y;
	mlx_put_image_to_window(game->mlx, game->window,
		enemy->sprites[enemy->current_sprite], screen_x, screen_y);
}
