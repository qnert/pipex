/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 10:54:36 by skunert           #+#    #+#             */
/*   Updated: 2023/06/05 16:26:30 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	fork_child_proc(char **argv, char **envp, int *fd)
{
	pid_t	pid;

	if (pipe(fd) == -1)
		return (perror("Error"), -1);
	pid = fork();
	if (pid == -1)
		return (perror("Error"), -1);
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		exec_cmd(argv[0], envp);
		close (fd[1]);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
	}
	return (pid);
}

int	fork_end(char **argv, char **envp, int *fd, int fd_out)
{
	dup2(fd[0], STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	close (fd[1]);
	exec_cmd(argv[0], envp);
	close (fd[0]);
	return (0);
}
