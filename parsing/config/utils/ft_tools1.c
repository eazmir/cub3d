/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazmir <eazmir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 08:25:51 by eazmir            #+#    #+#             */
/*   Updated: 2025/12/28 08:25:53 by eazmir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../config.h"

int	ft_texturse_formate(char *key, int i)
{
	if (!key)
		return (0);
	if (!key[i] || !key[i + 1])
		return (0);
	if (key[i] == 'N' && key[i + 1] == 'O')
		return (1);
	if (key[i] == 'S' && key[i + 1] == 'O')
		return (2);
	if (key[i] == 'W' && key[i + 1] == 'E')
		return (3);
	if (key[i] == 'E' && key[i + 1] == 'A')
		return (4);
	return (0);
}

int	ft_checker(char *line)
{
	int	i;

	if (!line)
		return (0);
	i = ft_skip_space(line, 0);
	if (!line[i] || !line[i + 1] || !line[i + 2])
		return (0);
	if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
		return (1);
	if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
		return (2);
	if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
		return (3);
	if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
		return (4);
	return (0);
}

int	ft_checker2(char *line)
{
	int	i;

	if (!line)
		return (0);
	i = ft_skip_space(line, 0);
	if (!line[i] || !line[i + 1])
		return (0);
	if (line[i] == 'N' && line[i + 1] == 'O')
		return (1);
	if (line[i] == 'S' && line[i + 1] == 'O')
		return (2);
	if (line[i] == 'W' && line[i + 1] == 'E')
		return (3);
	if (line[i] == 'E' && line[i + 1] == 'A')
		return (4);
	return (0);
}

int	ft_checker3(char *line)
{
	int	i;

	if (!line)
		return (0);
	i = ft_skip_space(line, 0);
	if (!line[i])
		return (0);
	if (line[i] == 'F')
		return (5);
	if (line[i] == 'C')
		return (6);
	if (!line[i + 1])
		return (0);
	if (line[i] == 'N' && line[i + 1] == 'O')
		return (1);
	if (line[i] == 'S' && line[i + 1] == 'O')
		return (2);
	if (line[i] == 'W' && line[i + 1] == 'E')
		return (3);
	if (line[i] == 'E' && line[i + 1] == 'A')
		return (4);
	return (0);
}

int	ft_force_checker(char *s)
{
	if (!s || !s[0])
		return (0);
	if (ft_strncmp(s, "NO", 2) == 0 || ft_strncmp(s, "SO", 2) == 0
		|| ft_strncmp(s, "WE", 2) == 0 || ft_strncmp(s, "EA", 2) == 0)
	{
		if (s[2] == ' ' || s[2] == '\t')
			return (1);
		return (0);
	}
	return (0);
}
