/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdemuyn <amdemuyn@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:20:42 by amdemuyn          #+#    #+#             */
/*   Updated: 2023/05/26 15:16:30 by amdemuyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * The function checks if the game map is a rectangle, meaning that all rows 
 * have the same length. It does this by iterating through each row of the map
 * and comparing the length of each row to the length of the first row. If any
 * row has a different length than the first row, it prints an error message 
 * and exits the game. 
 */
void	map_is_rectangle(t_game *game)
{
	int	i;
	int	width_of_line;

	i = 1;
	game->map_width = find_width(game->map[0]);
	while (game->map[i])
	{
		width_of_line = find_width(game->map[i]);
		if (width_of_line != game->map_width)
		{
			printf("ERROR: map is not a rectangle\n");
			exit_window(game);
		}
		i++;
	}
}

/**
 * The function checks if the outer walls of a game map are made up entirely
 * of '1' characters.
 * @param height The current row index being checked in the map.
 * @param width The starting index of the column to check for walls in the 
 * game map.
 * @return an integer value of either 0 or 1.
 */
static int	check_walls(t_game *game, int height, int width)
{
	while (width < game->map_width)
	{
		if (!(game->map[0][width] == '1'
			&& game->map[game->map_height - 1][width] == '1'))
			return (0);
		width++;
	}
	while (height < game->map_height)
	{
		if (!(game->map[height][0] == '1'
			&& game->map[height][game->map_width - 1] == '1'))
			return (0);
		height++;
	}
	return (1);
}

/**
 * The function checks the validity of characters in a game map and counts 
 * the number of 'P', 'C', and 'E' characters.
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
		exit_window(game);
	}
	if (game->map[height][width] == 'P')
		game->perso_count++;
	if (game->map[height][width] == 'C')
		game->item_count++;
	if (game->map[height][width] == 'E')
		game->exit_count++;
}

/**
 * The function checks if the number of characters representing the player, 
 * items, and exit in the game map is correct. It counts the number of 
 * 'P', 'C', and 'E' characters and compares them to the expected number of 
 * each character. If the counts are not correct, it prints an error message 
 * and exits the game.
 */
void	valid_pce(t_game *game)
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
		exit_window(game);
	}
}

/**
 * The function checks for errors in the game map and exits the game if any 
 * errors are found.
 */
void	check_errors(t_game *game)
{
	char	**map;
	int		height;
	int		width;
	int		walls;

	height = 0;
	width = 0;
	map_is_rectangle(game);
	walls = check_walls(game, height, width);
	if (!walls)
	{
		printf("ERROR: No correct walls in this map\n");
		exit_window(game);
	}
	valid_pce(game);
	map = (char **)malloc(sizeof(char *) * game->map_height);
	map_copy(game, map);
	check_itinerary(game, map);
}
