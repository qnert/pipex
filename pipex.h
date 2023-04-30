#ifndef PIPEX_H
# define PIPEX_H

# include "./includes/includes.h"
#include <unistd.h>
#include <fcntl.h>

int	ft_outfile_check(char *filepath);
int	ft_infile_check(char *filepath);

#endif