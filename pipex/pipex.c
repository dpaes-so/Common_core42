/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:23:00 by dpaes-so          #+#    #+#             */
/*   Updated: 2025/02/12 00:03:31 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


void pprocess (int *pipefd)
{
    close(pipefd[0]);
    char* argument_list[] = {"ls", "-l", NULL};
    ft_printf("im parent process\n");
    dup2(pipefd[1],1);
    close(pipefd[1]);
    execvp("ls",argument_list);
    ft_printf("i am not suppose to appear");
}
void cprocess (int *pipefd)
{
    close(pipefd[1]);
    char* argument_list[] = {"wc", "-l", NULL};
    ft_printf("im child process\n");
    dup2(pipefd[0],0);
    close(pipefd[0]);
    execvp("wc",argument_list);
    ft_printf("i am not suppose to appear");
}
void	pipex(char **av,int ac)
{
    int pid;
    int pipefd[2];
    
	ft_printf("IM ACCESIBLE = %s\n",av[2]);
    open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if(access(av[ac -1],F_OK | R_OK |W_OK) < 0)
    {
        ft_printf("Error\n cant accest outfile");
        exit(0);
    }
    pipe(pipefd);
    pid = fork();
    if (pid < 0)
        exit(0);
    if(pid == 0)
        cprocess(pipefd);
    else                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
        pprocess(pipefd);
}
int	main(int ac, char **av,char *envp[])
{
	if (ac == 5)
	{
		if (access(av[1],F_OK | R_OK) < 0)
		{
			ft_printf("Cant access file or it does not exist\n");
			exit(0);
		}
        int i = 0;
		pipex(av,ac);
	}
	ft_printf("\n");
}
