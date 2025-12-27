/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazmir <eazmir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 14:44:31 by eazmir            #+#    #+#             */
/*   Updated: 2025/12/17 22:07:12 by eazmir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../config.h"

int	is_grid(char *s)
{
	while (*s == ' ' || *s == '\t')
		s++;
	return (*s == '1' || *s == '0');
}

int	is_empty(char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	return (s[i] == '\0');
}

char	**get_texturse(char **line, int height)
{
	int		i;
	int		j;
	char	**txt;

	i = 0;
	j = 0;
	txt = ft_malloc(sizeof(char *) * (height + 1), 1);
	if (!txt)
		return (NULL);
	while (i < height)
	{
		if (ft_missing_path(line[i]))
			return (NULL);
		if (ft_checker(line[i]))
			txt[j++] = line[i];
		i++;
	}
	txt[j] = NULL;
	return (txt);
}

char	**ft_parse_txt_from_map(t_texturse *txt, char **map, int height)
{
	int		i;
	int		j;
	char	**p;
	char	*t;

	p = ft_malloc(sizeof(char *) * 5, 1);
	if (!p)
		return (NULL);
	i = 0;
	j = 0;
	while (i < height)
	{
		if (ft_checker(map[i]))
		{
			t = ft_parse_txtrse(map[i], txt);
			if (t)
				p[j++] = t;
		}
		i++;
	}
	p[j] = NULL;
	return (p);
}

int	is_valid_extension(char *path)
{
	char	*last_dot;
	int		i;

	remove_space_newline(path);
	last_dot = ft_strrchr(path, '.');
	if (!last_dot || ft_strcmp(last_dot, ".xpm") != 0)
		return (0);
	i = 0;
	while (path[i])
	{
		if (path[i] == '.' && path[i + 1] == '.')
			return (0);
		i++;
	}
	return (1);
}
