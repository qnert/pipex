/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:04:30 by skunert           #+#    #+#             */
/*   Updated: 2023/05/25 10:01:35 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	fd_in;
	int	fd_out;
	int	fd[2];
	int	pid;
	int	i;

	if (argc >= 6)
	{
		fd_in = ft_infile_check(argv[1]);
		fd_out = ft_outfile_check(argv[argc - 1]);
		dup2(fd_in, STDIN_FILENO);
		i = 2;
		while (i < argc - 2)
		{
			pid = fork_child_proc(argv, envp, i, fd);
			if (pid == -1)
				return (-1);
			i++;
		}
		dup2(fd_out, STDOUT_FILENO);
		exec_cmd(argv[i], envp);
	}
	return (0);
}

int	fork_child_proc(char **argv, char **envp, int i, int *fd)
{
	int	pid;

	if (pipe(fd) == -1)
		return (perror("Error"), -1);
	pid = fork();
	if (pid == -1)
		return (perror("Error"), -1);
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		exec_cmd(argv[i], envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		wait(&pid);
	}
	return (0);
}
