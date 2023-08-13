/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradal <nradal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:18:17 by nradal            #+#    #+#             */
/*   Updated: 2023/07/31 10:44:48 by nradal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_access(t_data *data, const char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		error_handler(data, "Missing textures");
	close(fd);
}

int	rgb_to_hexa(unsigned char *color)
{
	int	hexa;

	hexa = color[0] << 16 | color[1] << 8 | color[2];
	return (hexa);
}

char	convert_char(char c)
{
	if (c == '1' || c == '0')
		return (c);
	else if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return ('0');
	else
		return ('2');
}

void	convert_line(t_data *data, t_map *current, char **c_map)
{
	int	i;

	i = 0;
	while (current->line[i])
	{
		if (current->line[i] == '1' || current->line[i] == '0')
			(*c_map)[i] = current->line[i];
		else if (current->line[i] == 'N' || current->line[i] == 'S'
			|| current->line[i] == 'W' || current->line[i] == 'E')
			(*c_map)[i] = '0';
		else
			(*c_map)[i] = '2';
		i++;
	}
	while (i < data->parsing.width)
	{
		(*c_map)[i] = '2';
		i++;
	}
	(*c_map)[i] = '\0';
}

void	ll_to_char(t_data *data)
{
	t_map	*current;
	char	**c_map;
	int		row;

	row = 0;
	current = data->parsing.map;
	c_map = (char **)malloc((data->parsing.height + 1) * sizeof(char *));
	if (c_map == NULL)
		error_handler(data, "Memory allocation");
	ft_bzero(c_map, (data->parsing.height + 1) * sizeof(char *));
	while (current != NULL)
	{
		c_map[row] = (char *)malloc((data->parsing.width + 1) * sizeof(char));
		if (c_map[row] == NULL || !is_legal_line(current->line))
			c_map_free(data, c_map,
				"Illegal character in map, or memory allocation");
		convert_line(data, current, &c_map[row]);
		row++;
		current = current->next;
	}
	c_map[row] = NULL;
	data->parsing.c_map = c_map;
}
