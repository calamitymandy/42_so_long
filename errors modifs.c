/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdemuyn <amdemuyn@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:20:42 by amdemuyn          #+#    #+#             */
/*   Updated: 2023/04/19 18:23:20 by amdemuyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	walls_in_place(t_game *game)
{
	int	has_vertical_wall;
	int	has_horizontal_wall;
	int height;
	int width;

	has_vertical_wall = 1;
	has_horizontal_wall = 1;
	height = 0;
	while (height < game->map_height && has_vertical_wall)
	{
		if (!(game->map[height][0] == '1' && game->map[height][game->map_height -1] == '1'))
			has_vertical_wall = 0;
		height++;
	}

	width = 0;
	while (width < game->map_width && has_horizontal_wall)
	{
		if(!(game->map[0][width] == '1' && game->map[game->map_width -1][width] == '1'))
			has_horizontal_wall = 0;
		width++;
	}
	return (has_vertical_wall && has_horizontal_wall);
}

static void	check_count(t_game *game, int height, int width)
{
	if (game->map[width][height] != '1' &&
		game->map[width][height] != '0' &&
		game->map[width][height] != 'P' &&
		game->map[width][height] != 'C' &&
		game->map[width][height] != 'E' &&
		game->map[width][height] != '\n')
	{
		printf("\nNot allowed: %c\n", game->map[width][height]);
		exit_window(game);
	}
	if (game->map[width][height] == 'P')
		game->perso_count++;
	if (game->map[width][height] == 'C')
		game->column_count++;
	if (game->map[width][height] == 'E')
		game->exit_count++;
}

void	valid_perso(t_game *game)
{
	int	height;
	int	width;

	height = 0;
	while (height < game->map_height -1)
	{
		width = 0;
		while (width < game->map_width -1)
		{
			check_count(game, height, width);
			width++;
		}
		height++;
	}
	if (!(game->perso_count == 1 && game->column_count > 1
			&& game->exit_count == 1))
	{
		printf("\nERROR: perso, item or exit is wrong\n");
		exit_window(game);
	}
}

void	check_errors(t_game *game)
{
	if (!walls_in_place(game))
	{
		printf("/nERROR: No walls in this map\n");
		exit_window(game);
	}
	valid_perso(game);
	// TODO!!!!! Check if all rows have the same length
	// for (int i = 1; i < game->map_height; i++) {
	// 	if (strlen(game->map[i]) != strlen(game->map[i - 1])) {
	// 		printf("\nERROR: Map is not a rectangle\n");
	// 		exit_window(game);
	// 	}
	// }
}
