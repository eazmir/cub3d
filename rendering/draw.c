/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med <med@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 00:00:00 by med               #+#    #+#             */
/*   Updated: 2025/12/27 06:52:26 by med              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

void	draw_column(t_game *game, t_ray *ray, int x)
{
	t_img	*texture;
	int		y;
	int		tex_y;
	int		color;

	calculate_texture_x(game, ray);
	texture = get_wall_texture(game, ray);
	ray->step = 1.0 * TEX_HEIGHT / ray->line_height;
	ray->tex_pos = (ray->draw_start - WIN_HEIGHT / 2
			+ ray->line_height / 2) * ray->step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		tex_y = (int)ray->tex_pos & (TEX_HEIGHT - 1);
		ray->tex_pos += ray->step;
		color = get_pixel_color(texture, ray->tex_x, tex_y);
		my_mlx_pixel_put(&game->render->img, x, y, color);
		y++;
	}
}
