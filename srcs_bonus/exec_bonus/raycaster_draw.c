/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_draw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradal <nradal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 20:25:08 by nradal            #+#    #+#             */
/*   Updated: 2023/08/01 11:21:09 by nradal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

t_image	*sprites_selector(t_data *data)
{
	t_image	*texture;

	if (data->sprites.direction == 'N')
		texture = data->sprites.n_image;
	else if (data->sprites.direction == 'S')
		texture = data->sprites.s_image;
	else if (data->sprites.direction == 'W')
		texture = data->sprites.w_image;
	else if (data->sprites.direction == 'E')
		texture = data->sprites.e_image;
	return (texture);
}

void	draw_loop(t_data *data, t_draw draw, t_image *texture, int x)
{
	int	pixel_y;
	int	y;

	pixel_y = (data->window.height - draw.wall_height) / 2;
	y = 0;
	while (y < data->window.height)
	{
		if (y >= pixel_y && y < pixel_y + draw.wall_height)
		{
			draw.tex_y = (int)((y - pixel_y) * draw.wall_texture_step)
				% texture->height;
			draw.tex_x = (int)(draw.texture_offset * texture->width);
			draw.tex_index = (draw.tex_y * texture->line_length)
				+ (draw.tex_x * (texture->bpp / 8));
			draw.tex_color = *(unsigned int *)(texture->addr + draw.tex_index);
			my_mlx_pixel_put(data->image, x, y, draw.tex_color);
		}
		else if (y < pixel_y)
			my_mlx_pixel_put(data->image, x, y, data->parsing.ceiling);
		else
			my_mlx_pixel_put(data->image, x, y, data->parsing.floor);
		y++;
	}
}

void	draw_cf(t_data *data, int column)
{
	int	y;

	y = 0;
	while (y < data->window.height / 2)
	{
		my_mlx_pixel_put(data->image, column, y, data->parsing.ceiling);
		y++;
	}
	while (y < data->window.height)
	{
		my_mlx_pixel_put(data->image, column, y, data->parsing.floor);
		y++;
	}
}

void	draw_walls_init(t_data *data, double wall_distance,
	int x, double texture_offset)
{
	t_draw	draw;
	t_image	*texture;

	texture = sprites_selector(data);
	draw.texture_offset = texture_offset;
	draw.wall_height = (int)(data->window.height / wall_distance);
	draw.wall_texture_step = (double)texture->height / draw.wall_height;
	draw_loop(data, draw, texture, x);
}

void	update_scene(t_data *data, char direction)
{
	if (mlx_clear_window(data->window.mlx_ptr, data->window.win_ptr) == -1)
		error_handler(data, "mlx_clear_window failed");
	raycaster_algo(data);
	if (direction == 'M')
	{
		draw_map(data);
		draw_player(data);
	}
	if (mlx_put_image_to_window
		(data->window.mlx_ptr, data->window.win_ptr, data->image->img, 0, 0)
		== -1)
		error_handler(data, "mlx_put_image_to_window failed");
}
