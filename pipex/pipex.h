/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:23:36 by dpaes-so          #+#    #+#             */
/*   Updated: 2025/02/19 11:41:42 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "includes/libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_pipe
{
	int		ac;
	char	**av;
	char	**path;
	int		infile_fd;
	int		outfile_fd;
	int		pipefd[2];
}			t_pipe;

// aux
void		freetrix(char **matrix);
char		**path_finder(char **envp);
#endif