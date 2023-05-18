/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdemuyn <amdemuyn@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:55:39 by amdemuyn          #+#    #+#             */
/*   Updated: 2023/04/11 14:32:05 by amdemuyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <stdlib.h>
# include <mlx.h>
# include "get_next_line.h"

typedef struct s_game
{
	int		fd;
	int		map_height;
	int		map_width;
	int		perso_count;
	int		item_count;
	int		exit_count;
	int		x_axis;
	int		y_axis;
	int		counter;
	int		items;
// added 4 counters for itinerary
	int		itinerary_exit;
	int		itinerary_items;
	int		itinerary_perso_x;
	int		itinerary_perso_y;

	char	**map;

	void	*floor;
	void	*wall;
	void	*perso;
	void	*exit;
	void	*item;
	void	*mlx;
	void	*window;

}	t_game;

int		exit_window(t_game *game);
int		read_map(t_game *game, char **argv);
void	check_errors(t_game *game);
void	valid_map(char *map, char *ext);
void	map_copy(t_game *game, char **map);
void	map_is_rectangle(t_game *game);
int		find_width(char *str);
void	put_images(t_game *game);
void	add_graphics(t_game *game);
int		controls(int command, t_game *game);

#endif