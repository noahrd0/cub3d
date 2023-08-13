/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradal <nradal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 18:27:35 by nradal            #+#    #+#             */
/*   Updated: 2023/08/01 11:21:09 by nradal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	get_fps(t_data *data)
{
	data->fps.old_time = data->fps.time;
	data->fps.time = clock();
	data->fps.fps = (data->fps.time - data->fps.old_time) / 1000.0;
	if (data->fps.fps > 50)
		data->fps.fps = 50;
}

void	loop_movements(t_data *data)
{
	if (data->player.move.forward)
		move_player(data, 'W');
	if (data->player.move.backward)
		move_player(data, 'S');
	if (data->player.move.left)
		move_player(data, 'A');
	if (data->player.move.right)
		move_player(data, 'D');
	if (data->player.move.rotation_left)
		move_player(data, 'L');
	if (data->player.move.rotation_right)
		move_player(data, 'R');
	if (data->player.map == 1)
		move_player(data, 'M');
	else
		move_player(data, '\0');
}

int	game_loop(t_data *data)
{
	get_fps(data);
	data->image = create_image
		(data->window.mlx_ptr, data->window.width, data->window.height);
	if (data->image == NULL)
		error_handler(data, "Error while creating image");
	loop_movements(data);
	if (mlx_destroy_image(data->window.mlx_ptr, data->image->img) == -1)
		error_handler(data, "Error while destroying image");
	free(data->image);
	data->image = NULL;
	if (data->is_running == false)
		close_window(data);
	return (0);
}

void	display_window(t_data *data)
{
	exec_init(data);
	mlx_hook(data->window.win_ptr, 2, 1L << 0, &key_press, data);
	mlx_hook(data->window.win_ptr, 3, 1L << 1, &key_release, data);
	mlx_hook(data->window.win_ptr, 17, 0, &close_window, data);
	mlx_loop_hook(data->window.mlx_ptr, &game_loop, data);
	mlx_loop(data->window.mlx_ptr);
}
