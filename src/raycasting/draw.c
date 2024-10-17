/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrischma <hrischma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:41:40 by malanglo          #+#    #+#             */
/*   Updated: 2024/10/16 13:56:37 by hrischma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

void	calculate_draw_positions(t_data *data, int x)
{
	data->ray[x].start_draw = -data->ray[x].line_height / 2 + HEIGHT / 2;
	if (data->ray[x].start_draw < 0)
		data->ray[x].start_draw = 0;
	data->ray[x].end_draw = data->ray[x].line_height / 2 + HEIGHT / 2;
	if (data->ray[x].end_draw > HEIGHT)
		data->ray[x].end_draw = HEIGHT;
}

t_image	*get_wall_texture(t_data *data, int x)
{
	if (data->ray[x].side == 0)
	{
		if (data->ray[x].dir_x > 0)
			return (&data->designs->t_wall_south);
		else
			return (&data->designs->t_wall_north);
	}
	else
	{
		if (data->ray[x].dir_y > 0)
			return (&data->designs->t_wall_east);
		else
			return (&data->designs->t_wall_west);
	}
}

int	calculate_tex_x(t_data *data, int x, t_image *texture)
{
	if (data->ray[x].side == 0)
		return ((int)((data->player->y + data->ray[x].perp_wall_dist
				* data->ray[x].dir_y) * texture->dimensions.x)
			% texture->dimensions.x);
	else
		return ((int)((data->player->x + data->ray[x].perp_wall_dist
				* data->ray[x].dir_x) * texture->dimensions.x)
			% texture->dimensions.x);
}

void	draw_ray(t_data *data, int x, t_image *texture, int tex_x)
{
	int				d;
	unsigned int	tex_y;

	int (color) = 0xFFFFFF;
	while (data->ray[x].start_draw < data->ray[x].end_draw
		&& data->ray[x].start_draw < HEIGHT && data->ray[x].start_draw >= 0
		&& data->ray[x].end_draw <= HEIGHT)
	{
		d = (int)(data->ray[x].start_draw * 256 - HEIGHT * 128
				+ data->ray[x].line_height * 128);
		tex_y = ((unsigned int)(d * texture->dimensions.y)
				/ data->ray[x].line_height) / 256;
		if (tex_y < 0)
		{
			((int *)data->mlx->image.img_addr)[(int)data->ray[x].start_draw
				* WIDTH + x] = color;
			data->ray[x].start_draw++;
			continue ;
		}
		color = *((int *)(texture->img_addr + (tex_y * texture->line_len + tex_x
						* (texture->bpp / 8))));
		((int *)data->mlx->image.img_addr)[(int)data->ray[x].start_draw * WIDTH
			+ x] = color;
		data->ray[x].start_draw++;
	}
}

void	draw(t_data *data, int x)
{
	t_image	*texture;
	int		tex_x;

	calculate_draw_positions(data, x);
	texture = get_wall_texture(data, x);
	tex_x = calculate_tex_x(data, x, texture);
	draw_ray(data, x, texture, tex_x);
}
