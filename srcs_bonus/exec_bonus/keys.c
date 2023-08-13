/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradal <nradal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 20:13:24 by nradal            #+#    #+#             */
/*   Updated: 2023/08/01 11:21:09 by nradal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

/*
** Keycodes:
** 119		=	W
** 115		=	S
** 97		=	A
** 100		=	D
** 113		=	Q
** 101		=	E
** 65362	=	UP
** 65364	=	DOWN
** 65361	=	LEFT
** 65363	=	RIGHT
** 109		=	M
** 65307	=	ESC
*/

int	key_press(int keycode, t_data *data)
{
	if (keycode == 119 || keycode == 65362)
		data->player.move.forward = 1;
	else if (keycode == 115 || keycode == 65364)
		data->player.move.backward = 1;
	else if (keycode == 97)
		data->player.move.left = 1;
	else if (keycode == 100)
		data->player.move.right = 1;
	else if (keycode == 113 || keycode == 65361)
		data->player.move.rotation_left = 1;
	else if (keycode == 101 || keycode == 65363)
		data->player.move.rotation_right = 1;
	else if (keycode == 109)
	{
		if (data->player.map == 0)
			data->player.map = 1;
		else
			data->player.map = 0;
	}
	else if (keycode == 65307)
		data->is_running = false;
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == 119 || keycode == 65362)
		data->player.move.forward = 0;
	else if (keycode == 115 || keycode == 65364)
		data->player.move.backward = 0;
	else if (keycode == 97)
		data->player.move.left = 0;
	else if (keycode == 100)
		data->player.move.right = 0;
	else if (keycode == 113 || keycode == 65361)
		data->player.move.rotation_left = 0;
	else if (keycode == 101 || keycode == 65363)
		data->player.move.rotation_right = 0;
	return (0);
}
