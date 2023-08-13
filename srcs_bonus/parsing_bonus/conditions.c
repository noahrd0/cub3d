/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradal <nradal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:21:55 by nradal            #+#    #+#             */
/*   Updated: 2023/08/01 11:21:09 by nradal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

bool	extract_textures_condition(t_data *data)
{
	if (!data->parsing.n_sprite || !data->parsing.s_sprite
		|| !data->parsing.w_sprite || !data->parsing.e_sprite
		|| !data->parsing.c_color || !data->parsing.f_color)
		return (true);
	return (false);
}

bool	is_map(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (false);
	while (line[i] == 32)
		i++;
	if (!ft_isdigit(line[i]) || ft_strchr("NSWE", line[i]) != NULL)
		return (true);
	return (false);
}

bool	is_legal_line(char *line)
{
	int	i;

	i = 0;
	if (!line || line[i] == '\0')
		return (false);
	while (line[i])
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != '2'
			&& line[i] != 'N' && line[i] != 'S' && line[i] != 'E'
			&& line[i] != 'W' && line[i] != ' ' && line[i] != '\t')
			return (false);
		i++;
	}
	return (true);
}
