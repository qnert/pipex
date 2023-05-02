/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 19:26:31 by skunert           #+#    #+#             */
/*   Updated: 2023/05/02 17:09:44 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	int		fd_in;
	int		fd_out;
	int		pid1;
	int		pid2;
	int		fd[2];

	if (pipe(fd) == -1)
		return (0);
	if (argc == 5)
	{
		fd_in = ft_infile_check(argv[1]);
		fd_out = ft_outfile_check(argv[4]);
		pid1 = fork_1(argv, fd, fd_in);
		pid2 = fork_2(argv, fd, fd_out);
		close(fd[0]);
		close(fd[1]);
		waitpid(pid1, NULL, 0);
		waitpid(pid2, NULL, 0);
	}
	return (0);
}
