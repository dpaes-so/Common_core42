/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:23:00 by dpaes-so          #+#    #+#             */
/*   Updated: 2025/02/12 15:27:10 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pprocess(int *pipefd,char **path,char **av)
{
    int i;
    char *exec;
    char* argument_list[] = {"ls", "-l", NULL};

    i = 0;
    while(path[i])
    {
        exec = ft_strjoin(path[i],av[2]);
        int r = execve(exec,argument_list,NULL);
        ft_printf("%d\n",r);
        i++;
    }
}
void	cprocess(int *pipefd,char **path,char **av)
{
    
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
		cprocess(pipefd,path,av);
	else
		pprocess(pipefd,path,av);
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
