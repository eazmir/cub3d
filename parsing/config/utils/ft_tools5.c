/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazmir <eazmir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 11:22:56 by eazmir            #+#    #+#             */
/*   Updated: 2026/01/03 16:54:48 by eazmir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_empty_values(char **rgb)
{
	int	i;

	i = 0;
	while (rgb[i])
	{
		if (rgb[i][0] == '\0')
			return (0);
		i++;
	}
	return (1);
}

int	ft_count_color(char **rgb)
{
	int	c;

	if (!rgb)
		return (0);
	c = 0;
	while (rgb[c])
		c++;
	return (c);
}

int	is_map_content(char c)
{
	return (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'E'
		|| c == 'W');
}
