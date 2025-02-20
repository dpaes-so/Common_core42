/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:23:36 by dpaes-so          #+#    #+#             */
/*   Updated: 2025/02/20 15:14:20 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
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
	int		*pid_array;
}			t_pipe;

// main
void		file_parse(t_pipe *pipe, char **av, int *i, int ac);
// aux
void		freetrix(char **matrix);
char		**path_finder(char **envp, t_pipe pipe);
void		wait_child(int *pid_array, int ac, t_pipe pipe);
void		clean(t_pipe pipe);
#endif