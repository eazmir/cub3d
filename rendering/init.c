/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med <med@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 00:00:00 by med               #+#    #+#             */
/*   Updated: 2025/12/27 06:58:06 by med              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "rendering.h"

void	init_player(t_game *game)
{
	char	direction;
	double	pos_x;
	double	pos_y;

	direction = game->cub->grid[game->cub->player_y][game->cub->player_x];
	pos_x = (double)game->cub->player_x + 0.5;
	pos_y = (double)game->cub->player_y + 0.5;
	if (pos_x < 1.5)
		pos_x = 1.5;
	if (pos_y < 1.5)
		pos_y = 1.5;
	if (pos_x > game->cub->width - 1.5)
		pos_x = game->cub->width - 1.5;
	if (pos_y > game->cub->height - 1.5)
		pos_y = game->cub->height - 1.5;
	game->render->player.pos_x = pos_x;
	game->render->player.pos_y = pos_y;
	set_player_direction(game, direction);
}

int	load_texture_image(t_game *game, t_img *texture, char *path)
{
	texture->img = mlx_xpm_file_to_image(game->mlx, path, &texture->width,
			&texture->height);
	if (!texture->img)
		return (0);
	texture->addr = mlx_get_data_addr(texture->img, &texture->bits_per_pixel,
			&texture->line_length, &texture->endian);
	if (!texture->addr)
		return (0);
	return (1);
}

int	load_textures(t_game *game)
{
	if (!load_texture_image(game, &game->render->tex_north, game->txt->no))
	{
		printf("Error\nFailed to load north texture: %s\n", game->txt->no);
		return (0);
	}
	if (!load_texture_image(game, &game->render->tex_south, game->txt->so))
	{
		printf("Error\nFailed to load south texture: %s\n", game->txt->so);
		return (0);
	}
	if (!load_texture_image(game, &game->render->tex_east, game->txt->ea))
	{
		printf("Error\nFailed to load east texture: %s\n", game->txt->ea);
		return (0);
	}
	if (!load_texture_image(game, &game->render->tex_west, game->txt->we))
	{
		printf("Error\nFailed to load west texture: %s\n", game->txt->we);
		return (0);
	}
	return (1);
}

int	init_render(t_game *game)
{
	game->render = ft_malloc(sizeof(t_render), 1);
	if (!game->render)
		return (0);
	game->render->img.img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!game->render->img.img)
		return (0);
	game->render->img.addr = mlx_get_data_addr(game->render->img.img,
			&game->render->img.bits_per_pixel, &game->render->img.line_length,
			&game->render->img.endian);
	if (!game->render->img.addr)
		return (0);
	game->render->img.width = WIN_WIDTH;
	game->render->img.height = WIN_HEIGHT;
	game->render->tex_north.img = NULL;
	game->render->tex_south.img = NULL;
	game->render->tex_east.img = NULL;
	game->render->tex_west.img = NULL;
	init_player(game);
	if (!load_textures(game))
		cleanup_game(game);
	return (1);
}
