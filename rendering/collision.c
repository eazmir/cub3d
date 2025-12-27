/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med <med@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 00:00:00 by med               #+#    #+#             */
/*   Updated: 2025/12/27 06:52:26 by med              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

int	is_wall(t_game *game, double x, double y)
{
	int	ix;
	int	iy;

	ix = (int)x;
	iy = (int)y;
	if (iy < 0 || iy >= game->cub->height || ix < 0)
		return (1);
	if (!game->cub->grid[iy])
		return (1);
	if (ix >= (int)ft_strlen(game->cub->grid[iy]))
		return (1);
	if (game->cub->grid[iy][ix] == '1' || game->cub->grid[iy][ix] == ' ')
		return (1);
	return (0);
}

int	check_collision(t_game *game, double x, double y)
{
	double	radius;

	radius = 0.25;
	if (is_wall(game, x + radius, y + radius))
		return (1);
	if (is_wall(game, x - radius, y + radius))
		return (1);
	if (is_wall(game, x + radius, y - radius))
		return (1);
	if (is_wall(game, x - radius, y - radius))
		return (1);
	return (0);
}
