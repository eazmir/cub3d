/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazmir <eazmir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 08:25:36 by eazmir            #+#    #+#             */
/*   Updated: 2026/01/03 11:25:28 by eazmir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define RESET "\033[0m"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"

typedef struct s_texturse
{
	int		height;
	int		width;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*img_no;
	char	*img_so;
	char	*img_we;
	char	*img_ea;
}			t_texturse;

typedef struct s_norm
{
	char	**cp_map;
	int		height;
}			t_norm;

typedef struct s_cub
{
	char	**grid;
	int		c_color;
	int		f_color;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	char	*file;
	t_norm	norm;
}			t_cub;

int			ft_checker2(char *line);
int			ft_check_space_on_map(char **map, int height, int width);
int			check_trailing_map_content(char **map, int height);
int			ft_getcolors(t_cub *game);
int			ft_check_txt_error(t_cub *game, t_texturse *txt);
int			ft_check_mltple_txtrse(char **maps, int height);
int			ft_check_error(char **map, int height, int width);
int			ft_check_player(char **maps, int height, int width);
int			ft_check_close_walls(char **maps, int height, int width);
int			ft_check_characters(char **map, int height, int width);
int			*ft_get_position(char **map, int height, int width);
int			ft_check_txt_isvald(t_cub *game, t_texturse *txt);
int			ft_skip_space(char *s, int i);
int			ft_check(char *s);
int			ft_get_height(int fd);
int			ft_texturse_formate(char *key, int i);
int			ft_checker(char *line);
int			ft_force_checker(char *s);
int			ft_isvalid(char *r, char *g, char *b);
int			is_invalid_space(char **map_copy, int i, int j, int height);
int			ft_check_empty_values(char **rgb);
int			check_floor_color(t_cub *game);
int			check_ceiling_color(t_cub *game);
int			is_map_line(char *line);
int			is_grid(char *s);
int			check_map_position(char **lines);
int			is_texture_definition(char *line);
int			ft_checker3(char *line);
int			is_empty(char *s);
int			is_valid_extension(char *path);
int			get_map_width(char **map);
int			ft_check_empty_values(char **rgb);
int			ft_count_color(char **rgb);
int			check_trailing_map_content(char **map, int height);
int			check_color_duplicate(char **maps, int height);
int			ft_missing_path(char *p);
int			is_map_content(char c);
int			is_key_followed_by_space_or_end(char **maps, int i, int j,
				char key);
char		*ft_parse_txtrse(char *path, t_texturse *txt);
char		**get_texturse(char **line, int height);
char		**ft_parse_txt_from_map(t_texturse *txt, char **map, int height);
char		*clean_component(char *value, char key, int is_first);
char		**get_rgb_components(char **maps, char key, int height);
char		**get_copy(char **src, int height);
char		*trim_string(char *s);
char		*ft_getlines(char **maps, char key, int height);
char		**ft_cp2d(t_cub *game, char **src, int height);
char		**ft_cp_map(int fd, int height);
char		**ft_remove_newline_from_map(t_cub *game, char **src, int height);
void		error(char *str);
void		init_texturse(t_texturse *txt);
void		init_cub(t_cub *cub);
void		remove_space_newline(char *str);
void		ft_remove_newline(char *str);
bool		ft_check_status_file(char *file);
#endif