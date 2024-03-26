/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:24:34 by lpeeters          #+#    #+#             */
/*   Updated: 2024/03/26 19:07:40 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// Print error messages
int	prnt_err(char *str)
{
	return (ft_putendl_fd(str, 2), 1);
}

//exit in a clean way
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

//defines what happens when certain keys are pressed
int	key_event(int keycode, t_mlx *mlx)
{
	if (keycode == ESCAPE)
		close_window(mlx, SUCCESS);
	else
		printf("Info: key not bound...\n");
	return (0);
}

// Parse map, handle errors, convert into an interactive 3D video game
int	main(int ac, char **av)
{
	t_mlx	mlx;

	(void)av;
	if (ac != 2)
		return (prnt_err("Error: invalid argument count"));
	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.ptr, 1920, 1080, "Cub3D");
	mlx_key_hook(mlx.win, key_event, &mlx);
	mlx_hook(mlx.win, 17, 0L, close_window, &mlx);
	mlx_loop(mlx.ptr);
}
