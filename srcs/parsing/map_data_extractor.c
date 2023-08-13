/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data_extractor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradal <nradal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:55:13 by nradal            #+#    #+#             */
/*   Updated: 2023/08/13 17:47:32 by nradal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	get_cub_data(t_data *data, int fd)
{
	char	*line;
	t_map	*current;
	t_map	*new_node;

	current = NULL;
	new_node = NULL;
	line = get_next_line(fd);
	while (line)
	{
		new_node = (t_map *)malloc(sizeof(t_map));
		if (new_node == NULL)
		{
			free(line);
			error_handler(data, "Memory allocation");
		}
		new_node->line = ft_strdup(line);
		new_node->next = NULL;
		free(line);
		map_assignation(data, &current, &new_node);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
}

void	map_assignation(t_data *data, t_map **current
						, t_map **new_node)
{
	if ((*new_node)->line == NULL)
		error_handler(data, "Memory allocation");
	if (*current == NULL)
	{
		data->parsing.map = *new_node;
		*current = data->parsing.map;
	}
	else
	{
		(*current)->next = *new_node;
		*current = (*current)->next;
	}
}

void	extract_colors(t_data *data, char *line)
{
	if (ft_strncmp(line, "F", 1) == 0)
	{
		if (data->parsing.f_color)
			error_handler(data, "There is two or more floor colors");
		data->parsing.f_color = colors_handler(data, line + 1);
	}
	else if (ft_strncmp(line, "C", 1) == 0)
	{
		if (data->parsing.c_color)
			error_handler(data, "There is two or more ceiling colors");
		data->parsing.c_color = colors_handler(data, line + 1);
	}
}

void	extract_sprites(t_data *data, char *line)
{
	if (ft_strncmp(line, "NO", 2) == 0)
	{
		if (data->parsing.n_sprite)
			error_handler(data, "There is two or more north sprites");
		data->parsing.n_sprite = ft_strdup(line + 2);
	}
	else if (ft_strncmp(line, "SO", 2) == 0)
	{
		if (data->parsing.s_sprite)
			error_handler(data, "There is two or more south sprites");
		data->parsing.s_sprite = ft_strdup(line + 2);
	}
	else if (ft_strncmp(line, "WE", 2) == 0)
	{
		if (data->parsing.w_sprite)
			error_handler(data, "There is two or more west sprites");
		data->parsing.w_sprite = ft_strdup(line + 2);
	}
	else if (ft_strncmp(line, "EA", 2) == 0)
	{
		if (data->parsing.e_sprite)
			error_handler(data, "There is two or more east sprites");
		data->parsing.e_sprite = ft_strdup(line + 2);
	}
}

void	extract_textures(t_data *data)
{
	t_map	*current;

	current = data->parsing.map;
	while (current)
	{
		clean_line(data, &current->line);
		extract_sprites(data, current->line);
		extract_colors(data, current->line);
		current = current->next;
	}
}
