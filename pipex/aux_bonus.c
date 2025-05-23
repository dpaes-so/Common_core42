/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:58:03 by dpaes-so          #+#    #+#             */
/*   Updated: 2025/04/08 13:14:34 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

	i = -1;
	while (envp[++i])
		if (ft_strnstr(envp[i], "PATH", 4))
			break ;
	if (!envp[i])
	{
		free(pipe.pid_array);
		close(pipe.outfile_fd);
		unlink("here_doc");
		exit(0);
	}
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

void	wait_child(int *pid_array, int ac,int *pstatus, t_pipe pipe)
{
	int	i;
	int status;

	i = 0;
	while (i < ac - 3)
	{
		if (!ft_strncmp(pipe.av[1], "here_doc", 8))
		{
			if (i != (ac - 3) - 2)
			{
				waitpid(pid_array[i], &status, 0);
			}
		}
		else
		{
			waitpid(pid_array[i], &status, 0);
		}
		i++;
	}
	if (WIFEXITED(status))
		*pstatus = WEXITSTATUS(status);
}

void	clean(t_pipe pipe)
{
	free(pipe.pid_array);
	freetrix(pipe.path);
	unlink("here_doc");
}
