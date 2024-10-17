/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrischma <hrischma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 14:12:59 by malanglo          #+#    #+#             */
/*   Updated: 2024/10/16 16:29:48 by hrischma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub.h"

int	elems_are_all_splitted_into_two_parts(char ***elem)
{
	int	i;
	int	j;

	i = 0;
	while (elem[i] != NULL)
	{
		j = 0;
		while (elem[i][j] != NULL)
		{
			if (ft_strcmp(elem[i][j], "\n") == 0)
				break ;
			j++;
		}
		if (j != 2)
		{
			printf("Error, element[%d] is invalid, it does not have 2 parts\n",
				i);
			return (1);
		}
		i++;
	}
	return (0);
}

int	elems_first_part_content_is_valid(char ***elem)
{
	int	i;

	i = 0;
	while (elem[i] != NULL)
	{
		while (elem[i][0] != NULL)
		{
			if (ft_strcmp(elem[i][0], "NO") == 0
				|| ft_strcmp(elem[i][0], "SO") == 0
				|| ft_strcmp(elem[i][0], "WE") == 0
				|| ft_strcmp(elem[i][0], "EA") == 0
				|| ft_strcmp(elem[i][0], "F") == 0
				|| ft_strcmp(elem[i][0], "C") == 0)
				break ;
			else
			{
				printf("Error, the ID of element[%d] is not valid.\n", i);
				return (1);
			}
		}
		i++;
	}
	return (0);
}

int	elems_first_part_are_unique(char ***elem)
{
	int	i;
	int	count;
	int	j;

	i = 0;
	count = 0;
	while (elem[i] != NULL)
		i++;
	count = i;
	i = 0;
	while (elem[i] != NULL)
	{
		j = i + 1;
		while (j < count)
		{
			if (ft_strcmp(elem[i][0], elem[j][0]) == 0)
			{
				printf("Error, elem[%d] & elem[%d] have the same ID.\n", i, j);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	elems_second_part_content_is_valid(char ***elems)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	while (elems[i] != NULL)
	{
		if (ft_strcmp(elems[i][0], "C") == 0
			|| ft_strcmp(elems[i][0], "F") == 0)
		{
			flag = color_check(elems, i);
			if (flag == 1)
				return (1);
		}
		else
		{
			flag = xpm_check(elems, i);
			if (flag == 1)
				return (1);
		}
		i++;
	}
	return (0);
}

int	elems_second_part_are_unique(char ***elems)
{
	int	j;

	int (i) = 0;
	int (count) = 0;
	while (elems[i] != NULL)
		i++;
	count = i;
	i = 0;
	while (elems[i] != NULL)
	{
		j = i + 1;
		while (j < count)
		{
			if (ft_strcmp(elems[i][1], elems[j][1]) == 0)
			{
				printf("Error, elem[%d] & [%d] have the same text/col.\n", i,
					j);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
