/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_config.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazmir <eazmir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 07:42:03 by eazmir            #+#    #+#             */
/*   Updated: 2025/12/09 23:21:28 by eazmir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../debug/debug.h"
#include "../include/parsing.h"
#include "config.h"

int	ft_getcolors(t_cub *game)
{
	if (!check_color_duplicate(game->norm.cp_map, game->norm.height))
	{
		error("there must be exactly one ceiling color and one floor color.!");
		return (0);
	}
	if (!check_ceiling_color(game))
		return (0);
	if (!check_floor_color(game))
		return (0);
	return (1);
}

int	ft_config(t_cub *game, t_texturse *txt)
{
	int		fd;
	int		height;
	char	**src;

	fd = open(game->file, O_RDONLY);
	if (fd < 0)
		return (0);
	height = ft_get_height(fd);
	lseek(fd, 0, SEEK_SET);
	src = ft_cp_map(fd, height);
	if (!check_map_position(src))
	{
		error("map must be last");
		close(fd);
		return (0);
	}
	game->norm.cp_map = ft_remove_newline_from_map(game, src, height);
	game->grid = ft_cp2d(game, game->norm.cp_map, game->norm.height);
	if (!game->grid)
		return (0);
	game->width = get_map_width(game->grid);
	if (!ft_check_txt_error(game, txt))
		return (0);
	close(fd);
	return (1);
}

void	the_end(t_cub *game, t_texturse *txt)
{
	int	*pos_player;

	if (!ft_check_status_file(game->file))
	{
		ft_malloc(0, 0);
		exit(0);
	}
	if (!ft_config(game, txt))
	{
		ft_malloc(0, 0);
		exit(0);
	}
	pos_player = ft_get_position(game->grid, game->height, game->width);
	game->player_x = pos_player[0];
	game->player_y = pos_player[1];
}

int	init_game(t_cub **game, t_texturse **txt, char *file)
{
	*game = ft_malloc(sizeof(t_cub), 1);
	*txt = ft_malloc(sizeof(t_texturse), 1);
	if (!*game || !*txt)
	{
		error("Error: malloc failed\n");
		return (0);
	}
	init_cub(*game);
	init_texturse(*txt);
	(*game)->file = file;
	the_end(*game, *txt);
	return (1);
}
