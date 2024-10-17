/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrischma <hrischma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:20:49 by malanglo          #+#    #+#             */
/*   Updated: 2024/10/16 13:51:48 by hrischma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub.h"

static int	map_starts_on_line(char **all_lines)
{
	int (line_nb_of_map_starts) = 0;
	int (empty_line) = 0;
	int (elem_count) = 0;
	int (flag) = 0;
	int (i) = 0;
	while (all_lines[i] != NULL)
	{
		if (this_line_has_content(all_lines[i]) == 1 && elem_count == 6)
		{
			line_nb_of_map_starts = empty_line + elem_count;
			flag = 1;
		}
		else if (this_line_has_content(all_lines[i]) == 1 && flag == 0)
		{
			line_nb_of_map_starts++;
			elem_count++;
		}
		else if (flag == 0)
		{
			line_nb_of_map_starts++;
			empty_line++;
		}
		i++;
	}
	return (line_nb_of_map_starts);
}

int	map_height(char **all_lines)
{
	int	line_nb_of_map_start;
	int	map_height;
	int	i;

	line_nb_of_map_start = map_starts_on_line(all_lines);
	i = line_nb_of_map_start;
	while (all_lines[i] != NULL)
		i++;
	while (this_line_has_content(all_lines[i]) == 0)
		i--;
	map_height = i - (line_nb_of_map_start - 1);
	return (map_height);
}

char	**stock_map(char **all_lines)
{
	char	**map;
	int		m_height;
	int		line_nb_of_map_start;
	int		i;

	m_height = map_height(all_lines);
	map = malloc(sizeof(char *) * (m_height + 1));
	if (!map)
		return (NULL);
	line_nb_of_map_start = map_starts_on_line(all_lines);
	i = 0;
	while (i < m_height)
	{
		map[i] = ft_strdup(all_lines[line_nb_of_map_start]);
		i++;
		line_nb_of_map_start++;
	}
	map[i] = NULL;
	return (map);
}
