/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradal <nradal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 11:35:24 by nradal            #+#    #+#             */
/*   Updated: 2023/07/31 17:48:00 by nradal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	error_handler(t_data *data, char *error)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(error, 2);
	if (data)
		free_data(data);
	exit(1);
}

void	safe_free(void *ptr)
{
	if (ptr != NULL)
		free(ptr);
}

void	c_map_free(t_data *data, char **c_map, char *str)
{
	int	i;

	i = 0;
	if (c_map)
	{
		while (c_map[i])
		{
			free(c_map[i]);
			i++;
		}
		free(c_map);
	}
	error_handler(data, str);
}

void	free_mlx(t_data *data)
{
	if (data->window.mlx_ptr)
	{
		mlx_destroy_window(data->window.mlx_ptr, data->window.win_ptr);
		mlx_destroy_display(data->window.mlx_ptr);
		mlx_loop_end(data->window.mlx_ptr);
		free(data->window.mlx_ptr);
	}
	data->window.mlx_ptr = NULL;
	data->window.win_ptr = NULL;
	data->window.x = 0;
	data->window.y = 0;
}
