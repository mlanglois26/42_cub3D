/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrischma <hrischma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:06:26 by malanglo          #+#    #+#             */
/*   Updated: 2024/10/16 13:51:24 by hrischma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub.h"

int	check_if_env_i(char **envp)
{
	char	*cmd;
	int		i;

	cmd = "PATH=";
	i = 0;
	while (envp[i] != NULL)
	{
		if (strncmp(envp[i], cmd, 5) == 0)
			return (1);
		i++;
	}
	printf("You must set the PATH variable to be able to run this program.\n");
	return (0);
}
