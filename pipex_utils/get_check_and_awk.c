/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_check_and_awk.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:24:40 by skunert           #+#    #+#             */
/*   Updated: 2023/06/08 19:12:32 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"
#include <stdio.h>

void	get_awk_args(char **cmd_args)
{
	int	i;

	i = 2;
	while (cmd_args[i] != NULL)
	{
		cmd_args[1] = ft_strjoin_free(cmd_args[1], " ");
		cmd_args[1] = ft_strjoin_free(cmd_args[1], cmd_args[i]);
		i++;
	}
	i = 2;
	while (cmd_args[i] != NULL)
	{
		free(cmd_args[i]);
		i++;
	}
	cmd_args[2] = NULL;
}

char	*get_check(char **argv, char **envp, int argc)
{
	int		i;
	int		j;
	char	*cmd;
	char	*ret_check;

	i = 2;
	while (i < argc - 2)
	{
		j = 0;
		while (argv[i][j] != '\0' && argv[i][j] != ' ')
			j++;
		cmd = ft_substr(argv[i], 0, j);
		ret_check = get_path_env(cmd, envp);
		free(cmd);
		if (ret_check == NULL)
			return (NULL);
		if ((i + 1) != (argc - 2))
			free(ret_check);
		i++;
	}
	return (ret_check);
}

int	check_absolut_path(char **argv)
{
	int		i;
	int		j;
	int		argc;
	char	*cmd;

	i = 2;
	argc = get_len_matrix(argv);
	while (i < argc -2)
	{
		j = 0;
		while (argv[i][j] != '\0' && argv[i][j] != ' ')
			j++;
		cmd = ft_substr(argv[i], 0, j);
		if (access(cmd, F_OK | X_OK) != 0)
			return (free(cmd), -1);
		free(cmd);
		i++;
	}
	return (0);
}

void	check_envp(char **argv, char **envp)
{
	int	i;
	int	fd;
	int	check;

	i = 0;
	while (envp[i] != NULL && ft_strnstr(envp[i], "PATH", 4) == NULL)
		i++;
	if (envp[i] == NULL)
	{
		check = check_absolut_path(argv);
		if (check == -1)
		{
			fd = ft_outfile_check(argv[get_len_matrix(argv) - 1]);
			write(2, "command not found\n", 18);
			close (fd);
			exit(-1);
		}
	}
}
