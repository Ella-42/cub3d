/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <lpeeters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:24:59 by lpeeters          #+#    #+#             */
/*   Updated: 2024/03/27 16:38:00 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* LIBRARIES */

# include "libft/libft.h" //Custom library functions
# include "mlx_linux/mlx.h" //Minilibx library functions
# include "stdio.h" //printf, perror
# include "string.h" //strerror
# include "errno.h" //errno

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

/* FUNCTIONS */

/**************************/
/*      exit/error.c      */
/**************************/

// Print error messages
int	prnt_err(char *str);

/*************************/
/*   exit/mlx_events.c   */
/*************************/

// Exit in a clean way
int	close_window(t_mlx *mlx, int status);

// Defines what happens when certain keys are pressed
int	key_event(int keycode, t_mlx *mlx);

/**************************/
/*  parser/map_checker.c  */
/**************************/

// Map file name validation
int	map_checker(char *file_name);

// Master map handler
int	map_handler(char *file_name);

#endif
