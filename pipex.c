/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 19:26:31 by skunert           #+#    #+#             */
/*   Updated: 2023/04/30 21:17:51 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "./includes/includes.h"

int main(int argc, char **argv)
{
	char	path[] = "/bin/";
	int		file = open("test.txt", O_WRONLY);
	argv[1] = ft_strjoin(path, argv[1]);
	dup2(file, 1);
	if (execve(argv[1], argv + 1, NULL) == -1)
	{
		ft_printf("lol");
	}
}