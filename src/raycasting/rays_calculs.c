/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_calculs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrischma <hrischma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:13:43 by malanglo          #+#    #+#             */
/*   Updated: 2024/10/16 13:53:07 by hrischma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

void	calculate_ray_dir(t_data *data, int x)
{
	data->ray[x].camera_pos_x = 2 * x / (double)(WIDTH - 1) - 1;
	data->ray[x].dir_x = data->ray->dir_vec->x + data->ray->cam_vec->x
		* data->ray[x].camera_pos_x;
	data->ray[x].dir_y = data->ray->dir_vec->y + data->ray->cam_vec->y
		* data->ray[x].camera_pos_x;
}

void	calculate_deltas(t_data *data, int x)
{
	data->ray[x].delta_x = ft_abs(1 / data->ray[x].dir_x);
	data->ray[x].delta_y = ft_abs(1 / data->ray[x].dir_y);
}

void	get_step_and_initial_side_dist(t_data *data, int x)
{
	if (data->ray[x].dir_x < 0)
	{
		data->ray[x].step_x = -1;
		data->ray[x].side_dist_x = (data->ray[x].player_vec->x
				- data->ray[x].map_x) * data->ray[x].delta_x;
	}
	else
	{
		data->ray[x].step_x = 1;
		data->ray[x].side_dist_x = (data->ray[x].map_x + 1.0
				- data->ray[x].player_vec->x) * data->ray[x].delta_x;
	}
	if (data->ray[x].dir_y < 0)
	{
		data->ray[x].step_y = -1;
		data->ray[x].side_dist_y = (data->ray[x].player_vec->y
				- data->ray[x].map_y) * data->ray[x].delta_y;
	}
	else
	{
		data->ray[x].step_y = 1;
		data->ray[x].side_dist_y = (data->ray[x].map_y + 1.0
				- data->ray[x].player_vec->y) * data->ray[x].delta_y;
	}
}

void	perform_dda(t_data *data, int x)
{
	while (1)
	{
		if (data->ray[x].side_dist_x < data->ray[x].side_dist_y)
		{
			data->ray[x].side_dist_x += data->ray[x].delta_x;
			data->ray[x].map_x += data->ray[x].step_x;
			data->ray[x].side = 0;
		}
		else
		{
			data->ray[x].side_dist_y += data->ray[x].delta_y;
			data->ray[x].map_y += data->ray[x].step_y;
			data->ray[x].side = 1;
		}
		if (data->ray[x].map_y >= 0 && data->ray[x].map_y <= data->map_height
			&& data->ray[x].map_x >= 0 && data->ray[x].map_x <= data->map_width)
		{
			if (data->map[data->ray[x].map_y][data->ray[x].map_x] == '1')
				break ;
		}
	}
}

void	get_line_height(t_data *data, int x)
{
	if (data->ray[x].side == 0)
		data->ray[x].perp_wall_dist = data->ray[x].side_dist_x
			- data->ray[x].delta_x;
	else
		data->ray[x].perp_wall_dist = data->ray[x].side_dist_y
			- data->ray[x].delta_y;
	if (data->ray[x].perp_wall_dist < 0.0001)
		data->ray[x].perp_wall_dist = 0.0001;
	data->ray[x].line_height = (int)(HEIGHT / data->ray[x].perp_wall_dist);
	if (data->ray[x].line_height > DBL_MAX)
		data->ray[x].line_height = HEIGHT;
}
