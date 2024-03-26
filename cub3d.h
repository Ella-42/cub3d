/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:24:59 by lpeeters          #+#    #+#             */
/*   Updated: 2024/03/26 19:13:29 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* LIBRARIES */

# include "libft/libft.h" //Custom library functions
# include "mlx/mlx.h" //Minilibx library functions
# include "stdio.h" //printf

/* MACROS */

# define SUCCESS 0
# define FAILURE 1

/* KEY CODES */

# define ESCAPE 65307
# define M 109
# define UP 65362
# define W 119
# define LEFT 65361
# define A 97
# define DOWN 65364
# define S 115
# define RIGHT 65363
# define D 100

// MLX data structure
typedef struct s_mlx
{
	void	*ptr;
	void	*win;
}			t_mlx;

#endif
