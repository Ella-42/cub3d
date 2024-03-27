/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <lpeeters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:24:34 by lpeeters          #+#    #+#             */
/*   Updated: 2024/03/27 14:52:51 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Parse map, handle errors, convert into an interactive 3D video game
int	main(int ac, char **av)
{
	t_mlx	mlx;

	if (ac != 2)
		return (prnt_err(strerror(EINVAL)));
	if (!map_handler(av[1]))
		return (FAILURE);
	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.ptr, 1920, 1080, "Cub3D");
	mlx_key_hook(mlx.win, key_event, &mlx);
	mlx_hook(mlx.win, 17, 0L, close_window, &mlx);
	mlx_loop(mlx.ptr);
}
