/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazmir <eazmir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 17:33:56 by eazmir            #+#    #+#             */
/*   Updated: 2026/01/03 17:34:00 by eazmir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
# define RENDERING_H

# include "../include/cub3d.h"
# include "../mlx/mlx.h"
# include <math.h>
# include <stdlib.h>

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720
# define TEX_WIDTH 64
# define TEX_HEIGHT 64
# define MOVE_SPEED 0.1
# define ROT_SPEED 0.1
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_img;

typedef struct s_player
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
}				t_player;

typedef struct s_ray
{
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		wall_x;
	int			tex_x;
	double		step;
	double		tex_pos;
}				t_ray;

typedef struct s_render
{
	t_player	player;
	t_img		img;
	t_img		tex_north;
	t_img		tex_south;
	t_img		tex_east;
	t_img		tex_west;
}				t_render;

/* Initialization */
int				init_render(t_game *game);
void			init_player(t_game *game);
void			set_player_direction(t_game *game, char direction);
int				load_textures(t_game *game);

/* Rendering */
void			render(t_game *game);
void			raycast(t_game *game);
void			draw_column(t_game *game, t_ray *ray, int x);
void			draw_floor_ceiling(t_game *game);
int				expose_hook(t_game *game);

/* Ray calculations */
void			init_ray(t_game *game, t_ray *ray, int x);
void			set_step_and_side_dist(t_game *game, t_ray *ray);
void			perform_dda(t_game *game, t_ray *ray);
void			calculate_wall_distance(t_game *game, t_ray *ray);
void			calculate_texture_x(t_game *game, t_ray *ray);
t_img			*get_wall_texture(t_game *game, t_ray *ray);

/* Input handling */
int				key_hook(int keycode, t_game *game);
int				clean_resource(t_game *game);
int				exit_game(t_game *game);

/* Movement */
void			move_forward(t_game *game);
void			move_backward(t_game *game);
void			move_left(t_game *game);
void			move_right(t_game *game);
void			rotate_left(t_game *game);
void			rotate_right(t_game *game);

/* Utils */
void			my_mlx_pixel_put(t_img *img, int x, int y, int color);
int				get_pixel_color(t_img *img, int x, int y);
int				is_wall(t_game *game, double x, double y);
int				check_collision(t_game *game, double x, double y);

#endif
