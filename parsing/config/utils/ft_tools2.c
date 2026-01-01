/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazmir <eazmir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 09:31:23 by eazmir            #+#    #+#             */
/*   Updated: 2026/01/01 19:33:33 by eazmir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../config.h"

int	is_invalid_space(char **map_copy, int i, int j, int height)
{
	if (i < 0 || i >= height)
		return (1);
	if (j < 0)
		return (1);
	if (j >= (int)ft_strlen(map_copy[i]))
		return (1);
	if (map_copy[i][j] == '1' || map_copy[i][j] == 'V')
		return (0);
	if (map_copy[i][j] == ' ' || map_copy[i][j] == '\t')
		return (1);
	map_copy[i][j] = 'V';
	if (is_invalid_space(map_copy, i - 1, j, height))
		return (1);
	if (is_invalid_space(map_copy, i + 1, j, height))
		return (1);
	if (is_invalid_space(map_copy, i, j - 1, height))
		return (1);
	if (is_invalid_space(map_copy, i, j + 1, height))
		return (1);
	return (0);
}

int	ft_is_only_digits(char *s)
{
	int		i;
	char	*str_clean;

	if (!s)
		return (0);
	str_clean = trim_string(s);
	i = 0;
	while (str_clean[i])
	{
		if (!ft_isdigit(str_clean[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_isvalid(char *r, char *g, char *b)
{
	if (!r || !g || !b)
		return (0);
	if (!ft_is_only_digits(r))
		return (0);
	if (!ft_is_only_digits(g))
		return (0);
	if (!ft_is_only_digits(b))
		return (0);
	return (1);
}

void	remove_space_newline(char *str)
{
	int	len;

	if (!str)
		return ;
	len = ft_strlen(str);
	while (len > 0)
	{
		if (str[len - 1] == ' ' || str[len - 1] == '\t' || str[len - 1] == '\n'
			|| str[len - 1] == '\r')
		{
			str[len - 1] = '\0';
			len--;
		}
		else
		{
			break ;
		}
	}
}

char	**get_copy(char **src, int height)
{
	char	**dest;
	int		i;

	dest = ft_malloc(sizeof(char *) * (height + 1), 1);
	i = 0;
	while (i < height)
	{
		dest[i] = ft_strdup(src[i]);
		i++;
	}
	dest[i] = NULL;
	return (dest);
}
