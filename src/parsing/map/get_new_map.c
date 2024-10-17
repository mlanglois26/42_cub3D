/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_new_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrischma <hrischma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:45:28 by malanglo          #+#    #+#             */
/*   Updated: 2024/10/16 13:51:51 by hrischma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub.h"

int	get_width_of_longest_h_line(char **map)
{
	int	tmp;
	int	res;
	int	i;
	int	j;

	tmp = 0;
	res = 0;
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
			j++;
		tmp = j;
		if (tmp > res)
			res = tmp;
		i++;
	}
	return (res);
}

static void	new_line_content(char **map, char **new_map, int i,
		int longest_line_len)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (map[i][j] != '\0')
	{
		if (map[i][j] == '\n')
			j++;
		else
		{
			new_map[i][k] = map[i][j];
			j++;
			k++;
		}
	}
	while (k < longest_line_len)
	{
		new_map[i][k] = ' ';
		k++;
	}
	new_map[i][k] = '\0';
}

char	**fill_map_with_spaces(char **map, char **all_lines)
{
	char	**new_map;
	int		size;
	int		i;
	int		longest_line_len;

	size = map_height(all_lines);
	new_map = malloc(sizeof(char *) * (size + 1));
	if (!new_map)
		return (NULL);
	longest_line_len = (get_width_of_longest_h_line(map) - 1);
	i = 0;
	while (map[i] != NULL)
	{
		new_map[i] = malloc(sizeof(char) * (longest_line_len + 1));
		if (!new_map[i])
			return (NULL);
		new_line_content(map, new_map, i, longest_line_len);
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}
