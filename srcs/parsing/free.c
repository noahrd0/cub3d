/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradal <nradal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 10:38:05 by nradal            #+#    #+#             */
/*   Updated: 2023/08/02 12:23:09 by nradal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_maps(t_data *data)
{
	t_map	*current;
	t_map	*next;
	int		i;

	current = data->parsing.map;
	while (current != NULL)
	{
		next = current->next;
		if (current->line)
			free(current->line);
		free(current);
		current = next;
	}
	i = 0;
	if (data->parsing.c_map)
	{
		while (data->parsing.c_map[i])
			free(data->parsing.c_map[i++]);
		free(data->parsing.c_map);
	}
	data->parsing.map = NULL;
	data->parsing.c_map = NULL;
}

void	free_parsing(t_data *data)
{
	safe_free(data->parsing.n_sprite);
	safe_free(data->parsing.s_sprite);
	safe_free(data->parsing.w_sprite);
	safe_free(data->parsing.e_sprite);
	safe_free(data->parsing.f_color);
	safe_free(data->parsing.c_color);
	data->parsing.ps_x = 0;
	data->parsing.ps_y = 0;
}

void	free_image(t_data *data, t_image *image)
{
	if (image && image->img && data->window.mlx_ptr)
	{
		mlx_destroy_image(data->window.mlx_ptr, image->img);
		free(image);
	}
}

void	free_images(t_data *data)
{
	free_image(data, data->image);
	free_image(data, data->sprites.n_image);
	free_image(data, data->sprites.s_image);
	free_image(data, data->sprites.w_image);
	free_image(data, data->sprites.e_image);
}

void	free_data(t_data *data)
{
	free_parsing(data);
	free_maps(data);
	if (data->game_started == true)
	{
		free_images(data);
		free_mlx(data);
	}
	if (data->parsing.fd != 0)
		if (close(data->parsing.fd) == -1)
			ft_putstr_fd("Error\nClose failed", 2);
	data->window.mlx_ptr = NULL;
	data->window.win_ptr = NULL;
	data->window.x = 0;
	data->window.y = 0;
}
