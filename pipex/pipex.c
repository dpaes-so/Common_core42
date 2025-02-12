/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:23:00 by dpaes-so          #+#    #+#             */
/*   Updated: 2025/02/12 17:24:25 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pprocess(int *pipefd, char **path, char **av)
{
	int		i;
	char	*exec;
	char	**argument_list = ft_split(av[2], ' ');

	i = 0;
    close(pipefd[0]);
    dup2(pipefd[1],1);
    close(pipefd[1]);
    while(argument_list[i])
    {
        ft_printf("HERE BITCH%s\n",argument_list[i]);
        i++;
    }
    i = 0;
	while (path[i])
	{
		exec = ft_strjoin(path[i], argument_list[0]);
		execve(exec, argument_list, NULL);
		i++;
	}
}
void	cprocess(int *pipefd, char **path, char **av)
{
    int		i;
	char	*exec;
	char	**argument_list = ft_split(av[3], ' ');

	i = 0;
    close(pipefd[1]);
    dup2(pipefd[0],0);
    close(pipefd[0]);
	while (path[i])
	{
		exec = ft_strjoin(path[i], argument_list[0]);
		execve(exec, argument_list, NULL);
		i++;
	}
}
void	pipex(char **av, int ac, char **path)
{
	int	pid;
	int	pipefd[2];

	if (access(av[ac - 1], F_OK | R_OK | W_OK) < 0)
	{
		ft_printf("Error\n cant accest outfile");
		exit(0);
	}
	open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	pipe(pipefd);
	pid = fork();
	if (pid < 0)
		exit(0);
	if (pid == 0)
		cprocess(pipefd, path, av);
	else
		pprocess(pipefd, path, av);
}
int	main(int ac, char **av, char *envp[])
{
	char	**path;
	int		i;

	i = 0;
	if (ac == 5)
	{
		if (access(av[1], F_OK | R_OK) < 0)
		{
			ft_printf("Cant access file or it does not exist\n");
			exit(0);
		}
		path = path_finder(av, envp);
		pipex(av, ac, path);
		freetrix(path);
		ft_printf("i got here");
	}
	ft_printf("\n");
}
