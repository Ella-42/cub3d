/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:05:32 by qraymaek          #+#    #+#             */
/*   Updated: 2024/03/28 17:05:35 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
 * The minimap can be both used for the bonus or a debug for raycasts
 * We make a 2D array of the map and we make our player visible in here
 * We also have a little line that shows you which direction we are looking at
 */

void	my_mlx_pixel_put(t_minimap *data, int x, int y, int color)
{
	char	*pos;

	pos = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)pos = color;
}

int	clear_image(t_minimap *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j <= 400)
	{
		i = 0;
		while (i <= 710)
		{
			my_mlx_pixel_put(map, i, j, 0x00000000);
			i++;
		}
		j++;
	}
	return (SUCCESS);
}

int	player_drawer(t_minimap *map, t_player_data *player, int color)
{
	int		pos_x;
	int		pos_y;
	char	*pos;

	if (!map || !player || !map->addr)
		return (printf("Invalid map or player data\n"), FAILURE);
	pos_x = player->posX - 2;
	while (pos_x <= player->posX + 2)
	{
		pos_y = player->posY - 2;
		while (pos_y <= player->posY + 2)
		{
			if (player->posX < 0 || player->posY < 0)
				return (printf("Invalid Position\n"), FAILURE);
			pos = map->addr + (pos_y * map->line_length + pos_x
					* (map->bits_per_pixel / 8));
			*(unsigned int *)pos = color;
			pos_y++;
		}
		pos_x++;
	}
	printf("Player Positions: x=[%f] y=[%f]\n", player->posX, player->posY);
	return (SUCCESS);
}
