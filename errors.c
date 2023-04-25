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

static int	vertical_wall(t_game *game)
{
	int	height;
	int	width;

	height = 0;
	width = game->map_width;
	while (height < game->map_height)
	{
		if (!(game->map[height][0] == '1'
			&& game->map[height][width -1] == '1'))
			return (0);
		height++;
	}
	return (1);
}

static int	horizontal_wall(t_game *game)
{
	int	width;
	int	height;

	width = 0;
	height = game->map_height;
	while (width < game->map_width)
	{
		if (!(game->map[0][width] == '1'
			&& game->map[height -1][width] == '1'))
			return (0);
		width++;
	}
	return (1);
}

/**
 * The function checks the validity of characters in a game map and counts the number of 'P', 'C', and
 * 'E' characters.
 */
static void	check_count(t_game *game, int height, int width)
{
	if (game->map[height][width] != '1' &&
		game->map[height][width] != '0' &&
		game->map[height][width] != 'P' &&
		game->map[height][width] != 'C' &&
		game->map[height][width] != 'E' &&
		game->map[height][width] != '\n')
	{
		printf("Not allowed: %c\n", game->map[height][width]);
		exit_point(game);
	}
	if (game->map[height][width] == 'P')
		game->perso_count++;
	if (game->map[height][width] == 'C')
		game->item_count++;
	if (game->map[height][width] == 'E')
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
		while (width <= game->map_width)
		{
			check_count(game, height, width);
			width++;
		}
		height++;
	}
	if (!(game->perso_count == 1 && game->item_count >= 1
			&& game->exit_count == 1))
	{
		printf("ERROR: perso, item or exit is wrong\n");
		exit_point(game);
	}
}

void	check_errors(t_game *game)
{
	int	horizontal_walls;
	int	vertical_walls;

	horizontal_walls = horizontal_wall(game);
	vertical_walls = vertical_wall(game);
	if (!horizontal_walls || !vertical_walls)
	{
		printf("ERROR: No walls in this map\n");
		exit_point(game);
	}
	valid_perso(game);
}
