/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:58:03 by dpaes-so          #+#    #+#             */
/*   Updated: 2025/04/02 18:58:15 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	freetrix(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix)
		return ;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

char	**path_finder(char **envp, t_pipe pipe)
{
	int		i;
	char	*temp;
	char	**split;

	pipe.status = 0;
	i = -1;
	while (envp[++i])
		if (ft_strnstr(envp[i], "PATH", 4))
			break ;
	if (!envp[i])
		return(NULL);
	envp[i] = envp[i] + 5;
	split = ft_split(envp[i], ':');
	i = -1;
	while (split[++i])
	{
		temp = split[i];
		split[i] = ft_strjoin(temp, "/");
		free(temp);
	}
	return (split);
}

void	wait_child(int *pid_array, int ac, int *pstatus)
{
	int	i;
	int	status;

	waitpid(pid_array[0], NULL, 0);
	i = 1;
	while (i < ac - 3)
	{
		waitpid(pid_array[i], &status, 0);
		i++;
	}
	if (WIFEXITED(status))
		*pstatus = WEXITSTATUS(status);
}

void	clean(t_pipe pipe)
{
	free(pipe.pid_array);
	freetrix(pipe.path);
	exit(pipe.status);
}

void	last_fork(t_pipe pipe, char **envp, int i)
{
	int	pid;

	pid = fork();
	if (pid == 0)
		cmdexec(pipe, envp, pipe.av[i], pipe.pid_array);
	else
		pipe.pid_array[pipe.ac - 4] = pid;
}
