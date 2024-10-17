/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrischma <hrischma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 14:04:55 by malanglo          #+#    #+#             */
/*   Updated: 2024/10/16 13:50:00 by hrischma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub.h"

static int	correct_nb_of_argc(int argc)
{
	if (argc != 2)
	{
		printf("Wrong numbr of Arguments.\n");
		return (0);
	}
	return (1);
}

static int	check_extension(char *argv1)
{
	int	i;

	i = 0;
	while (argv1[i] != '\0')
		i++;
	if (argv1[i - 1] != 'b' || argv1[i - 2] != 'u' || argv1[i - 3] != 'c'
		|| argv1[i - 4] != '.')
	{
		printf("Error, wrong extension: file.cub expected.\n");
		return (0);
	}
	return (1);
}

static int	make_sure_it_is_not_folder(char *argv1)
{
	int	fd;

	fd = open(argv1, O_DIRECTORY);
	if (fd < 0)
		return (1);
	else
	{
		close(fd);
		printf("Error, please provide a file.cub, not a folder.\n");
		return (0);
	}
}

static int	check_file_exists(char *argv1)
{
	int	fd;

	fd = open(argv1, O_RDONLY);
	if (fd < 0)
	{
		printf("Error, the file does not exist.\n");
		return (0);
	}
	else
	{
		close(fd);
		return (1);
	}
}

void	check_args_and_envp(int argc, char **argv, char **envp)
{
	if (check_if_env_i(envp) == 0)
		exit(0);
	if (correct_nb_of_argc(argc) == 0)
		exit(0);
	if (check_extension(argv[1]) == 0)
		exit(0);
	if (make_sure_it_is_not_folder(argv[1]) == 0)
		exit(0);
	if (check_file_exists(argv[1]) == 0)
		exit(0);
}
