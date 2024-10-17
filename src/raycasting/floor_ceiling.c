/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrischma <hrischma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 17:27:15 by malanglo          #+#    #+#             */
/*   Updated: 2024/10/16 13:52:58 by hrischma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

unsigned int	create_rgb(int r, int g, int b)
{
	return ((r & 0xFF) << 16 | (g & 0xFF) << 8 | (b & 0xFF));
}

void	get_ray_dir(t_data *data)
{
	data->ray_dir_x0 = data->direction->x - data->camera->x;
	data->ray_dir_y0 = data->direction->y - data->camera->y;
	data->ray_dir_x1 = data->direction->x + data->camera->x;
	data->ray_dir_y1 = data->direction->y + data->camera->y;
}

void	get_row_ditance(t_data *data, int p, double *row_distance)
{
	double	pos_z;

	pos_z = 0.5 * (int)HEIGHT;
	*row_distance = pos_z / p;
	data->floor_step_x = (*row_distance) * (data->ray_dir_x1 - data->ray_dir_x0)
		/ WIDTH;
	data->floor_step_y = (*row_distance) * (data->ray_dir_y1 - data->ray_dir_y0)
		/ WIDTH;
	data->floor_x = data->player->x + (*row_distance) * data->ray_dir_x0;
	data->floor_y = data->player->y + (*row_distance) * data->ray_dir_y0;
}

void	draw_floor_ceiling(t_data *data, int y)
{
	int	x;

	x = 0;
	while (x < WIDTH)
	{
		if (y >= 0 && y < HEIGHT)
			*((int *)data->mlx->image.img_addr + y * WIDTH
					+ x) = data->floor_color;
		if (y >= 0 && y < HEIGHT)
			*((int *)data->mlx->image.img_addr + (HEIGHT - y - 1) * WIDTH
					+ x) = data->ceiling_color;
		data->floor_x += data->floor_step_x;
		data->floor_y += data->floor_step_y;
		x++;
	}
}

void	floor_ceiling_casting(t_data *data)
{
	int		y;
	int		p;
	double	row_distance;

	data->floor_color = create_rgb(data->designs->floor.r,
			data->designs->floor.g, data->designs->floor.b);
	data->ceiling_color = create_rgb(data->designs->ceiling.r,
			data->designs->ceiling.g, data->designs->ceiling.b);
	get_ray_dir(data);
	y = 0;
	while (y < HEIGHT)
	{
		p = y - HEIGHT / 2;
		if (p != 0)
		{
			get_row_ditance(data, p, &row_distance);
			draw_floor_ceiling(data, y);
		}
		y++;
	}
}
