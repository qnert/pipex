/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 22:32:32 by skunert           #+#    #+#             */
/*   Updated: 2023/04/30 23:15:55 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_outfile_check(char *filepath)
{
	int fd;
	int	fd_err;

	fd = open(filepath, O_RDWR);
	if (fd < 0)
	{
		fd_err = open(filepath, O_RDWR | O_CREAT);
		return (fd_err);
	}
	return (fd);
}

int	ft_infile_check(char *filepath)
{
	int fd;

	fd = open(filepath, O_RDWR);
	if (fd < 0)
		return (-1);
	return (fd);
}