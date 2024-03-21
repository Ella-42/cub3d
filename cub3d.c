/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:24:34 by lpeeters          #+#    #+#             */
/*   Updated: 2024/03/21 21:50:25 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//parse map, handle errors, convert into interactive 2d video game
int	main(void)
{
	t_mlx	mlx;

	int test = ft_strlen("test");
	printf("test: %i\n", test);
	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.ptr, 1920, 1080, "Cub3D");
	mlx_loop(mlx.ptr);
}
