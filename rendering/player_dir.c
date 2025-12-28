/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazmir <eazmir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 08:23:28 by eazmir            #+#    #+#             */
/*   Updated: 2025/12/28 08:23:30 by eazmir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

static void	set_north_dir(t_player *player)
{
	player->dir_x = 0;
	player->dir_y = -1;
	player->plane_x = 0.66;
	player->plane_y = 0;
}

static void	set_south_dir(t_player *player)
{
	player->dir_x = 0;
	player->dir_y = 1;
	player->plane_x = -0.66;
	player->plane_y = 0;
}

static void	set_east_dir(t_player *player)
{
	player->dir_x = 1;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = 0.66;
}

static void	set_west_dir(t_player *player)
{
	player->dir_x = -1;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = -0.66;
}

void	set_player_direction(t_game *game, char direction)
{
	if (direction == 'N')
		set_north_dir(&game->render->player);
	else if (direction == 'S')
		set_south_dir(&game->render->player);
	else if (direction == 'E')
		set_east_dir(&game->render->player);
	else if (direction == 'W')
		set_west_dir(&game->render->player);
	else
		set_south_dir(&game->render->player);
}
