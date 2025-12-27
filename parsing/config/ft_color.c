/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_config.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazmir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 15:42:57 by eazmir            #+#    #+#             */
/*   Updated: 2025/08/25 15:43:03 by eazmir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

int	ft_convert_color(int red, int green, int blue)
{
	int	color;

	color = (red << 16) | (green << 8) | blue;
	return (color);
}

char	**ft_split_color(char **maps, char key, int height)
{
	char	**rgb;
	char	**result;

	rgb = get_rgb_components(maps, key, height);
	if (!rgb)
	{
		return (NULL);
	}
	result = ft_malloc(4 * sizeof(char *), 1);
	if (!result)
		return (NULL);
	result[0] = clean_component(rgb[0], key, 1);
	result[1] = clean_component(rgb[1], key, 0);
	result[2] = clean_component(rgb[2], key, 0);
	result[3] = NULL;
	if (!result[0] || !result[1] || !result[2])
		return (NULL);
	return (result);
}

int	ft_color_format(char **maps, char key, int height)
{
	char	**rgb;
	int		r;
	int		g;
	int		b;

	rgb = ft_split_color(maps, key, height);
	if (!rgb)
		return (-3);
	else if (!ft_check_empty_values(rgb))
		return (-3);
	else if (!get_rgb_components(maps, key, height))
		return (-4);
	else if (!ft_isvalid(rgb[0], rgb[1], rgb[2]))
		return (-3);
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	if (r < 0 || g < 0 || b < 0)
		return (-2);
	else if (r > 255 || g > 255 || b > 255)
		return (-1);
	return (ft_convert_color(r, g, b));
}

int	check_floor_color(t_cub *game)
{
	game->f_color = ft_color_format(game->norm.cp_map, 'F', game->norm.height);
	if (game->f_color == -2)
		return (error("Floor color values must be positive"), 0);
	if (game->f_color == -1)
		return (error("Floor color values must be between (0,255)"), 0);
	if (game->f_color == -3)
		return (error("Floor color definition is missing or incomplete"), 0);
	if (game->f_color == -4)
		return (error("Floor color must have exactly 3 values (R,G,B)"), 0);
	return (1);
}

int	check_ceiling_color(t_cub *game)
{
	game->c_color = ft_color_format(game->norm.cp_map, 'C', game->norm.height);
	if (game->c_color == -2)
		return (error("Ceiling color values must be positive"), 0);
	if (game->c_color == -1)
		return (error("Ceiling color values must be between (0,255)"), 0);
	if (game->c_color == -3)
		return (error("Ceiling color definition is missing or incomplete"), 0);
	if (game->c_color == -4)
		return (error("Ceiling color must have exactly 3 values (R,G,B)"), 0);
	return (1);
}
