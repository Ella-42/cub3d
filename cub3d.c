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
#include "mlx_macos/mlx.h"

// Parse map, handle errors, convert into an interactive 3D video game
int	main(int ac, char **av)
{
	t_mlx			mlx;
	t_minimap		minimap;
	t_player_data	player;

	if (ac != 2)
		return (prnt_err(strerror(EINVAL)));
	if (!map_handler(av[1]))
		return (FAILURE);
	player.posX = 5;
	player.posY = 5;
	player.moveSpeed = 10;
	player.oldX = player.posX;
	player.oldY = player.posY;
	minimap.player = &player;
	mlx.map = &minimap;
	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.ptr, 1920, 1080, "Cub3D");
	minimap.img = mlx_new_image(mlx.ptr, 710, 400);
	minimap.addr = mlx_get_data_addr(minimap.img, &minimap.bits_per_pixel,
			&minimap.line_length, &minimap.endian);
	player_drawer(&minimap, &player, 0x00FF0000);
	mlx_put_image_to_window(mlx.ptr, mlx.win, minimap.img, 0, 0);
	mlx_key_hook(mlx.win, key_event, &mlx);
	mlx_hook(mlx.win, 17, 0L, close_window, &mlx);
	mlx_loop(mlx.ptr);
}
