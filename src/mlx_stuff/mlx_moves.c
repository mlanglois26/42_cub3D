/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrischma <hrischma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:11:06 by malanglo          #+#    #+#             */
/*   Updated: 2024/10/16 13:53:25 by hrischma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

void	move_forward(t_data *data)
{
	double	tmp_y;
	double	tmp_x;

	tmp_y = data->player->y + data->direction->y * data->move_speed;
	tmp_x = data->player->x + data->direction->x * data->move_speed;
	if ((tmp_x > data->map_width || tmp_x < 0)
		|| data->map[(int)data->player->y][(int)(tmp_x)] == '1')
		return ;
	if ((tmp_y > data->map_height || tmp_y < 0)
		|| data->map[(int)tmp_y][(int)(tmp_x)] == '1')
		return ;
	data->player->x = tmp_x;
	data->player->y = tmp_y;
}

void	move_backward(t_data *data)
{
	double	tmp_x;
	double	tmp_y;

	tmp_x = data->player->x - data->direction->x * data->move_speed;
	tmp_y = data->player->y - data->direction->y * data->move_speed;
	if ((tmp_x > data->map_width || tmp_x < 0)
		|| data->map[(int)data->player->y][(int)(tmp_x)] == '1')
		return ;
	if ((tmp_y > data->map_height || tmp_y < 0)
		|| data->map[(int)tmp_y][(int)(tmp_x)] == '1')
		return ;
	data->player->x = tmp_x;
	data->player->y = tmp_y;
}

void	move_left(t_data *data)
{
	double	tmp_x;
	double	tmp_y;

	tmp_x = data->player->x + data->direction->y * data->move_speed;
	tmp_y = data->player->y - data->direction->x * data->move_speed;
	if ((tmp_x > data->map_width || tmp_x < 0)
		|| data->map[(int)data->player->y][(int)(tmp_x)] == '1')
		return ;
	if ((tmp_y > data->map_height || tmp_y < 0)
		|| data->map[(int)tmp_y][(int)(tmp_x)] == '1')
		return ;
	data->player->x = tmp_x;
	data->player->y = tmp_y;
}

void	move_right(t_data *data)
{
	double	tmp_x;
	double	tmp_y;

	tmp_x = data->player->x - data->direction->y * data->move_speed;
	tmp_y = data->player->y + data->direction->x * data->move_speed;
	if ((tmp_x > data->map_width || tmp_x < 0)
		|| data->map[(int)data->player->y][(int)(tmp_x)] == '1')
		return ;
	if ((tmp_y > data->map_height || tmp_y < 0)
		|| data->map[(int)tmp_y][(int)(tmp_x)] == '1')
		return ;
	data->player->x = tmp_x;
	data->player->y = tmp_y;
}
