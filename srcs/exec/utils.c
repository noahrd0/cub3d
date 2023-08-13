/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradal <nradal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 20:59:36 by nradal            #+#    #+#             */
/*   Updated: 2023/08/13 17:09:31 by nradal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	get_wall_size(t_data *data, double x2, double y2)
{
	data->ray.wall_size = sqrt(pow(x2 - data->player.px, 2)
			+ pow(y2 - data->player.py, 2));
}

int	close_window(t_data *data)
{
	free_data(data);
	exit(0);
}
