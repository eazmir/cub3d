/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med <med@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 00:00:00 by med               #+#    #+#             */
/*   Updated: 2025/12/27 07:02:57 by med              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"
#include "mlx/mlx.h"
#include "rendering/rendering.h"

static int	init_game_struct(t_game **game)
{
	*game = malloc(sizeof(t_game));
	if (!*game)
		return (0);
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
}

int	main(int argc, char *argv[])
{
	t_game	*game;

	if (!init_game_struct(&game))
		return (0);
	if (!start(argc, argv, game))
	{
		return (0);
	}
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
