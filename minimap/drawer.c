#include "../cub3d.h"

/*
 * The minimap can be both used for the bonus or a debug for raycasts
 * We make a 2D array of the map and we make our player visible in here
 * We also have a little line that shows you which direction we are looking at
*/

void	my_mlx_pixel_put(t_minimap *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void    player_drawer(t_minimap *map, t_player_data *player, int color)
{
    int posX;
    int posY;
    char    *dst;

    posX = player->posX - 2;
    posY = player->posY - 2;
    while (posX <= player->posX + 2)
    {
        posY = player->posY - 2;
        while (posY <= player->posY + 2)
        {
            dst = map->addr + (posY * map->line_length + posX * (map->bits_per_pixel / 8));
            *(unsigned int*)dst = color;
            posY++;
        }
        posX++;
    }
}
