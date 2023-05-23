/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:02:22 by skunert           #+#    #+#             */
/*   Updated: 2023/05/23 13:32:22 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	fork_1(char **argv, char **envp, int *fd, int fd_in)
{
	int	pid;

	pid = fork();
	if (pid < 0)
		return (ft_printf("Error occured: %s\n", strerror(errno)), -1);
	dup2(fd_in, STDIN_FILENO);
	if (pid == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close (fd[0]);
		close (fd[1]);
		exec_cmd(argv[2], envp);
	}
	return (pid);
}

int	fork_2(char **argv, char **envp, int *fd, int fd_out)
{
	int	pid;

	pid = fork();
	if (pid < 0)
		return (ft_printf("Error occured: %s\n", strerror(errno)), -1);
	if (pid == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		dup2(fd_out, STDOUT_FILENO);
		close (fd[0]);
		close (fd[1]);
		exec_cmd(argv[3], envp);
	}
	return (pid);
}
