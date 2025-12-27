/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med <med@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 00:00:00 by med               #+#    #+#             */
/*   Updated: 2025/12/27 06:52:26 by med              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

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
