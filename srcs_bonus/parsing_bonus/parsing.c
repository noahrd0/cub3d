/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradal <nradal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:59:20 by nradal            #+#    #+#             */
/*   Updated: 2023/08/01 11:21:09 by nradal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	map_parser(t_data *data, const char *map)
{
	int	count;

	ft_bzero(data, sizeof(t_data));
	data->parsing.fd = ft_open_file(map);
	get_cub_data(data, data->parsing.fd);
	extract_textures(data);
	verify_textures(data);
	data->parsing.floor = rgb_to_hexa(data->parsing.f_color);
	data->parsing.ceiling = rgb_to_hexa(data->parsing.c_color);
	remove_cub_data_lines(data);
	player_spawn_checker(data);
	ll_to_char(data);
	count = 0;
	explore_map_recursive(data, data->parsing.ps_x, data->parsing.ps_y, &count);
	if (count != 0)
		error_handler(data, "Map must be surrounded by walls");
}
