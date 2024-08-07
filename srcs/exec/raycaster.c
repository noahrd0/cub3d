/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradal <nradal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:22:10 by nradal            #+#    #+#             */
/*   Updated: 2023/08/13 17:45:07 by nradal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	raycaster_vertical(t_data *data, int column)
{
	int		x;
	int		y;

	if (data->ray.delta_x < 0)
	{
		x = round(data->ray.ver_x) - 1;
		data->sprites.direction = 'W';
	}
	else
	{
		x = round(data->ray.ver_x);
		data->sprites.direction = 'E';
	}
	y = (int)floor(data->ray.ver_y);
	if (x < 0 || x >= data->parsing.width || y < 0 || y >= data->parsing.height)
		return (false);
	if (data->parsing.c_map[y][x] == '1')
	{
		draw_walls_init(data,
			(data->ray.ver_dist * cos(data->ray.angle - data->player.angle)),
			column, (data->ray.ver_y - floor(data->ray.ver_y)));
		return (true);
	}
	return (false);
}

bool	raycater_horizontal(t_data *data, int column)
{
	int	x;
	int	y;

	if (data->ray.delta_y < 0)
	{
		y = round(data->ray.hor_y) - 1;
		data->sprites.direction = 'N';
	}
	else
	{
		y = round(data->ray.hor_y);
		data->sprites.direction = 'S';
	}
	x = (int)floor(data->ray.hor_x);
	if (x < 0 || x >= data->parsing.width || y < 0 || y >= data->parsing.height)
		return (false);
	if (data->parsing.c_map[y][x] == '1')
	{
		draw_walls_init(data,
			(data->ray.hor_dist * cos(data->ray.angle - data->player.angle)),
			column, (data->ray.hor_x - floor(data->ray.hor_x)));
		return (true);
	}
	return (false);
}

void	raycaster_loop(t_data *data)
{
	data->ray.ver_x = data->ray.ray_x
		+ (data->ray.sdx + data->ray.add_x) * data->ray.delta_x;
	data->ray.ver_y = data->ray.ray_y
		+ (data->ray.sdx + data->ray.add_x) * data->ray.delta_y;
	data->ray.hor_x = data->ray.ray_x
		+ (data->ray.sdy + data->ray.add_y) * data->ray.delta_x;
	data->ray.hor_y = data->ray.ray_y
		+ (data->ray.sdy + data->ray.add_y) * data->ray.delta_y;
	data->ray.ver_dist
		= fabs((data->ray.ver_x - data->player.px) / data->ray.delta_x);
	data->ray.hor_dist
		= fabs((data->ray.hor_y - data->player.py) / data->ray.delta_y);
}

bool	raycaster_ver_or_hor(t_data *data, int column)
{
	if (data->ray.ver_dist < data->ray.hor_dist)
	{
		if (raycaster_vertical(data, column) == true)
			return (true);
		data->ray.add_x += data->ray.step_x;
	}
	else
	{
		if (raycater_horizontal(data, column) == true)
			return (true);
		data->ray.add_y += data->ray.step_y;
	}
	return (false);
}

void	raycaster_algo(t_data *data)
{
	int	column;
	int	i;

	column = 0;
	while (column < data->window.width)
	{
		i = 0;
		raycaster_init(data, column);
		while (i++ < data->parsing.height * data->parsing.width)
		{
			raycaster_loop(data);
			if (raycaster_ver_or_hor(data, column) == true)
				break ;
			if (i == data->parsing.height * data->parsing.width)
				draw_cf(data, column);
		}
		column++;
	}
}
