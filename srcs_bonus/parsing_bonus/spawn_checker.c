/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradal <nradal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:53:44 by nradal            #+#    #+#             */
/*   Updated: 2023/08/01 11:21:09 by nradal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

bool	is_player_spawn(char c, int *player_spawn_counter)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		(*player_spawn_counter)++;
		return (true);
	}
	return (false);
}

void	find_player_spawn(t_data *data, t_map *current, int x, int y)
{
	data->parsing.ps_x = x;
	data->parsing.ps_y = y - 1;
	if (current->line[x] == 'N')
		data->player.angle = 3 * M_PI / 2;
	else if (current->line[x] == 'S')
		data->player.angle = M_PI / 2;
	else if (current->line[x] == 'E')
		data->player.angle = 0;
	else if (current->line[x] == 'W')
		data->player.angle = M_PI;
}

int	get_map_length(t_data *data, char *line)
{
	int	length;

	length = ft_strlen(line);
	if (length > data->parsing.width)
		data->parsing.width = length;
	return (length);
}

int	player_spawn_checker(t_data *data)
{
	int		length;
	int		x; 
	int		y;
	int		player_spawn_counter;
	t_map	*current;

	current = data->parsing.map;
	player_spawn_counter = 0;
	y = 0;
	while (current != NULL)
	{
		y++;
		x = -1;
		length = get_map_length(data, current->line);
		while (++x < length)
		{
			if (is_player_spawn(current->line[x], &player_spawn_counter))
				find_player_spawn(data, current, x, y);
		}
		current = current->next;
	}
	data->parsing.height = y;
	if (player_spawn_counter == 0 || player_spawn_counter >= 2)
		error_handler(data, "The map must have exactly 1 player spawn point");
	return (player_spawn_counter);
}

void	explore_map_recursive(t_data *data, int x, int y, int *count)
{
	char	current;

	current = data->parsing.c_map[y][x];
	if (current == 'v' || current == '1')
		return ;
	if (current == '2')
		(*count)++;
	if (current == '0')
	{
		data->parsing.c_map[y][x] = 'v';
		if (x == 0 || x == data->parsing.width - 1)
			(*count)++;
		if (y == 0 || y == data->parsing.height - 1)
			(*count)++;
		if (x > 0) 
			explore_map_recursive(data, x - 1, y, count);
		if (x < data->parsing.width - 1)
			explore_map_recursive(data, x + 1, y, count);
		if (y > 0)
			explore_map_recursive(data, x, y - 1, count);
		if (y < data->parsing.height - 1)
			explore_map_recursive(data, x, y + 1, count);
	}
}
