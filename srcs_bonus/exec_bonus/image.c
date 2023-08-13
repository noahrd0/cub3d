/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradal <nradal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:42:55 by nradal            #+#    #+#             */
/*   Updated: 2023/08/01 14:49:03 by nradal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

t_image	*create_image(void *mlx_ptr, int width, int height)
{
	t_image	*image;

	image = (t_image *)malloc(sizeof(t_image));
	if (image == NULL)
		return (NULL);
	image->img = mlx_new_image(mlx_ptr, width, height);
	if (image->img == NULL)
		return (free(image), NULL);
	image->addr = mlx_get_data_addr(image->img, &(image->bpp),
			&(image->line_length), &(image->endian));
	if (image->addr == NULL)
		return (mlx_destroy_image(mlx_ptr, image->img), free(image), NULL);
	image->width = width;
	image->height = height;
	return (image);
}

void	my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= image->width || y < 0 || y >= image->height)
		return ;
	dst = image->addr + (y * image->line_length + x * (image->bpp / 8));
	*(unsigned int *)dst = color;
}

t_image	*get_sprites(t_data *data, char *str)
{
	t_image	*sprite;

	sprite = malloc(sizeof(t_image));
	if (sprite == NULL)
		return (NULL);
	sprite->img = mlx_xpm_file_to_image(data->window.mlx_ptr, str,
			&(sprite->width), &(sprite->height));
	if (sprite->img == NULL)
		return (free(sprite), NULL);
	sprite->addr = mlx_get_data_addr(sprite->img, &(sprite->bpp),
			&(sprite->line_length), &(sprite->endian));
	if (sprite->addr == NULL)
		return (mlx_destroy_image(data->window.mlx_ptr, sprite->img),
			free(sprite), NULL);
	return (sprite);
}
