/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:58:03 by dpaes-so          #+#    #+#             */
/*   Updated: 2025/02/12 15:19:24 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	freetrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		i++;
	while (i--)
		free(matrix[i]);
	free(matrix);
}
char	**path_finder(char **av, char **envp)
{
	int i;
	char **path;
	char **split;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH", 4))
			break ;
		i++;
	}
	envp[i] = envp[i] + 5;
	split = ft_split(envp[i], ':');
	path = malloc(sizeof(char *) * i);
	i = 0;
	while (split[i])
	{
		path[i] = ft_strjoin(split[i], "/");
		free(split[i]);
		i++;
	}
	free(split);
	return (path);
}