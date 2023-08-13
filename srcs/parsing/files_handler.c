/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradal <nradal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:17:30 by nradal            #+#    #+#             */
/*   Updated: 2023/08/13 17:47:38 by nradal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_open_file(const char *file)
{
	int	fd;

	fd = open(file, O_DIRECTORY);
	if (fd != -1)
	{
		ft_putstr_fd("Error\nFile is a directory", 2);
		exit (1);
	}
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nAn error occured while opening the file", 2);
		exit (1);
	}
	return (fd);
}

bool	ft_extension(const char	*filename, char	*ext)
{
	int			filename_length;
	const char	*file_extension;
	const char	*last_separator;
	const char	*filename_start;

	if (filename == NULL || ext == NULL)
		return (false);
	filename_length = ft_strlen(filename);
	file_extension = filename + (filename_length - 4);
	last_separator = ft_strrchr(filename, '/');
	filename_start = last_separator + 1;
	if (filename_length <= 4)
		return (false);
	if (ft_strncmp(file_extension, ext, filename_length) != 0)
		return (false);
	if (file_extension == filename)
		return (false);
	if (last_separator == NULL)
		return (true);
	if (filename_start == file_extension)
		return (false);
	return (true);
}

void	verify_textures(t_data *data)
{
	if (ft_extension(data->parsing.n_sprite, ".xpm") == false)
		error_handler(data, "Invalid north sprite extension");
	if (ft_extension(data->parsing.s_sprite, ".xpm") == false)
		error_handler(data, "Invalid south sprite extension");
	if (ft_extension(data->parsing.w_sprite, ".xpm") == false)
		error_handler(data, "Invalid west sprite extension");
	if (ft_extension(data->parsing.e_sprite, ".xpm") == false)
		error_handler(data, "Invalid east sprite extension");
	ft_access(data, data->parsing.n_sprite);
	ft_access(data, data->parsing.s_sprite);
	ft_access(data, data->parsing.w_sprite);
	ft_access(data, data->parsing.e_sprite);
	if (!data->parsing.f_color || !data->parsing.c_color)
		error_handler(data, "Invalid colors");
}
