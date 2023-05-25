/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 19:26:31 by skunert           #+#    #+#             */
/*   Updated: 2023/05/25 09:02:46 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int				fd_in;
	int				fd_out;
	static int		pid1;
	static int		pid2;
	int				fd[2];

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			return (ft_printf("Error occured: %s\n", strerror(errno), 0));
		fd_in = ft_infile_check(argv[1]);
		fd_out = ft_outfile_check(argv[4]);
		if (fd_in != -1)
			pid1 = fork_1(argv, envp, fd, fd_in);
		else
			ft_printf("Error occured: %s\n", strerror(errno));
		if (pid1 != 0 || fd_in == -1)
			pid2 = fork_2(argv, envp, fd, fd_out);
		close(fd[0]);
		close(fd[1]);
		if (fd_in != -1)
			waitpid(pid1, NULL, 0);
		waitpid(pid2, NULL, 0);
	}
	return (0);
}

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
