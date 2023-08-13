/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradal <nradal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:25:19 by nradal            #+#    #+#             */
/*   Updated: 2023/08/01 14:46:41 by nradal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	mlx_draw_pixels_cubes(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	x += data->window.width / 2
		- (data->parsing.width * data->minimap.cube_size) / 2;
	y += data->window.height / 2
		- (data->parsing.height * data->minimap.cube_size) / 2;
	while (i < data->minimap.cube_size - 1)
	{
		my_mlx_pixel_put(data->image, x + i, y, color);
		while (j < data->minimap.cube_size - 1)
		{
			my_mlx_pixel_put(data->image, x + i, y + j, color);
			j++;
		}
		j = 0;
		i++;
	}
}

void	draw_map(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->parsing.c_map[y] != NULL)
	{
		while (data->parsing.c_map[y][x] != '\0')
		{
			if (data->parsing.c_map[y][x] == '1')
				mlx_draw_pixels_cubes(data, x * data->minimap.cube_size,
					y * data->minimap.cube_size, 0x333333);
			else if (data->parsing.c_map[y][x] == 'v')
				mlx_draw_pixels_cubes(data, x * data->minimap.cube_size,
					y * data->minimap.cube_size, 0xCCCCCC);
			x++;
		}
		x = 0;
		y++;
	}
}

void	draw_player(t_data *data)
{
	int	center_x;
	int	center_y;
	int	x;
	int	y;

	y = -(data->minimap.player_size / 2);
	center_x = (data->player.px * data->minimap.cube_size) + data->window.width
		/ 2 - (data->parsing.width * data->minimap.cube_size) / 2;
	center_y = (data->player.py * data->minimap.cube_size) + data->window.height
		/ 2 - (data->parsing.height * data->minimap.cube_size) / 2;
	while (y <= data->minimap.player_size / 2)
	{
		x = -(data->minimap.player_size / 2);
		while (x <= data->minimap.player_size / 2)
		{
			if (x * x + y * y <= (data->minimap.player_size / 2)
				* (data->minimap.player_size / 2))
			{
				my_mlx_pixel_put(data->image, center_x + x,
					center_y + y, 0x00FF0000);
			}
			x++;
		}
		y++;
	}
}
