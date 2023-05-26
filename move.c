/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdemuyn <amdemuyn@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:51:46 by amdemuyn          #+#    #+#             */
/*   Updated: 2023/05/04 12:52:59 by amdemuyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * The function performs a move in a game and updates the game state.
 * @param x The x-coordinate of the player's move on the game map.
 * @param y The variable `y` represents the y-coordinate of the player's 
 * current position on the game map. It is used in the `do_the_move` function
 * to check the type of tile the player is moving onto and update the game 
 * state accordingly.
 * 
 * @return an integer value of 1 if the move is valid and has been executed 
 * successfully. If the move results in the player collecting all the items 
 * and reaching the exit, the function prints a message and exits the game.
 * If the move is invalid, the function does not return anything and the game
 * continues.
 */
static int	do_the_move(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'E')
	{
		if (game->items != 0)
			return (0);
		printf("YAY! You've got all the items\n");
		exit_window(game);
	}
	if (game->map[y][x] == '0')
	{
		game->map[y][x] = 'P';
		game->x_axis = x;
		game->y_axis = y;
		game->counter++;
	}
	if (game->map[y][x] == 'C')
	{
		game->map[y][x] = 'P';
		game->x_axis = x;
		game->y_axis = y;
		game->items--;
		game->counter++;
	}
	return (1);
}

/**
 * The function moves the player up or down on the game map and updates the 
 * game state accordingly.
 * @param key The key pressed by the user to move the player character up or 
 * down. The value of the key is compared to specific key codes 
 * (13, 126, 1, 125) to determine the direction of movement.
 * @param x The x-coordinate of the player's current position on the game map.
 * @param y The current y-coordinate of the player's position on the game map.
 * @return an integer value of 1 if the move was successful, and 0 if the move 
 * was not possible due to a wall ('1') being in the way.
 */
static int	move_up_down(t_game *game, int key, int x, int y)
{
	int	which_move;

	if (key == 13 || key == 126)
	{
		y--;
		if (game->map[y][x] == '1')
			return (0);
		which_move = do_the_move(game, x, y);
		if (!which_move)
			return (0);
		game->map[y + 1][x] = '0';
	}
	else if (key == 1 || key == 125)
	{
		y++;
		if (game->map[y][x] == '1')
			return (0);
		which_move = do_the_move(game, x, y);
		if (!which_move)
			return (0);
		game->map[y - 1][x] = '0';
	}
	printf("How many steps: %i\n", game->counter);
	printf("Items left: %i\n", game->items);
	return (1);
}

static int	move_right_left(t_game *game, int key, int x, int y)
{
	int	which_move;

	if (key == 2 || key == 124)
	{
		x++;
		if (game->map[y][x] == '1')
			return (0);
		which_move = do_the_move(game, x, y);
		if (!which_move)
			return (0);
		game->map[y][x - 1] = '0';
	}
	if (key == 0 || key == 123)
	{
		x--;
		if (game->map[y][x] == '1')
			return (0);
		which_move = do_the_move(game, x, y);
		if (!which_move)
			return (0);
		game->map[y][x + 1] = '0';
	}
	printf("How many steps: %i\n", game->counter);
	printf("Items left: %i\n", game->items);
	return (1);
}

/**
 * The function controls keyboard inputs and moves the player accordingly
 * in a game.
 * @param key The key code of the keyboard input that triggered the controls 
 * function.
 */
int	controls(int key, t_game *game)
{
	int	is_ok;
	int	x;
	int	y;

	x = game->x_axis;
	y = game->y_axis;
	if (key == 53)
		exit_window(game);
	if (key == 13 || key == 126)
		is_ok = move_up_down(game, key, x, y);
	if (key == 1 || key == 125)
		is_ok = move_up_down(game, key, x, y);
	if (key == 0 || key == 123)
		is_ok = move_right_left(game, key, x, y);
	if (key == 2 || key == 124)
		is_ok = move_right_left(game, key, x, y);
	if (is_ok)
		add_graphics(game);
	return (1);
}
