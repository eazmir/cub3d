/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazmir <eazmir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 09:14:06 by eazmir            #+#    #+#             */
/*   Updated: 2025/12/10 00:27:21 by eazmir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../config.h"

char	**ft_cp_map(int fd, int height)
{
	char	**dest;
	char	*line;
	int		i;

	dest = ft_malloc(sizeof(char *) * (height + 1), 1);
	if (!dest)
		return (NULL);
	line = get_next_line(fd);
	i = 0;
	while (i < height && line)
	{
		dest[i] = ft_strdup(line);
		line = get_next_line(fd);
		i++;
	}
	dest[i] = NULL;
	return (dest);
}

char	**ft_remove_newline_from_map(t_cub *game, char **src, int height)
{
	char	*temp;
	char	**dest;
	int		i;
	int		j;
	int		len;

	dest = ft_malloc(sizeof(char *) * (height + 1), 1);
	i = 0;
	j = 0;
	while (i < height)
	{
		len = ft_strlen(src[i]);
		if (len > 0 && src[i][len - 1] == '\n')
		{
			temp = ft_substr(src[i], 0, len - 1);
			dest[j] = temp;
		}
		else
			dest[j] = ft_strdup(src[i]);
		j++;
		i++;
	}
	dest[j] = NULL;
	game->norm.height = j;
	return (dest);
}

int	ft_get_height(int fd)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		i++;
		line = get_next_line(fd);
	}
	return (i);
}

int	ft_missing_path(char *p)
{
	int	i;

	if (!p)
		return (0);
	i = ft_skip_space(p, 0);
	if ((p[i] == 'N' && p[i + 1] == 'O' && (p[i + 2] == '\0' || p[i
					+ 2] == '\n')) || (p[i] == 'S' && p[i + 1] == 'O' && (p[i
					+ 2] == '\0' || p[i + 2] == '\n')) || (p[i] == 'W' && p[i
				+ 1] == 'E' && (p[i + 2] == '\0' || p[i + 2] == '\n'))
		|| (p[i] == 'E' && p[i + 1] == 'A' && (p[i + 2] == '\0' || p[i
					+ 2] == '\n')))
	{
		return (1);
	}
	return (0);
}
