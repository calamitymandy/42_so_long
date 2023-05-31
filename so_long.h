/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdemuyn <amdemuyn@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:55:39 by amdemuyn          #+#    #+#             */
/*   Updated: 2023/05/18 17:29:47 by amdemuyn         ###   ########.fr       */
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
# include "ft_printf.h"

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

/*map*/
int		find_width(char *str);
int		read_map(t_game *game, char **argv);
void	valid_ber(char *map, char *ext);
void	check_errors(t_game *game);
void	map_is_rectangle(t_game *game);
void	map_copy(t_game *game, char **map);
void	check_itinerary(t_game *game, char **map);

/*game*/
int		exit_window(t_game *game);
int		controls(int command, t_game *game);

/*graphics*/
void	put_images(t_game *game);
void	add_graphics(t_game *game);

#endif
