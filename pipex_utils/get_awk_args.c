/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_awk_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:24:40 by skunert           #+#    #+#             */
/*   Updated: 2023/05/26 18:25:33 by skunert          ###   ########.fr       */
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
