/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 02:36:56 by albernar          #+#    #+#             */
/*   Updated: 2024/10/24 02:36:57 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_player(t_game *game, t_player *player)
{
	int	screen_x;
	int	screen_y;

	screen_x = player->x - game->camera.x;
	screen_y = player->y - game->camera.y;
	mlx_put_image_to_window(game->mlx, game->window,
		player->sprites[player->current_sprite], screen_x, screen_y);
}
