/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazmir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:40:02 by eazmir            #+#    #+#             */
/*   Updated: 2025/08/29 11:28:33 by eazmir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

int	ft_check_for_player(char **maps, int *i, int *j)
{
	if (maps[*i][*j] == 'N' || maps[*i][*j] == 'S' || maps[*i][*j] == 'W'
		|| maps[*i][*j] == 'E')
		return (1);
	return (0);
}

int	ft_check_player(char **maps, int height, int width)
{
	int	i;
	int	j;
	int	c;
	int	l;

	(void)width;
	i = 0;
	c = 0;
	while (i < height)
	{
		j = 0;
		l = ft_strlen(maps[i]);
		while (j < l)
		{
			if (ft_check_for_player(maps, &i, &j))
				c++;
			if (c > 1)
				return (0);
			j++;
		}
		i++;
	}
	if (c == 0)
		return (0);
	return (1);
}

int	*ft_get_position(char **map, int height, int width)
{
	int	i;
	int	j;
	int	*pos_xy;

	i = 0;
	pos_xy = ft_malloc(sizeof(int) * 2, 1);
	while (i < height)
	{
		j = 0;
		width = ft_strlen(map[i]);
		while (j < width)
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W'
				|| map[i][j] == 'E')
			{
				pos_xy[0] = i;
				pos_xy[1] = j;
				return (pos_xy);
			}
			j++;
		}
		i++;
	}
	return (0);
}
