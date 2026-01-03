/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazmir <eazmir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 08:23:39 by eazmir            #+#    #+#             */
/*   Updated: 2026/01/03 17:31:24 by eazmir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

int	expose_hook(t_game *game)
{
	render(game);
	return (0);
}

void	raycast(t_game *game)
{
	t_ray	ray;
	int		x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		init_ray(game, &ray, x);
		set_step_and_side_dist(game, &ray);
		perform_dda(game, &ray);
		calculate_wall_distance(game, &ray);
		draw_column(game, &ray, x);
		x++;
	}
}

void	render(t_game *game)
{
	draw_floor_ceiling(game);
	raycast(game);
	mlx_put_image_to_window(game->mlx, game->win,
		game->render->img.img, 0, 0);
}
