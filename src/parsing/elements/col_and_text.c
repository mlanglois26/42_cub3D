/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_and_text.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrischma <hrischma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 14:16:06 by malanglo          #+#    #+#             */
/*   Updated: 2024/10/16 17:16:33 by hrischma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub.h"

int	rgb_has_three_parts(const char *rgb_str)
{
	int	count;
	int	i;
	int	prev_char_was_comma;

	count = 0;
	i = 0;
	prev_char_was_comma = 0;
	while (rgb_str[i] != '\0')
	{
		if (rgb_str[i] == ',')
		{
			if (prev_char_was_comma)
				return (1);
			count++;
			prev_char_was_comma = 1;
		}
		else
			prev_char_was_comma = 0;
		i++;
	}
	if (count == 2)
		return (0);
	else
		return (1);
}

static int	is_acceptable_str(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] != '\n') && ((str[i] > '9') || (str[i] < '0')))
			return (1);
		i++;
	}
	return (0);
}

int	rgb_nb_is_valid(char *elem_second_part)
{
	char	**rgb;
	int		int_value;
	int		i;

	rgb = ft_split(elem_second_part, ',');
	i = 0;
	while (rgb[i] != NULL)
	{
		if (is_acceptable_str(rgb[i]) == 1)
		{
			free_double_pointer(rgb);
			return (1);
		}
		int_value = ft_atoi(rgb[i]);
		if (int_value < 0 || int_value > 255)
		{
			free_double_pointer(rgb);
			return (1);
		}
		i++;
	}
	free_double_pointer(rgb);
	return (0);
}
