/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:58:03 by dpaes-so          #+#    #+#             */
/*   Updated: 2025/02/20 16:26:50 by dpaes-so         ###   ########.fr       */
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
		ft_printf("Cant find path");
		free(pipe.pid_array);
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

void	wait_child(int *pid_array, int ac, t_pipe pipe)
{
	int	i;
	int	status;

	i = 0;
	// close(0);
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
}

void	clean(t_pipe pipe)
{
	free(pipe.pid_array);
	freetrix(pipe.path);
	unlink("here_doc");
}
