/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vectors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrischma <hrischma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:04:25 by malanglo          #+#    #+#             */
/*   Updated: 2024/10/16 13:53:05 by hrischma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

t_player_vec	*init_player_vector(char **map)
{
	t_player_vec	*player;
	int				i_axis;

	int (j_axis) = 0;
	player = malloc(sizeof(t_player_vec));
	if (!player)
		return (NULL);
	while (map[j_axis] != NULL)
	{
		i_axis = 0;
		while (map[j_axis][i_axis] != '\0')
		{
			if (is_player_char(map[j_axis][i_axis]) == 1)
			{
				player->x = (double)i_axis + 0.5;
				player->y = (double)j_axis + 0.5;
				player->z = map[j_axis][i_axis];
				map[j_axis][i_axis] = '0';
				return (player);
			}
			i_axis++;
		}
		j_axis++;
	}
	return (free(player), NULL);
}

t_direction_vec	*init_direction_vector(t_player_vec *player)
{
	t_direction_vec	*direction;

	direction = malloc(sizeof(t_direction_vec));
	if (!direction)
		return (NULL);
	if (player->z == 'N')
		direction->angle = 270;
	else if (player->z == 'S')
		direction->angle = 90;
	else if (player->z == 'W')
		direction->angle = 180;
	else if (player->z == 'E')
		direction->angle = 0;
	direction->angle = degrees_to_radians(direction->angle);
	direction->x = cos(direction->angle);
	direction->y = sin(direction->angle);
	if (ft_abs(direction->x) < 0.000001)
		direction->x = 0;
	if (ft_abs(direction->y) < 0.000001)
		direction->y = 0;
	return (direction);
}

t_camera_vec	*init_camera_vector(t_direction_vec *dir)
{
	t_camera_vec	*camera;
	double			fov_scale;

	camera = malloc(sizeof(t_camera_vec));
	if (!camera)
		return (NULL);
	fov_scale = 0.66;
	camera->x = sin(dir->angle) * fov_scale;
	camera->y = cos(dir->angle) * fov_scale;
	if (ft_abs(camera->x) < 0.000001)
		camera->x = 0;
	if (ft_abs(camera->y) < 0.000001)
		camera->y = 0;
	return (camera);
}
