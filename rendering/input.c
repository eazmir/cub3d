/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazmir <eazmir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 08:23:16 by eazmir            #+#    #+#             */
/*   Updated: 2026/01/01 15:53:50 by eazmir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit_game(game);
	else if (keycode == KEY_W)
		move_forward(game);
	else if (keycode == KEY_S)
		move_backward(game);
	else if (keycode == KEY_A)
		move_left(game);
	else if (keycode == KEY_D)
		move_right(game);
	else if (keycode == KEY_LEFT)
		rotate_left(game);
	else if (keycode == KEY_RIGHT)
		rotate_right(game);
	render(game);
	return (0);
}

int	clean_resource(t_game *game)
{
	if (game->render)
	{
		if (game->render->img.img)
			mlx_destroy_image(game->mlx, game->render->img.img);
		if (game->render->tex_north.img)
			mlx_destroy_image(game->mlx, game->render->tex_north.img);
		if (game->render->tex_south.img)
			mlx_destroy_image(game->mlx, game->render->tex_south.img);
		if (game->render->tex_east.img)
			mlx_destroy_image(game->mlx, game->render->tex_east.img);
		if (game->render->tex_west.img)
			mlx_destroy_image(game->mlx, game->render->tex_west.img);
	}
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	return (0);
}
