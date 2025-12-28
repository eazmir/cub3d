/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazmir <eazmir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 09:13:56 by eazmir            #+#    #+#             */
/*   Updated: 2025/12/28 08:26:20 by eazmir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../config.h"

void	ft_remove_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			str[i] = '\0';
			break ;
		}
		i++;
	}
}

int	ft_skip_space(char *s, int i)
{
	if (!s)
		return (i);
	while (s[i] && (s[i] == ' ' || s[i] == '\t'))
		i++;
	return (i);
}

char	*trim_string(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n' || s[i] == ' ' || s[i] == '\t')
			s[i] = '\0';
		i++;
	}
	return (s);
}

int	ft_check(char *s)
{
	int	i;

	i = ft_skip_space(s, 0);
	if (s[i] == 'F')
		return (1);
	else if (s[i] == 'C')
		return (1);
	return (0);
}

char	*ft_getlines(char **maps, char key, int height)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		if (ft_check(maps[i]))
		{
			j = ft_skip_space(maps[i], 0);
			if (maps[i][j] == key)
			{
				return (maps[i]);
			}
		}
		i++;
	}
	return (NULL);
}
