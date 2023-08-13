/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradal <nradal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 21:02:13 by nradal            #+#    #+#             */
/*   Updated: 2023/08/01 11:21:09 by nradal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	move_forward(t_data *data)
{
	move_x(data, cos(data->player.angle));
	move_y(data, sin(data->player.angle));
}

void	move_backward(t_data *data)
{
	move_x(data, -cos(data->player.angle));
	move_y(data, -sin(data->player.angle));
}

void	move_left(t_data *data)
{
	move_x(data, cos(data->player.angle - M_PI / 2));
	move_y(data, sin(data->player.angle - M_PI / 2));
}

void	move_right(t_data *data)
{
	move_x(data, cos(data->player.angle + M_PI / 2));
	move_y(data, sin(data->player.angle + M_PI / 2));
}
