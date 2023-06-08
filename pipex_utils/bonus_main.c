/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:12:34 by skunert           #+#    #+#             */
/*   Updated: 2023/06/08 14:13:17 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	fd_in;
	int	fd_out;

	if (argc >= 5)
	{
		check_envp(argv, envp);
		if (ft_strncmp(argv[1], "here_doc", 8) == 0)
			fd_in = read_till_limiter(argv);
		else
			fd_in = ft_infile_check(argv[1]);
		fd_out = ft_outfile_check(argv[argc - 1]);
		if (ft_strncmp(argv[1], "here_doc", 8) == 0)
			unlink("here_doc");
		pipex(argv, envp, fd_in, fd_out);
		close(fd_in);
		close(fd_out);
	}
	else
		ft_printf("Too few arguments!\n");
	return (0);
}