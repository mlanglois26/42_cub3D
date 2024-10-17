/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 10:54:56 by malanglo          #+#    #+#             */
/*   Updated: 2024/10/17 11:19:16 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

void	rotate_right(t_data *data)
{
	double	rot_speed;
	double	old_dir_x;
	double	old_camera_x;

	rot_speed = 0.05;
	old_dir_x = data->direction->x;
	data->direction->x = data->direction->x * cos(rot_speed)
		- data->direction->y * sin(rot_speed);
	data->direction->y = old_dir_x * sin(rot_speed) + data->direction->y
		* cos(rot_speed);
	old_camera_x = data->camera->x;
	data->camera->x = data->camera->x * cos(rot_speed) - data->camera->y
		* sin(rot_speed);
	data->camera->y = old_camera_x * sin(rot_speed) + data->camera->y
		* cos(rot_speed);
}

void	rotate_left(t_data *data)
{
	double	rot_speed;
	double	old_dir_x;
	double	old_camera_x;

	rot_speed = 0.05;
	old_dir_x = data->direction->x;
	data->direction->x = data->direction->x * cos(-rot_speed)
		- data->direction->y * sin(-rot_speed);
	data->direction->y = old_dir_x * sin(-rot_speed) + data->direction->y
		* cos(-rot_speed);
	old_camera_x = data->camera->x;
	data->camera->x = data->camera->x * cos(-rot_speed) - data->camera->y
		* sin(-rot_speed);
	data->camera->y = old_camera_x * sin(-rot_speed) + data->camera->y
		* cos(-rot_speed);
}

static void	check_key(int key, t_data *data)
{
	if (key == XK_Escape)
		quit(data);
	if (key == 119)
		move_forward(data);
	else if (key == 115)
		move_backward(data);
	if (data->player->z == 'N' || data->player->z == 'S')
	{
		if (key == 97)
			move_right(data);
		else if (key == 100)
			move_left(data);	
		else if (key == 65363)
			rotate_left(data);
		else if (key == 65361)
			rotate_right(data);
	}
	else
	{
		if (key == 97)
			move_left(data);
		else if (key == 100)
			move_right(data);
		else if (key == 65363)
			rotate_right(data);
		else if (key == 65361)
			rotate_left(data);
	}
}

int	on_key_press(int key, t_data *data)
{
	if (data->mlx->image.img_ptr)
	{
		mlx_destroy_image(data->mlx->mlx_connection, data->mlx->image.img_ptr);
		data->mlx->image.img_ptr = NULL;
		data->mlx->image.img_ptr = mlx_new_image(data->mlx->mlx_connection,
				WIDTH, HEIGHT);
		data->mlx->image.img_addr = mlx_get_data_addr(data->mlx->image.img_ptr,
				&data->mlx->image.bpp, &data->mlx->image.line_len,
				&data->mlx->image.endian);
	}
	check_key(key, data);
	raycasting(data);
	return (0);
}
