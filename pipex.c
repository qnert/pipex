/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 19:26:31 by skunert           #+#    #+#             */
/*   Updated: 2023/04/30 23:16:20 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv)
{
	if (argc == 5)
	{
		ft_printf("%d\n", ft_infile_check(argv[1]));
		ft_printf("%d\n", ft_outfile_check(argv[4]));

	}
	return (0);
}