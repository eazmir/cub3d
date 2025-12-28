/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazmir <eazmir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 08:23:01 by eazmir            #+#    #+#             */
/*   Updated: 2025/12/28 08:23:03 by eazmir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

static void	draw_ceiling(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT / 2)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			my_mlx_pixel_put(&game->render->img, x, y, game->cub->c_color);
			x++;
		}
		y++;
	}
}

static void	draw_floor(t_game *game)
{
	int	x;
	int	y;

	y = WIN_HEIGHT / 2;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			my_mlx_pixel_put(&game->render->img, x, y, game->cub->f_color);
			x++;
		}
		y++;
	}
}

void	draw_floor_ceiling(t_game *game)
{
	draw_ceiling(game);
	draw_floor(game);
}
