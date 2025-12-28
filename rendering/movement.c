/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazmir <eazmir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 08:23:22 by eazmir            #+#    #+#             */
/*   Updated: 2025/12/28 08:23:24 by eazmir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

void	move_forward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->render->player.pos_x
		+ game->render->player.dir_x * MOVE_SPEED;
	new_y = game->render->player.pos_y
		+ game->render->player.dir_y * MOVE_SPEED;
	if (!check_collision(game, new_x, game->render->player.pos_y))
		game->render->player.pos_x = new_x;
	if (!check_collision(game, game->render->player.pos_x, new_y))
		game->render->player.pos_y = new_y;
}

void	move_backward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->render->player.pos_x
		- game->render->player.dir_x * MOVE_SPEED;
	new_y = game->render->player.pos_y
		- game->render->player.dir_y * MOVE_SPEED;
	if (!check_collision(game, new_x, game->render->player.pos_y))
		game->render->player.pos_x = new_x;
	if (!check_collision(game, game->render->player.pos_x, new_y))
		game->render->player.pos_y = new_y;
}

void	move_left(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->render->player.pos_x
		- game->render->player.plane_x * MOVE_SPEED;
	new_y = game->render->player.pos_y
		- game->render->player.plane_y * MOVE_SPEED;
	if (!check_collision(game, new_x, game->render->player.pos_y))
		game->render->player.pos_x = new_x;
	if (!check_collision(game, game->render->player.pos_x, new_y))
		game->render->player.pos_y = new_y;
}

void	move_right(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->render->player.pos_x
		+ game->render->player.plane_x * MOVE_SPEED;
	new_y = game->render->player.pos_y
		+ game->render->player.plane_y * MOVE_SPEED;
	if (!check_collision(game, new_x, game->render->player.pos_y))
		game->render->player.pos_x = new_x;
	if (!check_collision(game, game->render->player.pos_x, new_y))
		game->render->player.pos_y = new_y;
}
