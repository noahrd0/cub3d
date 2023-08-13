/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_values.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradal <nradal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 20:19:57 by nradal            #+#    #+#             */
/*   Updated: 2023/08/13 17:09:13 by nradal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	horizontal_crossings(t_data *data)
{
	double	next_x;
	double	next_y;
	double	pixel_x;
	double	pixel_y;

	if (data->ray.delta_y >= 0)
		next_y = ceil(data->ray.ray_y);
	else
		next_y = floor(data->ray.ray_y);
	next_x
		= data->ray.ray_x + (next_y - data->ray.ray_y) / tan(data->ray.angle);
	pixel_x = data->player.px + (fabs((next_x - data->ray.ray_x)
				/ data->ray.delta_x)) * data->ray.delta_x;
	pixel_y = data->player.py + (fabs((next_y - data->ray.ray_y)
				/ data->ray.delta_y)) * data->ray.delta_y;
	data->ray.sdy = sqrt(pow(pixel_x - data->player.px, 2)
			+ pow(pixel_y - data->player.py, 2));
	data->ray.step_y = sqrt(1 + (data->ray.delta_x * data->ray.delta_x)
			/ (data->ray.delta_y * data->ray.delta_y));
}

void	vertical_crossing(t_data *data)
{
	double	next_x;
	double	next_y;
	double	pixel_x;
	double	pixel_y;

	if (data->ray.delta_x >= 0)
		next_x = ceil(data->ray.ray_x);
	else
		next_x = floor(data->ray.ray_x);
	next_y
		= data->ray.ray_y + (next_x - data->ray.ray_x) * tan(data->ray.angle);
	pixel_x = data->player.px + (fabs((next_x - data->ray.ray_x)
				/ data->ray.delta_x)) * data->ray.delta_x;
	pixel_y = data->player.py + (fabs((next_y - data->ray.ray_y)
				/ data->ray.delta_y)) * data->ray.delta_y;
	data->ray.sdx = sqrt(pow(pixel_x - (data->player.px), 2)
			+ pow(pixel_y - (data->player.py), 2));
	data->ray.step_x = sqrt(1 + (data->ray.delta_y * data->ray.delta_y)
			/ (data->ray.delta_x * data->ray.delta_x));
}

void	raycaster_init(t_data *data, int column)
{
	data->ray.angle_increment
		= atan((column - data->window.width / 2.0) / data->window.width * 1.5);
	data->ray.angle = data->player.angle + data->ray.angle_increment;
	if (data->ray.angle == 0)
		data->ray.angle = 0.00001;
	data->ray.delta_x = cos(data->ray.angle);
	data->ray.delta_y = sin(data->ray.angle);
	data->ray.ray_x = data->player.px;
	data->ray.ray_y = data->player.py;
	horizontal_crossings(data);
	vertical_crossing(data);
	data->ray.add_x = data->ray.step_x;
	data->ray.add_y = data->ray.step_y;
	data->ray.sdx = data->ray.sdx - data->ray.add_x;
	data->ray.sdy = data->ray.sdy - data->ray.add_y;
	data->ray.ver_x = data->ray.ray_x + (data->ray.sdx) * data->ray.delta_x;
	data->ray.ver_y = data->ray.ray_y + (data->ray.sdx) * data->ray.delta_y;
	data->ray.hor_x = data->ray.ray_x + (data->ray.sdy) * data->ray.delta_x;
	data->ray.hor_y = data->ray.ray_y + (data->ray.sdy) * data->ray.delta_y;
}
