/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazmir <eazmir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 00:28:14 by eazmir            #+#    #+#             */
/*   Updated: 2025/12/28 08:26:28 by eazmir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../config.h"

char	*ft_strtrim_color(char *str)
{
	char	*start;
	char	*end;
	char	*res;
	int		len;
	int		i;

	start = str;
	while (*start == ' ' || *start == '\t')
		start++;
	end = start + ft_strlen(start) - 1;
	while (end > start && (*end == ' ' || *end == '\t'))
		end--;
	len = end - start + 1;
	res = ft_malloc(len + 1, 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = start[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int	is_valid_rgb_component(char *str, char key)
{
	int	i;
	int	digit_found;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || (str[i] == key)))
		i++;
	digit_found = 0;
	while (str[i] && ft_isdigit(str[i]))
	{
		digit_found = 1;
		i++;
	}
	if (!digit_found)
		return (0);
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

char	**get_rgb_components(char **maps, char key, int height)
{
	char	*line;
	char	**rgb;
	int		i;

	line = ft_getlines(maps, key, height);
	if (!line)
		return (NULL);
	i = 0;
	while (line[i])
	{
		if (line[i] == ',' && line[i + 1] == ',')
			return (NULL);
		i++;
	}
	rgb = ft_split(line, ',');
	i = 0;
	while (i < 3)
	{
		if (!rgb[i] || !is_valid_rgb_component(rgb[i], key))
			return (NULL);
		i++;
	}
	if (ft_count_color(rgb) != 3)
		return (NULL);
	return (rgb);
}

char	*clean_component(char *value, char key, int is_first)
{
	char	*trimmed;
	int		i;

	i = ft_skip_space(value, 0);
	if (is_first && value[i] == key)
		i++;
	trimmed = ft_strtrim_color(value + i);
	if (!trimmed || trimmed[0] == '\n' || trimmed[0] == '\0')
		return (NULL);
	return (trimmed);
}
