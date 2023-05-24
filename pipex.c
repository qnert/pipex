/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 19:26:31 by skunert           #+#    #+#             */
/*   Updated: 2023/05/24 13:14:30 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
