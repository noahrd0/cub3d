/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradal <nradal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:42:21 by nradal            #+#    #+#             */
/*   Updated: 2023/08/01 11:21:09 by nradal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	rotation_left(t_data *data)
{
	double	rotation_speed;

	rotation_speed = data->player.move.rotation_speed * data->fps.fps;
	data->player.angle -= rotation_speed;
	if (data->player.angle < 0)
		data->player.angle += 2 * M_PI;
}

void	rotation_right(t_data *data)
{
	double	rotation_speed;

	rotation_speed = data->player.move.rotation_speed * data->fps.fps;
	data->player.angle += rotation_speed;
	if (data->player.angle > 2 * M_PI)
		data->player.angle -= 2 * M_PI;
}
