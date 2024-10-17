/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrischma <hrischma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 09:53:39 by malanglo          #+#    #+#             */
/*   Updated: 2024/10/16 13:54:01 by hrischma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	mlx_run(t_data *data)
{
	mlx_hook(data->mlx->window, 17, 0, quit, data);
	mlx_hook(data->mlx->window, KeyPress, KeyPressMask, on_key_press, data);
	mlx_loop_hook(data->mlx->mlx_connection, raycasting, data);
	mlx_loop(data->mlx->mlx_connection);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	*data;

	check_args_and_envp(argc, argv, envp);
	data = init_data();
	parse_file_content(argv[1], data);
	set_data_for_raycasting(data);
	raycasting(data);
	mlx_run(data);
	return (0);
}
