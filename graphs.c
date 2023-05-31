/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdemuyn <amdemuyn@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:48:42 by amdemuyn          #+#    #+#             */
/*   Updated: 2023/05/17 18:19:45 by amdemuyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * The function puts an image of an item on the game window at a specific 
 * position and increments the number of items in the game.
 * @param height The height parameter is an integer value representing the 
 * vertical position of the item to be placed on the game screen.
 * @param width The width parameter is an integer value representing the
 * horizontal position of the item to be placed on the game window. It is 
 * multiplied by 60 to convert it to pixel coordinates.
 */
void	put_items(t_game *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx, game->window, game->item, width * 60,
		height * 60);
	game->items++;
}

/**
 * The function puts an image of a character in a specific position on the 
 * game window.
 * @param height vertical position of the character. It is used to calculate
 * the y-axis position of the character on the screen.
 * @param width horizontal position of the character. It is used to calculate
 * the x-coordinate of the character's position on the game window.
 */
void	put_perso(t_game *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx, game->window, game->perso, width * 60,
		height * 60);
	game->y_axis = height;
	game->x_axis = width;
}

/**
 * The function loads and validates XPM images for the game 
 * and assigns them to specific variables.
 */
void	*valid_xpm_img(t_game *game, char *xpm_name)
{
	void	*img;
	int		pixels;

	pixels = 60;
	img = mlx_xpm_file_to_image(game->mlx, xpm_name, &pixels, &pixels);
	if (!img)
	{
		ft_printf("ERROR: something is wrong with xpm\n");
		exit_window(game);
	}
	return (img);
}

void	put_images(t_game *game)
{
	game->floor = valid_xpm_img(game, "sand.xpm");
	game->wall = valid_xpm_img(game, "stoneXbackground.xpm");
	game->perso = valid_xpm_img(game, "ostrichXbackground.xpm");
	game->item = valid_xpm_img(game, "smallworm.xpm");
	game->exit = valid_xpm_img(game, "holeXbackground.xpm");
}

/**
 * The function adds graphics to the game window based on the contents of 
 * the game map.
 */
void	add_graphics(t_game *game)
{
	int	height;
	int	width;

	height = -1;
	game->items = 0;
	while (++height < game->map_height)
	{
		width = -1;
		while (game->map[height][++width])
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
					game->exit, (width) * 60, (height) * 60);
		}
	}
}
