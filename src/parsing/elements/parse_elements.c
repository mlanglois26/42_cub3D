/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrischma <hrischma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 14:10:01 by malanglo          #+#    #+#             */
/*   Updated: 2024/10/16 16:05:44 by hrischma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub.h"

static char	**get_6_first_full_lines(char **stocked_line)
{
	char	**elems;
	int		line_count;
	int		i;

	line_count = 0;
	elems = malloc(sizeof(char *) * (6 + 1));
	i = 0;
	while (stocked_line[i] != NULL)
	{
		if (this_line_has_content(stocked_line[i]) == 1 && line_count < 6)
		{
			elems[line_count] = ft_strdup(stocked_line[i]);
			line_count++;
		}
		i++;
	}
	elems[line_count] = NULL;
	return (elems);
}

static char	***split_elements(char **elems)
{
	char	***splitted_elems_array;
	int		i;

	splitted_elems_array = malloc(sizeof(char **) * (6 + 1));
	if (!splitted_elems_array)
		return (NULL);
	i = 0;
	while (elems[i] != NULL)
	{
		splitted_elems_array[i] = ft_split(elems[i], ' ');
		i++;
	}
	splitted_elems_array[i] = NULL;
	return (splitted_elems_array);
}

void	clean_map_data_and_elems(char ***splitted_elems, t_data *data,
			char **elems, char **stocked_line)
{
	if (data->designs)
	{
		free_designs(data);
		free(data->designs);
	}
	free_double_pointer(data->map);
	free_double_pointer(stocked_line);
	free_double_pointer(elems);
	free(data);
	exit_and_free_triple_pointer(splitted_elems);
}

void	check_elements_validity(char ***splitted_elems, t_data *data,
			char **elems, char **stocked_line)
{
	if (elems_are_all_splitted_into_two_parts(splitted_elems) == 1)
		clean_map_data_and_elems(splitted_elems, data, elems, stocked_line);
	if (elems_first_part_content_is_valid(splitted_elems) == 1)
		clean_map_data_and_elems(splitted_elems, data, elems, stocked_line);
	if (elems_first_part_are_unique(splitted_elems) == 1)
		clean_map_data_and_elems(splitted_elems, data, elems, stocked_line);
	if (elems_second_part_content_is_valid(splitted_elems) == 1)
		clean_map_data_and_elems(splitted_elems, data, elems, stocked_line);
	if (elems_second_part_are_unique(splitted_elems) == 1)
		clean_map_data_and_elems(splitted_elems, data, elems, stocked_line);
}

char	***parse_elements(char *file, t_data *data)
{
	char	**stocked_line;
	char	**elements;
	char	***splitted_elements;

	stocked_line = stock_file_content(file);
	elements = get_6_first_full_lines(stocked_line);
	splitted_elements = split_elements(elements);
	check_elements_validity(splitted_elements, data, elements, stocked_line);
	extract_floor_ceiling_and_textures(stocked_line, data);
	free_double_pointer(stocked_line);
	free_double_pointer(elements);
	return (splitted_elements);
}
