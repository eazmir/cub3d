/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazmir <eazmir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 11:10:52 by eazmir            #+#    #+#             */
/*   Updated: 2026/01/01 13:21:47 by eazmir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug/debug.h"
#include "include/parsing.h"

int	start(int ac, char **args, t_game *game)
{
	t_cub		*cub;
	t_texturse	*txt;

	if (ac != 2)
	{
		printf("Usage: ./cub <map_file.cub>\n");
		return (0);
	}
	if (!init_game(&cub, &txt, args[1]))
	{
		ft_malloc(0, 0);
		return (0);
	}
	game->cub = cub;
	game->txt = txt;
	return (1);
}
