/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_elements2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrischma <hrischma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:31:12 by malanglo          #+#    #+#             */
/*   Updated: 2024/10/16 13:51:44 by hrischma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub.h"

int	color_check(char ***elems, int i)
{
	if (rgb_has_three_parts(elems[i][1]) == 1)
	{
		printf("Error, the RGB format of the element[%d] is not valid.\n", i);
		return (1);
	}
	if (rgb_nb_is_valid(elems[i][1]) == 1)
	{
		printf("Error, RGB value of element[% d] must be an int between\
         0 and 255.\n ", i);
		return (1);
	}
	return (0);
}

int	xpm_check(char ***elems, int i)
{
	int	j;

	j = 0;
	while (elems[i][1][j] != '\0')
		j++;
	while (elems[i][1][j] == '\0' || elems[i][1][j] == '\n'
		|| elems[i][1][j] == ' ')
		j--;
	if (elems[i][1][j] != 'm' || elems[i][1][j - 1] != 'p' || elems[i][1][j
		- 2] != 'x' || elems[i][1][j - 3] != '.')
	{
		printf("Please, provide a file.xpm for the texture\n");
		return (1);
	}
	return (0);
}
