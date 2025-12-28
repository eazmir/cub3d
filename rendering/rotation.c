/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazmir <eazmir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 08:23:51 by eazmir            #+#    #+#             */
/*   Updated: 2025/12/28 08:23:53 by eazmir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

void	rotate_left(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->render->player.dir_x;
	game->render->player.dir_x = game->render->player.dir_x * cos(-ROT_SPEED)
		- game->render->player.dir_y * sin(-ROT_SPEED);
	game->render->player.dir_y = old_dir_x * sin(-ROT_SPEED)
		+ game->render->player.dir_y * cos(-ROT_SPEED);
	old_plane_x = game->render->player.plane_x;
	game->render->player.plane_x = game->render->player.plane_x
		* cos(-ROT_SPEED) - game->render->player.plane_y * sin(-ROT_SPEED);
	game->render->player.plane_y = old_plane_x * sin(-ROT_SPEED)
		+ game->render->player.plane_y * cos(-ROT_SPEED);
}

void	rotate_right(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->render->player.dir_x;
	game->render->player.dir_x = game->render->player.dir_x * cos(ROT_SPEED)
		- game->render->player.dir_y * sin(ROT_SPEED);
	game->render->player.dir_y = old_dir_x * sin(ROT_SPEED)
		+ game->render->player.dir_y * cos(ROT_SPEED);
	old_plane_x = game->render->player.plane_x;
	game->render->player.plane_x = game->render->player.plane_x
		* cos(ROT_SPEED) - game->render->player.plane_y * sin(ROT_SPEED);
	game->render->player.plane_y = old_plane_x * sin(ROT_SPEED)
		+ game->render->player.plane_y * cos(ROT_SPEED);
}
