/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazmir <eazmir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 17:35:51 by eazmir            #+#    #+#             */
/*   Updated: 2026/01/03 18:15:38 by eazmir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"
#include "mlx/mlx.h"
#include "rendering/rendering.h"

static int	init_game_struct(t_game **game)
{
	(*game)->mlx = mlx_init();
	if (!(*game)->mlx)
	{
		free(*game);
		return (0);
	}
	return (1);
}

static int	setup_window(t_game *game)
{
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	if (!game->win)
		return (0);
	return (1);
}

static void	setup_hooks(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, key_hook, game);
	mlx_hook(game->win, 17, 0, exit_game, game);
	mlx_hook(game->win, 12, 1L << 15, expose_hook, game);
}

int	main(int argc, char *argv[])
{
	t_game	*game;

	game = ft_malloc(sizeof(t_game), 1);
	ft_memset(game, 0, sizeof(t_game));
	if (!start(argc, argv, game))
		return (0);
	if (!init_game_struct(&game))
		return (0);
	if (!init_render(game))
	{
		printf("Error\nFailed to initialize rendering\n");
		return (0);
	}
	if (!setup_window(game))
		return (0);
	render(game);
	setup_hooks(game);
	mlx_loop(game->mlx);
	return (0);
}
