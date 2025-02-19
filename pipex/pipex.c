/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:42:15 by dpaes-so          #+#    #+#             */
/*   Updated: 2025/02/19 15:10:19 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmdexec(t_pipe pipe, char *envp[], char **argument_list)
{
	int		i;
	char	*exec;

	i = 0;
	while (pipe.path[i] && argument_list[0])
	{
		exec = ft_strjoin(pipe.path[i], argument_list[0]);
		execve(exec, argument_list, envp);
		free(exec);
		i++;
	}
	freetrix(argument_list);
	freetrix(pipe.path);
	ft_putstr_fd("Command not found",2);
	exit(0);
}

void	pipex(t_pipe pipet, char *envp[], int i)
{
	int	pid;

	pipe(pipet.pipefd);
	pid = fork();
	if (pid == 0)
	{
		close(pipet.pipefd[0]);
		dup2(pipet.pipefd[1], 1);
		cmdexec(pipet, envp, ft_split(pipet.av[i], ' '));
	}
	else
	{
		wait(NULL);
		close(pipet.pipefd[1]);
		dup2(pipet.pipefd[0], 0);
	}
}

int	file_parse(t_pipe *pipe, char **av)
{
	int	i;

	pipe->outfile_fd = open(pipe->av[pipe->ac - 1],
			O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (pipe->outfile_fd < 0)
	{
		perror("Error");
		exit(0);
	}
	i = 1;
	if (access(av[1], F_OK | R_OK) < 0)
	{
		perror("Error");
		exit(0);
	}
	return (i);
}

int	main(int ac, char **av, char *envp[])
{
	t_pipe	pipe;
	int		i;
	int		pid;

	if (ac == 5)
	{
		pipe.ac = ac;
		pipe.av = av;
		i = file_parse(&pipe, av);
		pipe.infile_fd = open(pipe.av[1], O_RDONLY);
		dup2(pipe.infile_fd, 0);
		pipe.path = path_finder(envp);
		while (++i < pipe.ac - 2)
			pipex(pipe, envp, i);
		dup2(pipe.outfile_fd, 1);
		pid = fork();
		if (pid == 0)
			cmdexec(pipe, envp, ft_split(pipe.av[i], ' '));
		freetrix(pipe.path);
		close(pipe.outfile_fd);
	}
	else
		ft_putstr_fd("Please input 5 arguments", 2);
	return (0);
}
