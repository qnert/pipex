/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_check_and_awk.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:24:40 by skunert           #+#    #+#             */
/*   Updated: 2023/06/07 16:35:26 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

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
		while (argv[i][j] != ' ')
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

void	check_envp(char **envp)
{
	int	i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
	{
		if (envp[i] == NULL)
		{
			ft_printf("PATH not found\n");
			exit(-1);
		}
		i++;
	}
}
