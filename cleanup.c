/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazmir <eazmir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 08:24:32 by eazmir            #+#    #+#             */
/*   Updated: 2026/01/01 15:37:09 by eazmir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"
#include "rendering/rendering.h"
#include <stdlib.h>

int	exit_game(t_game *game)
{
	clean_resource(game);
	ft_malloc(0, 0);
	exit(0);
	return (0);
}

void	clean_up(t_game *game)
{
	clean_resource(game);
	ft_malloc(0, 0);
	exit(0);
}
