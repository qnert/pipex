/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:04:30 by skunert           #+#    #+#             */
/*   Updated: 2023/05/25 16:16:04 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	fd_in;
	int	fd_out;
	int	check;

	if (argc >= 6)
	{
		fd_out = ft_outfile_check(argv[argc - 1]);
		check = 0;
		if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		{
			fd_in = open("here_doc", O_RDWR | O_CREAT);
			dup2(fd_in, STDIN_FILENO);
		}
		else
		{
			fd_in = ft_infile_check(argv[1]);
			check = pipex(argv, envp, fd_in, fd_out);
			if (check == -1)
				return (-1);
		}
	}
	return (0);
}

int	pipex(char **argv, char **envp, int fd_in, int fd_out)
{
	int	i;
	int	argc;
	int	fd[2];

	argc = get_len_matrix(argv);
	if (fd_in != -1)
	{
		dup2(fd_in, STDIN_FILENO);
		if (pipe(fd) == -1)
			return (perror("Error"), -1);
	}
	i = 1;
	while (++i < argc - 2 && fd_in != -1)
	{
		fork_child_proc(argv, envp, i, fd);
	}
	fork_2(argv + (argc - 5), envp, fd, fd_out);
	return (0);
}

int	get_len_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i] != NULL)
		i++;
	return (i);
}
