/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file_validity.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazmir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 10:15:08 by eazmir            #+#    #+#             */
/*   Updated: 2025/08/22 11:36:02 by eazmir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

bool	ft_check_file_exist(char *file)
{
	if (access(file, F_OK | R_OK) != 0)
	{
		return (false);
	}
	return (true);
}

bool	ft_check_file_extntion(char *file)
{
	int		i;
	char	*excub;

	excub = ft_strrchr(file, '.');
	i = 0;
	while (file[i])
	{
		if (ft_strlen(excub) == 4 && ft_strcmp(excub, ".cub") == 0)
		{
			return (true);
		}
		else
			return (false);
		i++;
	}
	return (false);
}

bool	ft_check_status_file(char *file)
{
	if (file)
	{
		if (!ft_check_file_exist(file))
		{
			error("file does not exist");
			return (false);
		}
		else if (!ft_check_file_extntion(file))
		{
			error("Invalid file extension. Must be .cub");
			return (false);
		}
	}
	return (true);
}
