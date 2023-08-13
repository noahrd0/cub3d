/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradal <nradal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:16:30 by nradal            #+#    #+#             */
/*   Updated: 2023/08/01 11:21:09 by nradal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	set_color(t_data *data, char *token, unsigned char **color, int index)
{
	int	i;
	int	value;

	i = 0;
	if (index >= 3)
		return ;
	while (token[i])
	{
		if (!ft_isdigit(token[i]))
		{
			free(*color);
			error_handler(data, "RGB values must be numeric.");
		}
		i++;
	}
	value = ft_atoi(token);
	if (value < 0 || value > 255)
	{
		free(*color);
		error_handler(data, "Invalid RGB value.");
	}
	(*color)[index] = (unsigned char)value;
}

unsigned char	*colors_handler(t_data *data, char *line)
{
	unsigned char	*color;
	char			*token;
	int				i;

	i = 0;
	color = (unsigned char *)malloc(3 * sizeof(unsigned char));
	if (!color)
		error_handler(data, "Memory allocation");
	token = ft_strtok(&line, ',');
	while (token != NULL)
	{
		set_color(data, token, &color, i);
		token = ft_strtok(&line, ',');
		i++;
	}
	if (i != 3)
	{
		free(color);
		error_handler(data, "Invalid number of RGB values.");
	}
	return (color);
}

void	clean_line(t_data *data, char **line)
{
	int		i;
	int		j;
	int		length;
	char	*new_line;

	i = 0;
	j = 0;
	length = 0;
	while ((*line)[i])
	{
		if ((*line)[i] != ' ')
			length++;
		i++;
	}
	new_line = malloc((length + 1) * sizeof(char));
	if (!new_line)
		error_handler(data, "Memory allocation");
	i = -1;
	while ((*line)[++i])
		if ((*line)[i] != ' ')
			new_line[j++] = (*line)[i];
	new_line[j] = '\0';
	free(*line);
	*line = new_line;
}

void	remove_cub_data_lines(t_data *data)
{
	t_map	*current;
	t_map	*next;

	current = data->parsing.map;
	while (is_map(current->line))
	{
		next = current->next;
		free(current->line);
		free(current);
		current = next;
	}
	data->parsing.map = current;
}
