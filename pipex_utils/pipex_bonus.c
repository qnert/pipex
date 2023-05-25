/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:04:30 by skunert           #+#    #+#             */
/*   Updated: 2023/05/25 11:39:30 by skunert          ###   ########.fr       */
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
		pid = 0;
		fd_in = ft_infile_check(argv[1]);
		fd_out = ft_outfile_check(argv[argc - 1]);
		if (fd_in != -1)
			dup2(fd_in, STDIN_FILENO);
		i = 2;
		while (i < argc - 2 && fd_in != -1)
		{
			pid = fork_child_proc(argv, envp, i, fd);
			if (pid == -1)
				return (-1);
			i++;
		}
		if (pipe(fd) == -1)
			return (perror("Error"), -1);
		fork_2(argv + (argc - 5), envp, fd, fd_out);
	}
	return (0);
}
