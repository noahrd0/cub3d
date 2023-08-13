/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradal <nradal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:14:18 by nradal            #+#    #+#             */
/*   Updated: 2023/08/01 11:22:26 by nradal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	move_x(t_data *data, double dx)
{
	double	new_player_x;

	new_player_x = data->player.px + dx
		* data->player.move.move_speed * data->fps.fps;
	if ((int)floor(data->player.py) < 0
		|| (int)floor(data->player.py) >= data->parsing.height)
		return ;
	if (data->parsing.c_map[(int)floor(data->player.py)]
		[(int)floor(new_player_x)] == '1')
	{
		while (data->parsing.c_map[(int)floor(data->player.py)]
			[(int)floor(new_player_x)] == '1')
			new_player_x -= dx * 0.2;
	}
	else if (data->parsing.c_map[(int)floor(data->player.py)]
		[(int)floor(new_player_x)] == '2')
		return ;
	data->player.px = new_player_x;
}

void	move_y(t_data *data, double dy)
{
	double	new_player_y;

	new_player_y = data->player.py + dy
		* data->player.move.move_speed * data->fps.fps;
	if ((int)floor(data->player.px) < 0
		|| (int)floor(data->player.px) >= data->parsing.width)
		return ;
	if (data->parsing.c_map[(int)floor(new_player_y)]
		[(int)floor(data->player.px)] == '1')
	{
		while (data->parsing.c_map[(int)floor(new_player_y)]
			[(int)floor(data->player.px)] == '1')
			new_player_y -= dy * 0.2;
	}
	else if (data->parsing.c_map[(int)floor(new_player_y)]
		[(int)floor(data->player.px)] == '2')
		return ;
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
