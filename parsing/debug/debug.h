/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazmir <eazmir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 11:03:34 by eazmir            #+#    #+#             */
/*   Updated: 2025/12/28 08:27:12 by eazmir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include "../include/parsing.h"

void						debug_game(t_cub *game, t_texturse *txt);
void						debug_color(const char *name, int color);
#endif
