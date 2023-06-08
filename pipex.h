/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:49:35 by skunert           #+#    #+#             */
/*   Updated: 2023/06/08 10:16:05 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./includes/includes.h"
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <stdio.h>

int		ft_outfile_check(char *filepath);
int		ft_infile_check(char *filepath);
char	*get_path_env(char *cmd, char **envp);
void	exec_cmd(char *cmd, char **envp);
int		fork_end(char **argv, char **envp, int *fd, int fd_out);
int		fork_child_proc(char **argv, char **envp, int *fd);
int		get_len_matrix(char **matrix);
int		pipex(char **argv, char **envp, int fd_in, int fd_out);
int		read_till_limiter(char **argv);
void	get_awk_args(char **cmd_args);
char	*get_check(char **argv, char **envp, int argc);

#endif