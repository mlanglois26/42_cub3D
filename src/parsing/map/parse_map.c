/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrischma <hrischma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:57:16 by malanglo          #+#    #+#             */
/*   Updated: 2024/10/16 15:10:09 by hrischma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub.h"

static void	check_char_error_and_empty_line(char **new_map, char **all_lines,
		t_data *data)
{
	if (there_is_empty_line_in_array(new_map) == 1)
	{
		printf("Error, there is an empty line in the map.\n");
		free_wrapper(new_map, all_lines, data);
	}
	if (there_is_unwanted_character_in_array(new_map) == 1)
	{
		printf("Error, there is a character that is not valid in the map.\n");
		free_wrapper(new_map, all_lines, data);
	}
	if (n_s_e_w_are_unique_in_array(new_map) == 1)
	{
		printf("Error, the map must contain one player - no less, no more.\n");
		free_wrapper(new_map, all_lines, data);
	}
}

int	error_message(int i, int j)
{
	printf("There is a hole near map[%d][%d]\n", i, j);
	return (1);
}

static int	wall_verif(char **map)
{
	int	j;

	int (i) = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
			{
				if (i - 1 < 0 || j - 1 < 0)
					return (error_message(i, j));
				else if (map[i][j + 1] == ' ' || map[i][j - 1] == ' ')
					return (error_message(i, j));
				else if (map[i + 1] == NULL || map[i + 1][j] == ' ')
					return (error_message(i, j));
				else if (map[i - 1][j] == ' ')
					return (error_message(i, j));
			}
			j++;
		}
		i++;
	}
	return (0);
}

char	**parse_map(char *file, t_data *data)
{
	char	**all_lines;
	char	**map;
	char	**new_map;

	all_lines = stock_file_content(file);
	map = stock_map(all_lines);
	new_map = fill_map_with_spaces(map, all_lines);
	free_double_pointer(map);
	check_char_error_and_empty_line(new_map, all_lines, data);
	if (wall_verif(new_map) == 1)
	{
		if (data->designs)
			free_designs(data);
		free(data->designs);
		free_double_pointer(all_lines);
		free(data);
		exit_and_free_double_pointer(new_map);
	}
	free_double_pointer(all_lines);
	return (new_map);
}

int	get_final_map_height(char **map)
{
	int	j;

	j = 0;
	while (map[j] != NULL)
		j++;
	return (j);
}
