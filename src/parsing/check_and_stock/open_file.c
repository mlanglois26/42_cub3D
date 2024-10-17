/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrischma <hrischma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 14:06:56 by malanglo          #+#    #+#             */
/*   Updated: 2024/10/16 17:50:33 by hrischma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub.h"

int	file_height(char *file)
{
	int		fd;
	char	*line;
	int		height;

	height = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		perror("open");
	line = get_next_line(fd);
	while (line != NULL)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

char	**stock_file_content(char *file)
{
	int		fd;
	char	*line;
	char	**stocked_line;
	int		height;
	int		i;

	height = file_height(file);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	stocked_line = malloc(sizeof(char *) * (height + 1));
	if (!stocked_line)
		return (NULL);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		stocked_line[i] = ft_strdup(line);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	stocked_line[i] = NULL;
	close(fd);
	return (stocked_line);
}

int	this_line_has_content(char *line)
{
	int	i;
	int	flag;

	if (line == NULL)
		return (0);
	i = 0;
	flag = 0;
	while (line[i] != '\0')
	{
		if (line[i] != ' ' && line[i] != '\n')
			flag = 1;
		i++;
	}
	if (flag == 1)
		return (1);
	return (0);
}

static int	file_has_at_least_nine_lines_with_content(char **stocked_line)
{
	int	line_with_content_count;
	int	i;

	line_with_content_count = 0;
	i = 0;
	while (stocked_line[i] != NULL)
	{
		if (this_line_has_content(stocked_line[i]) == 1)
			line_with_content_count++;
		i++;
	}
	if (line_with_content_count < 9)
		return (1);
	return (0);
}

void	file_worth_analysing(char *file, t_data *data)
{
	char	**stocked_line;

	stocked_line = stock_file_content(file);
	if (file_has_at_least_nine_lines_with_content(stocked_line) == 1)
	{
		printf("Error, the content of the file is either empty or not\
        big enough.\n");
		if (data->designs)
		{
			free_designs(data);
			free(data->designs);
		}
		free(data);
		exit_and_free_double_pointer(stocked_line);
	}
	free_double_pointer(stocked_line);
}
