/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazmir <eazmir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 08:24:57 by eazmir            #+#    #+#             */
/*   Updated: 2026/01/01 19:32:20 by eazmir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

int	ft_check_border_row(char *row)
{
	int	j;
	int	len;

	j = 0;
	len = ft_strlen(row);
	if (len > 0 && row[len - 1] == '\n')
		len--;
	while (j < len)
	{
		if (row[j] != '1' && row[j] != ' ' && row[j] != '\t')
			return (0);
		j++;
	}
	return (1);
}

int	ft_check_middle_row(char *row)
{
	int	j;
	int	len;

	len = ft_strlen(row);
	if (len > 0 && row[len - 1] == '\n')
		len--;
	j = 0;
	while (j < len && (row[j] == ' ' || row[j] == '\t'))
		j++;
	if (j < len && row[j] != '1')
		return (0);
	j = len - 1;
	while (j >= 0 && (row[j] == ' ' || row[j] == '\t'))
		j--;
	if (row[j] != '1')
		return (0);
	return (1);
}

int	ft_check_close_walls(char **maps, int height, int width)
{
	int	i;

	(void)width;
	i = 0;
	while (i < height)
	{
		if (i == 0 || i == height - 1)
		{
			if (!ft_check_border_row(maps[i]))
				return (0);
		}
		else
		{
			if (!ft_check_middle_row(maps[i]))
				return (0);
		}
		i++;
	}
	return (1);
}

int	ft_check_characters(char **map, int height, int width)
{
	int	i;
	int	j;
	int	l;

	(void)width;
	i = 0;
	while (i < height)
	{
		j = 0;
		l = ft_strlen(map[i]);
		while (j < l)
		{
			if (l == 1)
				return (0);
			if (!ft_strchr("10NSEW \t", map[i][j]))
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_space_on_map(char **map, int height, int width)
{
	int		i;
	int		j;
	char	**cop_map;

	i = 0;
	cop_map = get_copy(map, height);
	while (i < height)
	{
		width = ft_strlen(map[i]);
		j = 0;
		while (j < width && cop_map[i][j])
		{
			if (cop_map[i][j] == 'N' || cop_map[i][j] == '0'
				|| cop_map[i][j] == 'S' || cop_map[i][j] == 'E'
				|| cop_map[i][j] == 'W')
			{
				if (is_invalid_space(cop_map, i, j, height))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
