/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texturse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazmir <eazmir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 15:44:23 by eazmir            #+#    #+#             */
/*   Updated: 2025/12/10 00:22:08 by eazmir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

char	*ft_parse_txtrse(char *path, t_texturse *txt)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	i = ft_skip_space(path, 0);
	if (ft_texturse_formate(path, i))
	{
		i += 2;
		i = ft_skip_space(path, i);
		j = ft_skip_space(path, j);
		if (ft_texturse_formate(path, j) == 1)
			return (txt->no = ft_strdup(path + i));
		else if (ft_texturse_formate(path, j) == 2)
			return (txt->so = ft_strdup(path + i));
		else if (ft_texturse_formate(path, j) == 3)
			return (txt->we = ft_strdup(path + i));
		else if (ft_texturse_formate(path, j) == 4)
			return (txt->ea = ft_strdup(path + i));
		else
			return (NULL);
	}
	return (NULL);
}

int	force_checker(char **s, int height)
{
	int		i;
	char	*p;
	int		c;
	int		j;

	i = 0;
	c = 0;
	while (i < height && (s[i][0] == '\n'))
		i++;
	while (i < height && c < 4)
	{
		j = ft_skip_space(s[i], 0);
		p = ft_substr(s[i] + j, 0, 3);
		if (!ft_force_checker(p))
			return (0);
		c++;
		i++;
	}
	return (1);
}

int	ft_check_mltple_txtrse(char **maps, int height)
{
	int	i;
	int	id;
	int	c[5];

	if (!maps[0] || !maps)
		return (0);
	ft_memset(c, 0, sizeof(c));
	if (!force_checker(maps, height))
		return (-1);
	i = 0;
	while (i < height)
	{
		id = ft_checker2(maps[i]);
		if (id > 0)
		{
			c[id]++;
			if (c[id] > 1)
				return (0);
		}
		i++;
	}
	return (1);
}

int	ft_validate_texture_format(char **p)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!p[i])
			return (0);
		if (!is_valid_extension(p[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_txt_isvald(t_cub *game, t_texturse *txt)
{
	int		txt_count;
	char	**txt1;
	char	**p;

	txt1 = get_texturse(game->norm.cp_map, game->norm.height);
	if (!txt1)
		return (-3);
	txt_count = 0;
	while (txt1[txt_count])
		txt_count++;
	if (ft_check_mltple_txtrse(txt1, txt_count) == -1)
		return (-1);
	if (!ft_check_mltple_txtrse(txt1, txt_count))
		return (0);
	p = ft_parse_txt_from_map(txt, txt1, txt_count);
	if (!ft_validate_texture_format(p))
		return (-2);
	return (1);
}
