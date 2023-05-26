/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itinerary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdemuyn <amdemuyn@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:12:21 by amdemuyn          #+#    #+#             */
/*   Updated: 2023/05/26 15:14:33 by amdemuyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * The function finds the position of the character 'P' in a given map.
 * @param map The map is a 2D array of characters. It contains information 
 * about the location of different objects and obstacles in the game, 
 * including the player character ('P').
 */
static void	perso_position(t_game *game, char **map)
{
	while (game->itinerary_perso_y < game->map_height
		&& map[game->itinerary_perso_y][game->itinerary_perso_x] != 'P')
	{
		game->itinerary_perso_x = 1;
		while (game->itinerary_perso_x < game->map_width
			&& map[game->itinerary_perso_y][game->itinerary_perso_x] != 'P')
		{
			if (map[game->itinerary_perso_y][game->itinerary_perso_x] == 'P')
				break ;
			game->itinerary_perso_x++;
		}
		if (map[game->itinerary_perso_y][game->itinerary_perso_x] == 'P')
			break ;
		game->itinerary_perso_y++;
	}
}

/**
 * The function recursively searches a map for 'C' items and updates the 
 * game's itinerary count while replacing visited locations with '.'
 * @param game A pointer to a struct representing the current game state.
 * @param map A 2D array representing the game map.
 * @param x The x-coordinate of the current position on the map.
 * @param y The variable "y" represents the vertical coordinate of the 
 * current position on the map being traversed in the itinerary_c function.
 * It is used to check the values of the cells above and below the current 
 * position, and to recursively call the itinerary_c function for those 
 * cells if they are valid.
 */
static void	itinerary_c(t_game *game, char **map, int x, int y)
{
	if (map[y][x] == 'C')
		game->itinerary_items++;
	if (map[y - 1][x] == '0' || map[y + 1][x] == '0' || map[y][x - 1] == '0'
			|| map[y][x + 1] == '0' || map[y - 1][x] == 'C'
			|| map[y + 1][x] == 'C' || map[y][x - 1] == 'C'
			|| map[y][x + 1] == 'C')
		map[y][x] = '.';
	if (map[y - 1][x] == '0' || map[y - 1][x] == 'C')
		itinerary_c(game, map, x, y - 1);
	if (map[y + 1][x] == '0' || map[y + 1][x] == 'C')
		itinerary_c(game, map, x, y + 1);
	if (map[y][x - 1] == '0' || map[y][x - 1] == 'C')
		itinerary_c(game, map, x - 1, y);
	if (map[y][x + 1] == '0' || map[y][x + 1] == 'C')
		itinerary_c(game, map, x + 1, y);
	map[y][x] = '.';
}

static void	itinerary_e(t_game *game, char **map, int x, int y)
{
	if (map[y][x] == 'E')
		game->itinerary_exit++;
	if (map[y - 1][x] == '0' || map[y + 1][x] == '0' || map[y][x - 1] == '0'
			|| map[y][x + 1] == '0' || map[y - 1][x] == 'C'
			|| map[y + 1][x] == 'C' || map[y][x - 1] == 'C'
			|| map[y][x + 1] == 'C')
		map[y][x] = '.';
	if (map[y - 1][x] == '0' || map[y - 1][x] == 'C' || map[y - 1][x] == 'E')
		itinerary_e(game, map, x, y - 1);
	if (map[y + 1][x] == '0' || map[y + 1][x] == 'C' || map[y + 1][x] == 'E')
		itinerary_e(game, map, x, y + 1);
	if (map[y][x - 1] == '0' || map[y][x - 1] == 'C' || map[y][x - 1] == 'E')
		itinerary_e(game, map, x - 1, y);
	if (map[y][x + 1] == '0' || map[y][x + 1] == 'C' || map[y][x + 1] == 'E')
		itinerary_e(game, map, x + 1, y);
	map[y][x] = '.';
}

/**
 * The function checks if there is a valid itinerary for the player to pick up 
 * all items and exit the map.
 * @param map The "map" parameter is a pointer to a two-dimensional array of 
 * characters, representing the game map.
 */
void	check_itinerary(t_game *game, char **map)
{
	int	line;

	line = 0;
	perso_position(game, map);
	itinerary_c(game, map, game->itinerary_perso_x, game->itinerary_perso_y);
	if (game->itinerary_items != game->item_count)
	{
		printf("ERROR: No valid itinerary to pick items");
		exit_window(game);
	}
	while (line < game->map_height)
		free(map[line++]);
	map_copy(game, map);
	itinerary_e(game, map, game->itinerary_perso_x, game->itinerary_perso_y);
	line = 0;
	while (line < game->map_height)
		free(map[line++]);
	free(map);
	if (game->itinerary_exit != 1)
	{
		printf("ERROR: No valid itinerary to exit");
		exit_window(game);
	}
}
