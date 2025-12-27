/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med <med@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 00:00:00 by med               #+#    #+#             */
/*   Updated: 2025/12/27 05:54:18 by med              ###   ########.fr       */
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
