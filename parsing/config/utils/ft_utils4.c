/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazmir <eazmir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:51:13 by eazmir            #+#    #+#             */
/*   Updated: 2026/01/02 10:18:14 by eazmir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../config.h"

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r');
}

int	is_texture_line(char *line)
{
	if (!line)
		return (0);
	while (*line && ft_isspace(*line))
		line++;
	return (ft_strncmp(line, "NO", 2) == 0 || ft_strncmp(line, "SO", 2) == 0
		|| ft_strncmp(line, "WE", 2) == 0 || ft_strncmp(line, "EA", 2) == 0
		|| ft_strncmp(line, "F", 1) == 0 || ft_strncmp(line, "C", 1) == 0);
}

int	is_map_line(char *line)
{
	char	*ptr;

	if (!line)
		return (0);
	ptr = line;
	while (*ptr && ft_isspace(*ptr))
		ptr++;
	if (*ptr == '\0')
		return (0);
	if (ft_strncmp(ptr, "NO", 2) == 0 || ft_strncmp(ptr, "SO", 2) == 0
		|| ft_strncmp(ptr, "WE", 2) == 0 || ft_strncmp(ptr, "EA", 2) == 0
		|| ft_strncmp(ptr, "F", 1) == 0 || ft_strncmp(ptr, "C", 1) == 0)
		return (0);
	while (*ptr && (*ptr == '1' || *ptr == '0' || *ptr == 'N' || *ptr == 'S'
			|| *ptr == 'E' || *ptr == 'W' || *ptr == ' ' || *ptr == '\t'))
		ptr++;
	return (*ptr == '\0' || *ptr == '\n');
}

int	check_map_position(char **lines)
{
	int	map_started;
	int	i;

	map_started = 0;
	i = 0;
	while (lines[i])
	{
		if (is_map_line(lines[i]))
			map_started = 1;
		if (map_started && is_texture_line(lines[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}
