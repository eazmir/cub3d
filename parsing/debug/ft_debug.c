/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazmir <eazmir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 12:51:58 by eazmir            #+#    #+#             */
/*   Updated: 2025/12/28 08:27:18 by eazmir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

void	debug_color(const char *name, int color)
{
	int	r;
	int	g;
	int	b;

	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = color & 0xFF;
	printf("%s: %d -> (R:%d, G:%d, B:%d)\n", name, color, r, g, b);
}

void	debug_game(t_cub *game, t_texturse *txt)
{
	int	i;

	i = 0;
	printf("===== DEBUG GAME =====\n");
	printf("Map width: %d\n", game->width);
	printf("Map height: %d\n", game->height);
	debug_color("Floor", game->f_color);
	debug_color("Ceiling", game->c_color);
	printf("\nTextures:\n");
	printf("  NO: -> %s\n", txt->no);
	printf("  SO: -> %s\n", txt->so);
	printf("  WE: -> %s\n", txt->we);
	printf("  EA: -> %s\n", txt->ea);
	printf("\nMap grid:\n");
	while (i < game->height && game->grid[i])
	{
		printf("%s\n", game->grid[i]);
		i++;
	}
	printf("======================\n");
}
