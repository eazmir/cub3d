/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med <med@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 00:00:00 by med               #+#    #+#             */
/*   Updated: 2025/12/27 06:58:06 by med              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

static int	is_hit(t_game *game, t_ray *ray)
{
	if (ray->map_y < 0 || ray->map_y >= game->cub->height || ray->map_x < 0)
		return (1);
	if (!game->cub->grid[ray->map_y])
		return (1);
	if (ray->map_x >= (int)ft_strlen(game->cub->grid[ray->map_y]))
		return (1);
	if (game->cub->grid[ray->map_y][ray->map_x] == '1'
		|| game->cub->grid[ray->map_y][ray->map_x] == ' ')
		return (1);
	return (0);
}

void	perform_dda(t_game *game, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (is_hit(game, ray))
			ray->hit = 1;
	}
}
