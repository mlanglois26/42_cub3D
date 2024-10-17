/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrischma <hrischma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:22:34 by hrischma          #+#    #+#             */
/*   Updated: 2024/10/16 16:19:35 by hrischma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub.h"

void	exit_and_free_double_pointer(char **ptr)
{
	free_double_pointer(ptr);
	exit(0);
}

void	exit_and_free_triple_pointer(char ***ptr)
{
	free_triple_pointer(ptr);
	exit(0);
}

void	cleanup_data(t_data *data)
{
	if (data->designs)
	{
		free_designs(data);
		free(data->designs);
		data->designs = NULL;
	}
	if (data->mlx)
	{
		mlx_destroy_window(data->mlx->mlx_connection, data->mlx->window);
		mlx_destroy_display(data->mlx->mlx_connection);
		if (data->mlx->mlx_connection)
		{
			free(data->mlx->mlx_connection);
		}
		free(data->mlx);
		data->mlx = NULL;
	}
	free(data->player);
	data->player = NULL;
	free(data->direction);
	data->direction = NULL;
	free(data->camera);
	data->camera = NULL;
	free(data->ray);
	data->ray = NULL;
}

int	quit(t_data *data)
{
	if (!data)
		return (-1);
	if (data->mlx && data->mlx->image.img_ptr)
	{
		mlx_destroy_image(data->mlx->mlx_connection, data->mlx->image.img_ptr);
		data->mlx->image.img_ptr = NULL;
	}
	cleanup_data(data);
	if (data->map)
	{
		free_double_pointer(data->map);
		data->map = NULL;
	}
	if (data->elements)
	{
		free_triple_pointer(data->elements);
		data->elements = NULL;
	}
	free(data);
	data = NULL;
	exit(0);
}

void	free_mlx_ptr_and_exit(t_mlx *mlx)
{
	free(mlx);
	exit(0);
}
