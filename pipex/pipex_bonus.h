/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:23:36 by dpaes-so          #+#    #+#             */
/*   Updated: 2025/03/05 12:26:34 by dpaes-so         ###   ########.fr       */
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
void	pipex(t_pipe pipet, char *envp[], int i, int *pid_array);
void	cmdexec(t_pipe pipe, char *envp[], char **argument_list, int *pid_array);
void	here_doc(t_pipe *pipe);
// aux
void		freetrix(char **matrix);
char		**path_finder(char **envp, t_pipe pipe);
void		wait_child(int *pid_array, int ac, t_pipe pipe);
void		clean(t_pipe pipe);
//more aux
void	here_doc_check(t_pipe *pipe, int *i);
void	last_fork(t_pipe pipe, char **envp, int i);
//arg split
char	**ft_arg_split(char const *s, char c);
#endif