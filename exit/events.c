/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <lpeeters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:40:33 by lpeeters          #+#    #+#             */
/*   Updated: 2024/03/27 12:40:54 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// Exit in a clean way
int	close_window(t_mlx *mlx, int status)
{
	mlx_destroy_window(mlx->ptr, mlx->win);
	mlx_destroy_display(mlx->ptr);
	free(mlx->ptr);
	if (status == FAILURE)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
	return (FAILURE);
}

/*
	else if (keycode == UP || keycode == W)
		move(mlx, mlx->map, UP);
	else if (keycode == DOWN || keycode == S)
		move(mlx, mlx->map, DOWN);
	else if (keycode == LEFT || keycode == A)
		move(mlx, mlx->map, LEFT);
	else if (keycode == RIGHT || keycode == D)
		move(mlx, mlx->map, RIGHT);
	else if (keycode == M)
		print_map(mlx->map);
*/

// Handles Movement
int move(t_minimap *map, int direction)
{
    if (direction == UP)
        map->player->posY += 0.5;
    return (SUCCESS);
}

// Defines what happens when certain keys are pressed
int	key_event(int keycode, t_mlx *mlx)
{
    if (keycode == ESCAPE)
        close_window(mlx, SUCCESS);
    else if (keycode == UP || keycode == W)
        move(mlx->map, UP);
    else
		printf("Info: key not bound...\n");
	return (0);
}
