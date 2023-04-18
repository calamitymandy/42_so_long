/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdemuyn <amdemuyn@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:25:27 by amdemuyn          #+#    #+#             */
/*   Updated: 2023/04/18 16:25:56 by amdemuyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	find_width(char *str)
{
	int	width;

	width = 0;
	while (str[width] != '\0')
		width++;
	if (str[width -1] == '\n')
		width--;
	return (width);
}

/**
 * The function adds a new line to a game map by copying the existing map to a temporary array and
 * appending the new line to the end.
 * @param game a pointer to a struct of type `t_game`, which contains information about the game being
 * played, including the map.
 * @param line A pointer to a string representing a new line to be added to the game map.
 */
static int	add_line(t_game *game, char *line)
{
	int		i;
	char	**temp;

	if (!line)
		return (0);
	i = 0;
	game->map_height++;
	temp = (char **)malloc(sizeof(char *) * (game->map_height +1));
	temp[game->map_height] = NULL;
/* This code block is copying the existing map stored in `game->map` to a new temporary array `temp`,
while also adding a new line to the end of the `temp` array. It starts by initializing `i` to 0 and
then copies all the elements of `game->map` to `temp` until the second-to-last line. Finally, it
adds the new line to the end of `temp`. */
	while (i < game->map_height -1)
	{
		temp[i] = game->map[i];
		i++;
	}
	temp[i] = line;
	if (game->map)
		free(game->map);
	game->map = temp;
	return (1);
}

int	read_map(t_game *game, char **argv)
{
	char	*reading;

	game->fd = open(argv[1], O_RDONLY);
	if (game->fd < 0)
		return (0);
	while (1)
	{
		reading = get_next_line(game->fd);
		if (!add_line(game, reading))
			break ;
	}
	close (game->fd);
	game->map_width = find_width(game->map[0]);
	return (1);
}
