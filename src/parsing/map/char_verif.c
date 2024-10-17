/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_verif.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrischma <hrischma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:17:07 by malanglo          #+#    #+#             */
/*   Updated: 2024/10/16 13:51:46 by hrischma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub.h"

static int	is_unwanted_chararcter(char c)
{
	if (c != '0' && c != '1' && c != 'N' && c != 'S' && c != 'E' && c != 'W'
		&& c != ' ' && c != '\n' && c != '\0')
		return (1);
	return (0);
}

int	there_is_unwanted_character_in_array(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (is_unwanted_chararcter(map[i][j]) == 1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	nb_of_appearance_of_char_in_array(char **map, char c)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	n_s_e_w_are_unique_in_array(char **map)
{
	int	total_count;
	int	nb_of_n;
	int	nb_of_s;
	int	nb_of_e;
	int	nb_of_w;

	total_count = 0;
	nb_of_n = nb_of_appearance_of_char_in_array(map, 'N');
	nb_of_s = nb_of_appearance_of_char_in_array(map, 'S');
	nb_of_e = nb_of_appearance_of_char_in_array(map, 'E');
	nb_of_w = nb_of_appearance_of_char_in_array(map, 'W');
	total_count = nb_of_n + nb_of_s + nb_of_e + nb_of_w;
	if (total_count == 1)
		return (0);
	return (1);
}

int	there_is_empty_line_in_array(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		if (this_line_has_content(map[i]) == 0 && this_line_has_content(map[i
					+ 1]) == 1)
			return (1);
		i++;
	}
	return (0);
}
