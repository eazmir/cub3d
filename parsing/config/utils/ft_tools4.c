/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazmir <eazmir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 13:43:09 by eazmir            #+#    #+#             */
/*   Updated: 2026/01/03 15:16:48 by eazmir           ###   ########.fr       */
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

int	get_content_bounds(char *line, int *first, int *last)
{
	int	j;

	*first = -1;
	*last = -1;
	j = 0;
	while (line[j])
	{
		if (is_map_content(line[j]))
		{
			if (*first == -1)
				*first = j;
			*last = j;
		}
		j++;
	}
	return (*first != -1);
}

int	ft_check_single_line(char *line, int first, int last)
{
	int	j;
	int	k;
	int	gap_size;

	j = first;
	while (j <= last)
	{
		if (line[j] == ' ' || line[j] == '\t')
		{
			gap_size = 0;
			k = j;
			while (k <= last && (line[k] == ' ' || line[k] == '\t'))
			{
				gap_size++;
				k++;
			}
			if (gap_size > 2 && k <= last && is_map_content(line[k]))
				return (0);
		}
		j++;
	}
	return (1);
}

int	check_trailing_map_content(char **map, int height)
{
	int	i;
	int	first_valid;
	int	last_valid;

	i = 0;
	while (i < height)
	{
		if (get_content_bounds(map[i], &first_valid, &last_valid))
		{
			if (!ft_check_single_line(map[i], first_valid, last_valid))
				return (0);
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
