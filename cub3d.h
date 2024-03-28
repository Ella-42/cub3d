/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:24:59 by lpeeters          #+#    #+#             */
/*   Updated: 2024/03/27 20:12:14 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* LIBRARIES */

# include "libft/libft.h" //Custom library functions
# include "mlx_macos/mlx.h" //Minilibx library functions
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

# define MINIMAP_WIDTH 710
# define MINIMAP_HEIGHT 400

// Raycast data structure
typedef struct s_ray_data
{
}	t_ray_data;

// Player Data Structure
typedef struct s_player_data
{
    float   posX;
    float   posY;
    float   playerAngle;
    float   moveSpeed;

}   t_player_data;

// MiniMap Data Structure
typedef struct s_minimap
{
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
    t_player_data   *player;
}   t_minimap;

// MLX data structure
typedef struct s_mlx
{
	void	*ptr;
	void	*win;
    t_minimap *map;
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

/**************************/
/*  minimap/drawer.c  */
/**************************/

// Pixel Put MLX Images
void    my_mlx_pixel_put(t_minimap *data, int x, int y, int color);

// Draw Player Minimap
void    player_drawer(t_minimap *map, t_player_data *player, int color);

#endif
