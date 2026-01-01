/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazmir <eazmir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 08:26:02 by eazmir            #+#    #+#             */
/*   Updated: 2025/12/30 18:37:59 by eazmir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../config.h"

int	is_map_empty(char **src)
{
	int	i;
	int	j;

	i = 0;
	if (!src || !src[0])
		return (1);
	while (src[i])
	{
		j = 0;
		while (src[i][j])
		{
			if (src[i][j] == '1' || src[i][j] == '0' || src[i][j] == 'N'
				|| src[i][j] == 'S' || src[i][j] == 'E' || src[i][j] == 'W')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static void	get_map_bounds(char **src, int height, int *start, int *end)
{
	int	i;

	*start = -1;
	*end = -1;
	i = 0;
	while (i < height && *start == -1)
	{
		if (!ft_checker3(src[i]) && !is_empty(src[i]))
			*start = i;
		i++;
	}
	i = height - 1;
	while (i >= 0 && *end == -1)
	{
		if (!ft_checker3(src[i]) && !is_empty(src[i]))
			*end = i;
		i--;
	}
}

static char	**copy_map_grid(t_cub *game, char **src, int start, int end)
{
	char	**dest;
	int		i;
	int		j;

	dest = ft_malloc(sizeof(char *) * (end - start + 2), 1);
	if (!dest)
		return (NULL);
	j = 0;
	i = start;
	while (i <= end)
	{
		if (!src[i])
			break ;
		if (!ft_checker3(src[i]) && src[i][0] != '\n')
		{
			ft_remove_newline(src[i]);
			dest[j++] = ft_strdup(src[i]);
		}
		i++;
	}
	dest[j] = NULL;
	game->height = j;
	return (dest);
}

char	**ft_cp2d(t_cub *game, char **src, int height)
{
	int	start;
	int	end;

	if (is_map_empty(src))
	{
		error("the file is empty");
		return (NULL);
	}
	get_map_bounds(src, height, &start, &end);
	if (start > height || end > height || start >= end)
	{
		error("No map found in file");
		return (NULL);
	}
	return (copy_map_grid(game, src, start, end));
}

int	is_key_followed_by_space_or_end(char **maps, int i, int j, char key)
{
	if ((maps[i][j] == key && maps[i][j + 1] == ' ') || (maps[i][j] == key
			&& maps[i][j + 1] == '\0'))
		return (1);
	return (0);
}
