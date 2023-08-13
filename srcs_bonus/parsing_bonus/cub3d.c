/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradal <nradal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:26:12 by nradal            #+#    #+#             */
/*   Updated: 2023/08/13 17:54:30 by nradal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int	main(int argc, const char **argv)
{
	t_data	data;

	if (argc == 2 && ft_extension(argv[1], ".cub"))
	{
		map_parser(&data, argv[1]);
		display_window(&data);
		free_data(&data);
	}
	else
	{
		ft_putstr_fd("Error\nInvalid format !\n(./cub3d map.cub)", 2);
		exit (1);
	}
	return (0);
}
