/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_casting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrischma <hrischma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:31:35 by malanglo          #+#    #+#             */
/*   Updated: 2024/10/16 13:53:09 by hrischma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

void	init_ray_2(t_ray *ray, int x)
{
	ray[x].side_dist_x = 0.0;
	ray[x].side_dist_y = 0.0;
	ray[x].side = -1;
	ray[x].perp_wall_dist = 0;
	ray[x].line_height = 0;
	ray[x].start_draw = 0.0;
	ray[x].end_draw = 0.0;
}

t_ray	*init_ray(t_data *data)
{
	t_ray	*ray;
	int		x;

	ray = malloc(sizeof(t_ray) * (int)WIDTH);
	if (!ray)
		return (NULL);
	x = 0;
	while (x < WIDTH)
	{
		ray[x].dir_vec = data->direction;
		ray[x].cam_vec = data->camera;
		ray[x].dir_x = 0.0;
		ray[x].dir_y = 0.0;
		ray[x].camera_pos_x = 0.0;
		ray[x].delta_x = 0.0;
		ray[x].delta_y = 0.0;
		ray[x].step_x = 0;
		ray[x].step_y = 0;
		ray[x].player_vec = data->player;
		ray[x].map_x = (int)data->player->x;
		ray[x].map_y = (int)data->player->y;
		init_ray_2(ray, x);
		x++;
	}
	return (ray);
}

void	reset_everything(t_data *data, int x)
{
	data->ray[x].dir_vec = data->direction;
	data->ray[x].cam_vec = data->camera;
	data->ray[x].dir_x = 0.0;
	data->ray[x].dir_y = 0.0;
	data->ray[x].camera_pos_x = 0.0;
	data->ray[x].delta_x = 0.0;
	data->ray[x].delta_y = 0.0;
	data->ray[x].step_x = 0;
	data->ray[x].step_y = 0;
	data->ray[x].side_dist_x = 0.0;
	data->ray[x].side_dist_y = 0.0;
	data->ray[x].player_vec = data->player;
	data->ray[x].map_x = (int)data->player->x;
	data->ray[x].map_y = (int)data->player->y;
	data->ray[x].side = -1;
	data->ray[x].perp_wall_dist = 0;
	data->ray[x].line_height = 0;
}

int	raycasting(t_data *data)
{
	int	x;

	x = 0;
	floor_ceiling_casting(data);
	while (x < WIDTH)
	{
		reset_everything(data, x);
		calculate_ray_dir(data, x);
		calculate_deltas(data, x);
		get_step_and_initial_side_dist(data, x);
		perform_dda(data, x);
		get_line_height(data, x);
		draw(data, x);
		x++;
	}
	mlx_put_image_to_window(data->mlx->mlx_connection, data->mlx->window,
		data->mlx->image.img_ptr, 0, 0);
	return (0);
}
