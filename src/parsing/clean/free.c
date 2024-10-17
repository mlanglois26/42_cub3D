/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrischma <hrischma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:21:13 by hrischma          #+#    #+#             */
/*   Updated: 2024/10/16 15:10:16 by hrischma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub.h"

void	free_wrapper(char **new_map, char **all_lines, t_data *data)
{
	if (data->designs)
	{
		free_designs(data);
		free(data->designs);
	}
	free_double_pointer(all_lines);
	free(data);
	exit_and_free_double_pointer(new_map);
}

void	free_designs(t_data *data)
{
	if (data->designs->path_wall_no)
		free(data->designs->path_wall_no);
	if (data->designs->t_wall_north.img_ptr)
		mlx_destroy_image(data->mlx->mlx_connection,
			data->designs->t_wall_north.img_ptr);
	if (data->designs->path_wall_we)
		free(data->designs->path_wall_we);
	if (data->designs->t_wall_west.img_ptr)
		mlx_destroy_image(data->mlx->mlx_connection,
			data->designs->t_wall_west.img_ptr);
	if (data->designs->path_wall_ea)
		free(data->designs->path_wall_ea);
	if (data->designs->t_wall_east.img_ptr)
		mlx_destroy_image(data->mlx->mlx_connection,
			data->designs->t_wall_east.img_ptr);
	if (data->designs->path_wall_so)
		free(data->designs->path_wall_so);
	if (data->designs->t_wall_south.img_ptr)
		mlx_destroy_image(data->mlx->mlx_connection,
			data->designs->t_wall_south.img_ptr);
}

void	free_double_pointer(char **elems)
{
	int	i;

	i = 0;
	while (elems[i] != NULL)
	{
		free(elems[i]);
		i++;
	}
	free(elems);
}

void	free_triple_pointer(char ***elems)
{
	int	i;
	int	j;

	i = 0;
	while (elems[i] != NULL)
	{
		j = 0;
		while (elems[i][j] != NULL)
		{
			free(elems[i][j]);
			j++;
		}
		free(elems[i]);
		i++;
	}
	free(elems);
}
