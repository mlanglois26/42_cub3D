/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrischma <hrischma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:29:33 by malanglo          #+#    #+#             */
/*   Updated: 2024/10/16 15:15:46 by hrischma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

void	horizontal_ray_init(t_data *data)
{
	data->ray_dir_x0 = 0.0;
	data->ray_dir_y0 = 0.0;
	data->ray_dir_x1 = 0.0;
	data->ray_dir_y1 = 0.0;
	data->floor_x = 0.0;
	data->floor_y = 0.0;
	data->floor_step_x = 0.0;
	data->floor_step_y = 0.0;
	data->floor_color = 0;
	data->ceiling_color = 0;
}

void	designs_to_null(t_data *data)
{
	data->designs->path_wall_ea = NULL;
	data->designs->path_wall_no = NULL;
	data->designs->path_wall_we = NULL;
	data->designs->path_wall_so = NULL;
	data->designs->t_wall_north.img_ptr = NULL;
	data->designs->t_wall_west.img_ptr = NULL;
	data->designs->t_wall_east.img_ptr = NULL;
	data->designs->t_wall_south.img_ptr = NULL;
}

t_data	*init_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->map = NULL;
	data->map_height = 0;
	data->map_width = 0;
	data->elements = NULL;
	data->mlx = NULL;
	data->player = NULL;
	data->direction = NULL;
	data->camera = NULL;
	data->ray = NULL;
	data->designs = malloc(sizeof(t_designs));
	if (!data->designs)
		printf("Nope");
	designs_to_null(data);
	horizontal_ray_init(data);
	return (data);
}

void	parse_file_content(char *file, t_data *data)
{
	file_worth_analysing(file, data);
	data->map = parse_map(file, data);
	data->map_height = get_final_map_height(data->map) - 1;
	data->map_width = get_width_of_longest_h_line(data->map) - 1;
	data->elements = parse_elements(file, data);
	data->move_speed = 0.08;
}

void	set_data_for_raycasting(t_data *data)
{
	data->mlx = my_mlx_init();
	data->player = init_player_vector(data->map);
	data->direction = init_direction_vector(data->player);
	data->camera = init_camera_vector(data->direction);
	data->ray = init_ray(data);
	data->designs->t_wall_east = new_file_img(data->designs->path_wall_ea,
			data);
	data->designs->t_wall_north = new_file_img(data->designs->path_wall_no,
			data);
	data->designs->t_wall_west = new_file_img(data->designs->path_wall_we,
			data);
	data->designs->t_wall_south = new_file_img(data->designs->path_wall_so,
			data);
}
