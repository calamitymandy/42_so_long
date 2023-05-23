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
	// added 4 counters for itinerary
	game->itinerary_exit = 0;
	game->itinerary_items = 0;
	game->itinerary_perso_x = 1;
	game->itinerary_perso_y = 1;
	//
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
	while (line < game->map_height)
		free(game->map[line++]);
	free(game->map);
	exit(0);
}

void	leaks(void)
{
	system("leaks so_long");
}

/**
 * Initializes and runs a game using the mlx library based on a valid map file
 * provided as a command line argument.
 * argv[1] is expected to contain the name of a file with a ".ber" extension, 
 * which will be used as the map for the game.
 * 
 * If the number of arguments passed to the program is not 2, then 0 is returned.
 * If the allocation of memory for the game struct fails, then 0 is returned.
 */
int	main(int argc, char **argv)
{
	t_game	*game;

	atexit(leaks);
	if (argc != 2)
	{
		printf("ERROR: number of arguments is not valid\n");
		return (0);
	}
	valid_map(argv[1], ".ber");
	game = (t_game *)malloc(sizeof(t_game));
	if (game == NULL)
		return (0);
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
