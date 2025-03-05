/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_aux_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:22:35 by dpaes-so          #+#    #+#             */
/*   Updated: 2025/03/05 12:29:32 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	here_doc_check(t_pipe *pipe, int *i)
{
	if (pipe->ac < 6)
	{
		ft_putstr_fd("Please input at least 2 commands with here_doc", 2);
		close(pipe->outfile_fd);
		free(pipe->pid_array);
		exit(0);
	}
	here_doc(pipe);
	*i = 2;
}

void	last_fork(t_pipe pipe, char **envp, int i)
{
	int	pid;

	pid = fork();
	if (pid == 0)
		cmdexec(pipe, envp, ft_arg_split(pipe.av[i], ' '), pipe.pid_array);
	else
		pipe.pid_array[pipe.ac - 4] = pid;
}
