/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 22:32:32 by skunert           #+#    #+#             */
/*   Updated: 2023/05/22 11:03:15 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	free_arr(char **arr)
{
	unsigned int	i;

	i = 0;
	while (arr[i] != NULL)
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

	fd = open(filepath, O_RDWR | O_TRUNC, 0777);
	if (fd < 0)
	{
		fd_err = open(filepath, O_RDWR | O_CREAT, 0777);
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
	char	**command;

	command = ft_split(argv[0], ' ');
	if (command == NULL)
		return (NULL);
	return (command);
}

int	execute_command(char **command, int fd)
{
	char	*s;

	s = ft_strjoin("/usr/bin/", command[0]);
	if (execve(s, command, NULL) == -1)
	{
		free(s);
		s = ft_strjoin("/bin/", command[0]);
		if (execve(s, command, NULL) == -1)
		{
			ft_putstr_fd("Command cannot be executed\n", fd);
			return (free(s), free_arr(command), 0);
		}
	}
	free_arr(command);
	free(s);
	return (1);
}
