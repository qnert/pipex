/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 22:32:32 by skunert           #+#    #+#             */
/*   Updated: 2023/05/02 20:19:50 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	free_arr(char **arr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (arr[i] != NULL && i < size)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	ft_outfile_check(char *filepath)
{
	int	fd;
	int	fd_err;

	fd = open(filepath, O_RDWR, 0777);
	if (fd < 0)
	{
		fd_err = open(filepath, O_RDWR | O_CREAT | O_TRUNC, 0777);
		return (fd_err);
	}
	return (fd);
}

int	ft_infile_check(char *filepath)
{
	int	fd;

	fd = open(filepath, O_RDWR);
	if (fd < 0)
		return (-1);
	return (fd);
}

char	**get_command(char **argv)
{
	int		i;
	char	**command;

	i = 0;
	command = ft_split(argv[0], ' ');
	if (command == NULL)
		return (NULL);
	return (command);
}

int	execute_command(char **command)
{
	char	*s;
	int		i;

	s = ft_strjoin("/usr/bin/", command[0]);
	i = 0;
	if (execve(s, command, NULL) == -1)
	{
		free(s);
		s = ft_strjoin("/bin/", command[0]);
		if (execve(s, command, NULL) == -1)
			return (ft_printf("Command cannot be executed\n"), 0);
	}
	while (command[i] != NULL)
		i++;
	free_arr(command, i);
	return (1);
}
