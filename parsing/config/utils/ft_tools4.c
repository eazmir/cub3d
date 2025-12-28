/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazmir <eazmir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 13:43:09 by eazmir            #+#    #+#             */
/*   Updated: 2025/12/28 08:26:13 by eazmir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../config.h"

int	get_map_width(char **map)
{
	int	max_width;
	int	current_width;
	int	i;

	max_width = 0;
	i = 0;
	while (map[i])
	{
		current_width = ft_strlen(map[i]);
		if (current_width > max_width)
			max_width = current_width;
		i++;
	}
	return (max_width);
}

int	check_trailing_map_content(char **map, int height)
{
	int	i;
	int	j;
	int	found_end;

	i = 0;
	while (i < height)
	{
		j = 0;
		found_end = 0;
		while (map[i][j])
		{
			if (found_end && (map[i][j] == '1' || map[i][j] == '0'))
				return (0);
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'N'
				&& map[i][j] != 'S' && map[i][j] != 'E' && map[i][j] != 'W'
				&& map[i][j] != ' ' && map[i][j] != '\t' && map[i][j] != '\n')
				return (1);
			if ((map[i][j] == ' ' || map[i][j] == '\t') && j > 0 && (map[i][j
					- 1] == '1' || map[i][j - 1] == '0'))
				found_end = 1;
			j++;
		}
		i++;
	}
	return (1);
}

int	check_color_duplicate(char **maps, int height)
{
	int	i;
	int	j;
	int	c;
	int	f;

	f = 0;
	c = 0;
	i = 0;
	while (i < height)
	{
		j = 0;
		while (maps[i][j])
		{
			if (is_key_followed_by_space_or_end(maps, i, j, 'C'))
				c++;
			if (is_key_followed_by_space_or_end(maps, i, j, 'F'))
				f++;
			j++;
		}
		i++;
	}
	if (c != 1 || f != 1)
		return (0);
	return (1);
}

int	ft_count_color(char **rgb)
{
	int	c;

	if (!rgb)
		return (0);
	c = 0;
	while (rgb[c])
		c++;
	return (c);
}

int	ft_check_empty_values(char **rgb)
{
	int	i;

	i = 0;
	while (rgb[i])
	{
		if (rgb[i][0] == '\0')
			return (0);
		i++;
	}
	return (1);
}
