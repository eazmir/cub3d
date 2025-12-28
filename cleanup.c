/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazmir <eazmir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 08:24:32 by eazmir            #+#    #+#             */
/*   Updated: 2025/12/28 08:24:35 by eazmir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"
#include "rendering/rendering.h"
#include <stdlib.h>

void	cleanup_game(t_game *game)
{
	ft_malloc(0, 0);
	exit_game(game);
}
