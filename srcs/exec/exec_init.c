/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradal <nradal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:37:42 by nradal            #+#    #+#             */
/*   Updated: 2023/07/31 12:41:38 by nradal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	exec_init(t_data *data)
{
	data->window.mlx_ptr = mlx_init();
	if (data->window.mlx_ptr == NULL)
		error_handler(data, "mlx_init failed");
	data->window.win_ptr
		= mlx_new_window(data->window.mlx_ptr, WIDTH, HEIGHT, "Cub3D");
	if (data->window.win_ptr == NULL)
	{
		mlx_destroy_display(data->window.mlx_ptr);
		free(data->window.mlx_ptr);
		error_handler(data, "mlx_new_window failed");
	}
	data->game_started = true;
	init_sprites(data);
	data->window.width = WIDTH;
	data->window.height = HEIGHT;
	data->player.move.last_frame_time = clock();
	data->player.px = data->parsing.ps_x + 0.5;
	data->player.py = data->parsing.ps_y + 0.5;
	data->player.move.move_speed = 0.005;
	data->player.move.rotation_speed = 0.002;
	data->minimap.cube_size = 10;
	data->minimap.player_size = 5;
	data->is_running = true;
}

void	init_sprites(t_data *data)
{
	data->sprites.n_image = get_sprites(data, data->parsing.n_sprite);
	data->sprites.s_image = get_sprites(data, data->parsing.s_sprite);
	data->sprites.w_image = get_sprites(data, data->parsing.w_sprite);
	data->sprites.e_image = get_sprites(data, data->parsing.e_sprite);
	if (data->sprites.n_image == NULL || data->sprites.s_image == NULL
		|| data->sprites.w_image == NULL || data->sprites.e_image == NULL)
		error_handler(data, "Error while loading sprites");
}

void	init_image(t_data *data, t_image *image)
{
	image = (t_image *)malloc(sizeof(t_image));
	if (image == NULL)
		error_handler(data, "Error while allocating memory for image");
}
