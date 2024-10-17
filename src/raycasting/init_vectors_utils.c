/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vectors_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrischma <hrischma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:07:47 by malanglo          #+#    #+#             */
/*   Updated: 2024/10/16 13:53:03 by hrischma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

int	is_player_char(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

double	degrees_to_radians(double degrees)
{
	return ((PI / 180.0) * degrees);
}

double	ft_abs(double n)
{
	if (n < 0.0)
		return (-n);
	else
		return (n);
}
