/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:04:30 by skunert           #+#    #+#             */
/*   Updated: 2023/06/09 12:57:29 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	pipex(char **argv, char **envp, int fd_in, int fd_out)
{
	int		i;
	int		argc;
	int		fd[2];
	char	*check;

	i = 0;
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		i++;
	argc = get_len_matrix(argv);
	check = get_check(argv + i, envp, argc);
	if (fd_in != -1 && check != NULL)
		dup2(fd_in, STDIN_FILENO);
	if (pipe(fd) == -1)
		return (perror("Error"), -1);
	i++;
	while (++i < argc - 2 && fd_in != -1 && check != NULL)
		fork_child_proc(argv + i, envp, fd);
	if (fd_in == -1 || check == NULL)
		fork_end(argv + (argc - 2), envp, fd, fd_out);
	else
		fork_end(argv + i, envp, fd, fd_out);
	if (check != NULL)
		free(check);
	return (0);
}

int	read_till_limiter(char **argv)
{
	char	*line;
	int		fd_in;

	fd_in = ft_outfile_check(argv[1]);
	dup2(fd_in, STDOUT_FILENO);
	line = get_next_line(0);
	while (ft_strncmp(line, argv[2], ft_strlen(argv[2]) != 0))
	{
		ft_printf("%s", line);
		free(line);
		line = get_next_line(0);
	}
	free(line);
	close(fd_in);
	fd_in = open(argv[1], O_RDONLY);
	return (fd_in);
}

int	get_len_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i] != NULL)
		i++;
	return (i);
}
