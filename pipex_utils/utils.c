/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 22:32:32 by skunert           #+#    #+#             */
/*   Updated: 2023/05/25 09:47:05 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	free_arr(char **arr)
{
	unsigned int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	ft_outfile_check(char *filepath)
{
	int	fd;
	int	fd_err;

	fd = open(filepath, O_RDWR | O_TRUNC, 0644);
	if (fd < 0)
	{
		fd_err = open(filepath, O_RDWR | O_CREAT, 0644);
		return (fd_err);
	}
	return (fd);
}

int	ft_infile_check(char *filepath)
{
	int	fd;

	fd = open(filepath, O_RDWR);
	if (fd < 0)
		return (-1);
	return (fd);
}

char	*get_path_env(char *cmd, char **envp)
{
	char	**paths;
	char	*cmd_path;
	char	*curr_path;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == NULL)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = -1;
	while (paths[++i] != NULL)
	{
		curr_path = ft_strjoin(paths[i], "/");
		cmd_path = ft_strjoin(curr_path, cmd);
		free(curr_path);
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (free_arr(paths), cmd_path);
		free(cmd_path);
	}
	free_arr(paths);
	return (NULL);
}

void	exec_cmd(char *cmd, char **envp)
{
	char	**cmd_args;
	char	*cmd_path;

	cmd_args = ft_split(cmd, ' ');
	cmd_path = get_path_env(cmd_args[0], envp);
	if (cmd_path == NULL)
		write(2, "command not found\n", 18);
	if (execve(cmd_path, cmd_args, envp) == -1 && cmd_path != NULL)
	{
		free_arr(cmd_args);
		free(cmd_path);
		perror("Error");
	}
	free_arr(cmd_args);
	free(cmd_path);
}