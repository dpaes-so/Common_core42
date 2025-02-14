/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:23:36 by dpaes-so          #+#    #+#             */
/*   Updated: 2025/02/14 15:58:07 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "includes/libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_pipe
{
	int		ac;
	char	**av;
	char	**path;
    int     infile_fd;
    int     outfile_fd;
    int     pipefd[2];
}			t_pipe;

// aux
void		freetrix(char **matrix);
char		**path_finder(char **envp);
#endif