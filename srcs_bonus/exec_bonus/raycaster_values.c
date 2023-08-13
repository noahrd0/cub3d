/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_values.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradal <nradal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 20:19:57 by nradal            #+#    #+#             */
/*   Updated: 2023/08/01 11:21:09 by nradal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

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
