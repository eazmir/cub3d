/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazmir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 10:36:06 by eazmir            #+#    #+#             */
/*   Updated: 2025/09/05 10:37:08 by eazmir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

void	init_texturse(t_texturse *txt)
{
	txt->no = NULL;
	txt->so = NULL;
	txt->we = NULL;
	txt->ea = NULL;
	txt->img_no = NULL;
	txt->img_so = NULL;
	txt->img_we = NULL;
	txt->img_ea = NULL;
}

void	init_map(t_cub *map)
{
	map->grid = NULL;
	map->c_color = 0;
	map->f_color = 0;
	map->width = 0;
	map->height = 0;
	map->player_x = 0;
	map->player_y = 0;
}

void	init_norm(t_norm *norm)
{
	norm->cp_map = NULL;
	norm->height = 0;
}

void	init_cub(t_cub *cub)
{
	cub->file = NULL;
	init_norm(&cub->norm);
	init_map(cub);
}
