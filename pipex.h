/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:49:35 by skunert           #+#    #+#             */
/*   Updated: 2023/05/22 10:47:37 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./includes/includes.h"
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>

int		ft_outfile_check(char *filepath);
int		ft_infile_check(char *filepath);
char	**get_command(char **argv);
int		execute_command(char **command, int fd);
int		fork_1(char **argv, int *fd, int fd_in);
int		fork_2(char **argv, int *fd, int fd_out);

#endif