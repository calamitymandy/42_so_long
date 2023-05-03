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

void	put_perso(t_game *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx, game->window, game->perso, width * 40,
	height * 40);
	game->x_axis = height;
	game->y_axis = width;

}

void	put_images(t_game *game)
{
	int	width;
	int	height;

	game->floor = mlx_xpm_file_to_image(game->mlx, "floor_1.xpm", &width,
			&height);
	game->wall = mlx_xpm_file_to_image(game->mlx, "stone.xpm", &width,
			&height);
	game->perso = mlx_xpm_file_to_image(game->mlx, "ostrich.xpm", &width,
		&height);
}

void	add_graphics(t_game *game)
{
	int	height;
	int	width;

	height = 0;
	while (height < game->map_height)
	{
		width = 0;
		while (game->map[height][width])
		{
			if (game->map[height][width] == '0')
				mlx_put_image_to_window(game->mlx, game->window,
					game->floor, width * 40, height * 40);
			if (game->map[height][width] == '1')
				mlx_put_image_to_window(game->mlx, game->window,
					game->wall, width * 40, height * 40);
			if (game->map[height][width] == 'P')
				put_perso(game, height, width);
			width++;
		}
		height++;
	}
}
