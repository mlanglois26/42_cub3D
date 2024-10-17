/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrischma <hrischma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:44:14 by malanglo          #+#    #+#             */
/*   Updated: 2024/10/16 14:19:59 by hrischma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

t_image	new_img(int w, int h, t_mlx *mlx)
{
	t_image	image;

	image.img_ptr = mlx_new_image(mlx->mlx_connection, w, h);
	if (image.img_ptr)
	{
		image.img_addr = mlx_get_data_addr(image.img_ptr, &(image.bpp),
				&(image.line_len), &(image.endian));
		image.dimensions.x = w;
		image.dimensions.y = h;
	}
	else
		printf("Pointeur de l'image vide\n");
	return (image);
}

t_image	new_file_img(char *path, t_data *data)
{
	t_image	image;

	image.img_ptr = mlx_xpm_file_to_image(data->mlx->mlx_connection, path,
			&image.dimensions.x, &image.dimensions.y);
	if (!image.img_ptr)
	{
		printf("Error: Failed to load image from path: %s\n", path);
		quit(data);
	}
	image.img_addr = mlx_get_data_addr(image.img_ptr, &(image.bpp),
			&(image.line_len), &(image.endian));
	return (image);
}

t_mlx	*my_mlx_init(void)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		return (NULL);
	mlx->mlx_connection = mlx_init();
	if (!mlx->mlx_connection)
		free_mlx_ptr_and_exit(mlx);
	mlx->window = mlx_new_window(mlx->mlx_connection, WIDTH, HEIGHT, "Cube 3D");
	if (!mlx->window)
	{
		mlx_destroy_display(mlx->mlx_connection);
		free(mlx->mlx_connection);
		free_mlx_ptr_and_exit(mlx);
	}
	mlx->image = new_img(WIDTH, HEIGHT, mlx);
	if (!mlx->image.img_ptr)
	{
		mlx_destroy_window(mlx->mlx_connection, mlx->window);
		mlx_destroy_display(mlx->mlx_connection);
		free(mlx->mlx_connection);
		free_mlx_ptr_and_exit(mlx);
	}
	return (mlx);
}
