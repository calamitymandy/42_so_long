/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdemuyn <amdemuyn@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:25:27 by amdemuyn          #+#    #+#             */
/*   Updated: 2023/05/26 15:17:45 by amdemuyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_width(char *str)
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
 * The function adds a new line to a game map by copying the existing map to
 * a temporary array and appending the new line to the end.
 * @param line A pointer to a string representing a new line to be added to 
 * the game map.
 * The while block is copying the existing map stored in `game->map` to a new 
 * temporary array `temp`, while also adding a new line to the end of the 
 * `temp` array. It starts by initializing `i` to 0 and then copies all the 
 * elements of `game->map` to `temp` until the second-to-last line. 
 * Finally, it adds the new line to the end of `temp`. 
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
	if (!temp)
		return (0);
	temp[game->map_height] = NULL;
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

/* 
 * `while (1)` is an infinite loop that continues to execute until it is 
 * explicitly broken out of using a `break` statement. In this case, it 
 * is being used to read the contents of a file line by line using the 
 * `get_next_line` function and adding each line to the game map using the 
 * `add_line` function. It continues to read and add lines until there are 
 * no more lines to read, at which point it breaks out of the loop. 
 * If there is an error adding a line to the map, the loop also breaks.
 */
int	read_map(t_game *game, char **argv)
{
	char	*reading;

	game->fd = open(argv[1], O_RDONLY);
	if (game->fd < 0)
	{
		ft_printf("ERROR: can't open map\n");
		exit_window(game);
	}
	while (1)
	{
		reading = get_next_line(game->fd);
		if (!add_line(game, reading))
			break ;
	}
	if (game->map_height == 0 && game->map_width == 0)
	{
		ft_printf("ERROR: empty map\n");
		exit_window(game);
	}
	close (game->fd);
	return (1);
}

void	valid_ber(char *map_name, char *ext)
{
	int	i;
	int	j;

	i = ft_strlen(map_name) - ft_strlen(ext);
	j = 0;
	while (map_name[i + j] && ext[j])
	{
		if (map_name[i + j] == ext[j])
			j++;
		else
		{
			ft_printf("ERROR: file extension must be: .ber\n");
			exit(1);
		}
	}
}

/**
 * The function `map_copy` copies the contents of a 2D character array 
 * `game->map` to another 2D character array `map` of the same dimensions.
 */
void	map_copy(t_game *game, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_height)
	{
		map[i] = (char *)malloc(sizeof(char) * game->map_width);
		i++;
	}
	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			map[i][j] = game->map[i][j];
			j++;
		}
		i++;
	}
}
