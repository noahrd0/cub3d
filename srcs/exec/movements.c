/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradal <nradal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:14:18 by nradal            #+#    #+#             */
/*   Updated: 2023/07/31 17:49:00 by nradal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_forward(t_data *data)
{
	double	move_speed;
	double	new_player_x;
	double	new_player_y;

	move_speed = data->player.move.move_speed * data->fps.fps;
	new_player_x = data->player.px
		+ cos(data->player.angle) * move_speed;
	new_player_y = data->player.py
		+ sin(data->player.angle) * move_speed;
	data->player.px = new_player_x;
	data->player.py = new_player_y;
}

void	move_backward(t_data *data)
{
	double	move_speed;
	double	new_player_x;
	double	new_player_y;

	move_speed = data->player.move.move_speed * data->fps.fps;
	new_player_x = data->player.px
		- cos(data->player.angle) * move_speed;
	new_player_y = data->player.py
		- sin(data->player.angle) * move_speed;
	data->player.px = new_player_x;
	data->player.py = new_player_y;
}

void	move_left(t_data *data)
{
	double	move_speed;
	double	new_player_x;
	double	new_player_y;

	move_speed = data->player.move.move_speed * data->fps.fps;
	new_player_x = data->player.px
		+ cos(data->player.angle - M_PI / 2) * move_speed;
	new_player_y = data->player.py
		+ sin(data->player.angle - M_PI / 2) * move_speed;
	data->player.px = new_player_x;
	data->player.py = new_player_y;
}

void	move_right(t_data *data)
{
	double	move_speed;
	double	new_player_x;
	double	new_player_y;

	move_speed = data->player.move.move_speed * data->fps.fps;
	new_player_x = data->player.px
		+ cos(data->player.angle + M_PI / 2) * move_speed;
	new_player_y = data->player.py
		+ sin(data->player.angle + M_PI / 2) * move_speed;
	data->player.px = new_player_x;
	data->player.py = new_player_y;
}

void	move_player(t_data *data, char direction)
{
	if (direction == 'W')
		move_forward(data);
	else if (direction == 'S')
		move_backward(data);
	else if (direction == 'A')
		move_left(data);
	else if (direction == 'D')
		move_right(data);
	else if (direction == 'L')
		rotation_left(data);
	else if (direction == 'R')
		rotation_right(data);
	update_scene(data, direction);
}
