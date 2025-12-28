/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazmir <eazmir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 08:24:51 by eazmir            #+#    #+#             */
/*   Updated: 2025/12/28 08:24:53 by eazmir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

void	error(char *str)
{
	ft_putstr_fd(RED "Error : " RESET, 2);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
}

int	ft_check_eorr(char **map, int height, int width)
{
	if (ft_check_close_walls(map, height, width) == 0)
	{
		error("map must be surrounded by walls");
		return (0);
	}
	else if (ft_check_characters(map, height, width) == 0)
	{
		error("map contains invalid characters");
		return (0);
	}
	else if (ft_check_space_on_map(map, height, width) == 0)
	{
		error("Map contains invalid spaces");
		return (0);
	}
	else if (check_trailing_map_content(map, height) == 0)
	{
		error("Map has disconnected sections or trailing content");
		return (0);
	}
	return (1);
}

int	ft_check_error(char **map, int height, int width)
{
	if (ft_check_eorr(map, height, width) != 1)
		return (0);
	else if (!ft_check_player(map, height, width))
	{
		error("map most have only one player");
		return (0);
	}
	return (1);
}

int	ft_check_txt_error(t_cub *game, t_texturse *txt)
{
	if (!ft_getcolors(game))
		return (0);
	else if (!ft_check_error(game->grid, game->height, game->width))
		return (0);
	else if (ft_check_txt_isvald(game, txt) == -3)
	{
		error("missing path");
		return (0);
	}
	else if (ft_check_txt_isvald(game, txt) == 0)
	{
		error("Missing texture");
		return (0);
	}
	else if (ft_check_txt_isvald(game, txt) == -1)
	{
		error("Only one of each texture is allowed (NO,SO,WE,EA)");
		return (0);
	}
	else if (ft_check_txt_isvald(game, txt) == -2)
	{
		error("Texture files must have .xpm extension");
		return (0);
	}
	return (1);
}
