/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rgb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrischma <hrischma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:28:49 by hrischma          #+#    #+#             */
/*   Updated: 2024/10/16 16:22:46 by hrischma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub.h"

int	parse_rgb(char *rgb_str, t_rgb *rgb)
{
	char	**values;
	int		r;
	int		g;
	int		b;

	values = ft_split(rgb_str, ',');
	if (!values || !values[0] || !values[1] || !values[2] || values[3] != NULL)
	{
		free_double_pointer(values);
		return (0);
	}
	r = ft_atoi(values[0]);
	g = ft_atoi(values[1]);
	b = ft_atoi(values[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
	{
		free_double_pointer(values);
		return (0);
	}
	rgb->r = r;
	rgb->g = g;
	rgb->b = b;
	free_double_pointer(values);
	return (1);
}

int	handle_rgb_value(char *line, t_data *data, char identifier)
{
	char	*values;

	values = trim_trailing_whitespace(trim_whitespace(line + 1));
	if (identifier == 'F')
	{
		if (!parse_rgb(values, &(data->designs->floor)))
		{
			perror("Erreur : Valeurs RGB incorrectes pour le sol");
			exit(EXIT_FAILURE);
		}
	}
	else if (identifier == 'C')
	{
		if (!parse_rgb(values, &(data->designs->ceiling)))
		{
			perror("Erreur : Valeurs RGB incorrectes pour le plafond");
			exit(EXIT_FAILURE);
		}
	}
	return (1);
}
