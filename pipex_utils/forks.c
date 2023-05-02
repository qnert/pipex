/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:02:22 by skunert           #+#    #+#             */
/*   Updated: 2023/05/02 17:11:37 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	fork_1(char **argv, int *fd, int fd_in)
{
	int pid;

	pid = fork();
	if (pid < 0)
		return (0);
	dup2(fd_in, STDIN_FILENO);
	if (pid == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close (fd[0]);
		close (fd[1]);
		execute_command(get_command(argv + 2));
	}
	return (pid);
}

int	fork_2(char **argv, int *fd, int fd_out)
{
	int pid;

	pid = fork();
	if (pid < 0)
		return (0);
	if (pid == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		dup2(fd_out, STDOUT_FILENO);
		close (fd[0]);
		close (fd[1]);
		execute_command(get_command(argv + 3));
	}
	return (pid);
}