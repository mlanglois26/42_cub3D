/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrischma <hrischma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:28:55 by malanglo          #+#    #+#             */
/*   Updated: 2024/10/16 16:21:38 by hrischma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub.h"

char	*trim_whitespace(char *str)
{
	while (*str == ' ' || *str == '\t')
		str++;
	return (str);
}

char	*trim_trailing_whitespace(char *str)
{
	int	len;

	len = ft_strlen(str);
	len--;
	while (len >= 0 && (str[len] == ' ' || str[len] == '\t'
			|| str[len] == '\n'))
		len--;
	str[len + 1] = '\0';
	return (str);
}

int	extract_texture_path(char *line, char **destination,
		const char *identifier)
{
	char	*path;

	if (strncmp(line, identifier, 2) == 0 && (line[2] == ' '
			|| line[2] == '\t'))
	{
		path = trim_trailing_whitespace(trim_whitespace(line + 2));
		*destination = ft_strdup(path);
		if (!(*destination))
		{
			perror("Erreur lors de la duplication du chemin");
			exit(EXIT_FAILURE);
		}
		return (1);
	}
	return (0);
}

void	extract_floor_ceiling_and_textures(char **stocked_line, t_data *data)
{
	int		i;
	char	*line;

	i = 0;
	while (stocked_line[i])
	{
		line = trim_whitespace(stocked_line[i]);
		if (!handle_texture_path(line, data)
			&& (line[0] == 'F' || line[0] == 'C'))
		{
			handle_rgb_value(line, data, line[0]);
		}
		i++;
	}
}

int	handle_texture_path(char *line, t_data *data)
{
	if (extract_texture_path(line, &(data->designs->path_wall_no), "WE")
		|| extract_texture_path(line, &(data->designs->path_wall_so), "EA")
		|| extract_texture_path(line, &(data->designs->path_wall_we), "NO")
		|| extract_texture_path(line, &(data->designs->path_wall_ea), "SO"))
	{
		return (1);
	}
	return (0);
}
