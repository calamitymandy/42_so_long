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

typedef struct s_game
{
	int		fd;
	int		map_height;
	int		map_width;
	int		perso_count;
	int		column_count;
	int		exit_count;
	int		x_axis;
	int		y_axis;
	int		counter;
	int		items;

	char	**map;

	void	*floor;
	void	*barrier;
	void	*perso;
	void	*exit;
	void	*item;
	void	*mlx;
	void	*window;

}	t_game;

int		exit_point(t_game *game);
int		read_map(t_game *game, char **argv);
void	check_errors(t_game *game);
//int		controls_working(int command, t_game *game);
//void	adding_in_graphics(t_game *game);
//void	place_images_in_game(t_game *game);

#endif
