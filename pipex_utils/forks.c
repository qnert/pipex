/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 10:54:36 by skunert           #+#    #+#             */
/*   Updated: 2023/05/26 15:40:03 by skunert          ###   ########.fr       */
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
		wait(&pid);
	}
	return (0);
}

int	fork_end(char **argv, char **envp, int *fd, int fd_out)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		return (ft_printf("Error occured: %s\n", strerror(errno)), -1);
	if (pid == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		dup2(fd_out, STDOUT_FILENO);
		close (fd[0]);
		close (fd[1]);
		exec_cmd(argv[0], envp);
	}
	return (pid);
}
