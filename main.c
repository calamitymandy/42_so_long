/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdemuyn <amdemuyn@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:15:34 by amdemuyn          #+#    #+#             */
/*   Updated: 2023/04/27 14:39:25 by amdemuyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_struct(t_game *game)
{
	game->fd = 0;
	game->map_height = 0;
	game->map_width = 0;
	game->perso_count = 0;
	game->item_count = 0;
	game->exit_count = 0;
	game->x_axis = 0;
	game->y_axis = 0;
	game->counter = 0;
	game->items = 0;
	game->map = NULL;
	game->floor = 0;
	game->wall = 0;
	game->perso = 0;
	game->exit = 0;
	game->item = 0;
	game->mlx = 0;
	game->window = 0;
}

int	exit_window(t_game *game)
{
	int	line;

	line = 0;
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	free(game->mlx);
	while (line < game->map_height - 1)
		free(game->map[line++]);
	free(game->map);
	exit(0);
}

/**
 * The main function initializes a game struct, reads a map file, checks for errors, creates a window,
 * places images, adds graphics, sets up controls, and starts the game loop.
 * 
 * @param argc The number of arguments passed to the program, including the name of the program itself.
 * @param argv The argv parameter is a pointer to an array of characters that represent the
 * command-line arguments passed to the program. In this specific code, it is used to read the name of
 * the map file that the game will use.
 * 
 * @return If the number of arguments passed to the program is not 2, then 0 is being returned.
 * Otherwise, the program runs and does not return anything.
 */
int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (0);
	game = (t_game *)malloc(sizeof(t_game));
	init_struct(game);
	read_map(game, argv);
	check_errors(game);
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, (game->map_width * 60),
			(game->map_height * 60), "solong");
	put_images(game);
	add_graphics(game);
	mlx_key_hook(game->window, controls, game);
	mlx_hook(game->window, 17, 0, (void *)exit, 0);
	mlx_loop(game->mlx);
}
