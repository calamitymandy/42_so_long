/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdemuyn <amdemuyn@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:48:42 by amdemuyn          #+#    #+#             */
/*   Updated: 2023/04/27 13:06:04 by amdemuyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_items(t_game *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx, game->window, game->item, width * 60,
	height * 60);
	game->items++;
}

void	put_perso(t_game *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx, game->window, game->perso, width * 60,
	height * 60);
	game->x_axis = height;
	game->y_axis = width;
}

void	put_images(t_game *game)
{
	int	width;
	int	height;

	game->floor = mlx_xpm_file_to_image(game->mlx, "sand.xpm", &width,
			&height);
	game->wall = mlx_xpm_file_to_image(game->mlx, "stone.xpm", &width,
			&height);
	game->perso = mlx_xpm_file_to_image(game->mlx, "ostrichXbackground.xpm",
		&width, &height);
	game->item = mlx_xpm_file_to_image(game->mlx, "tumb.xpm", &width,
			&height);
	game->exit = mlx_xpm_file_to_image(game->mlx, "holeXbackground.xpm",
		&width, &height);
}

void	add_graphics(t_game *game)
{
	int	height;
	int	width;

	game->items = 0;
	height = 0;
	while (height < game->map_height)
	{
		width = 0;
		while (game->map[height][width])
		{
			if (game->map[height][width] == '0')
				mlx_put_image_to_window(game->mlx, game->window,
					game->floor, width * 60, height * 60);
			if (game->map[height][width] == '1')
				mlx_put_image_to_window(game->mlx, game->window,
					game->wall, width * 60, height * 60);
			if (game->map[height][width] == 'P')
				put_perso(game, height, width);
			if (game->map[height][width] == 'C')
				put_items(game, height, width);
			if (game->map[height][width] == 'E')
				mlx_put_image_to_window(game->mlx, game->window,
					game->exit, width * 60, height * 60);
			width++;
		}
		height++;
	}
}
