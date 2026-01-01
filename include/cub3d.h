/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazmir <eazmir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 13:29:09 by eazmir            #+#    #+#             */
/*   Updated: 2026/01/01 13:48:06 by eazmir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../parsing/include/parsing.h"
# include "../parsing/libft/libft.h"
# include "../parsing/config/config.h"

typedef struct s_render	t_render;

typedef struct s_game
{
	t_cub		*cub;
	t_texturse	*txt;
	t_render	*render;
	void		*mlx;
	void		*win;
}				t_game;

int				start(int ac, char **args, t_game *game);
void			clean_up(t_game *game);
#endif
