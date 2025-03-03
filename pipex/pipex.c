/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:42:15 by dpaes-so          #+#    #+#             */
/*   Updated: 2025/02/20 17:08:07 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmdexec(t_pipe pipe, char *envp[], char **argument_list, int *pid_array)
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
	free(pid_array);
	ft_putstr_fd("Command not found\n", 2);
	exit(0);
}

void	pipex(t_pipe pipet, char *envp[], int i, int *pid_array)
{
	int			pid;
	static int	j;

	pipe(pipet.pipefd);
	pid = fork();
	pid_array[j] = pid;
	j++;
	if (pid == 0)
	{
		close(pipet.pipefd[0]);
		dup2(pipet.pipefd[1], 1);
		cmdexec(pipet, envp, ft_split(pipet.av[i], ' '), pid_array);
	}
	else
	{
		close(pipet.pipefd[1]);
		dup2(pipet.pipefd[0], 0);
	}
}

void	file_parse(t_pipe *pipe, char **av, int *i, int ac)
{
	pipe->ac = ac;
	pipe->av = av;
	*i = 1;
	pipe->outfile_fd = open(pipe->av[pipe->ac - 1],
			O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (pipe->outfile_fd < 0)
	{
		free(pipe->pid_array);
		perror("Error");
		exit(0);
	}
	if (access(av[1], F_OK | R_OK) < 0)
	{
		free(pipe->pid_array);
		perror("Cant access file or it does not exist");
		exit(0);
	}
}

int	main(int ac, char **av, char *envp[])
{
	t_pipe	pipe;
	int		i;
	int		pid;

	if (ac == 5)
	{
		pipe.pid_array = malloc(sizeof(int) * (ac - 3));
		file_parse(&pipe, av, &i, ac);
		pipe.infile_fd = open(pipe.av[1], O_RDONLY);
		dup2(pipe.infile_fd, 0);
		pipe.path = path_finder(envp, pipe);
		while (++i < pipe.ac - 2)
			pipex(pipe, envp, i, pipe.pid_array);
		dup2(pipe.outfile_fd, 1);
		pid = fork();
		pipe.pid_array[ac - 4] = pid;
		if (pid == 0)
			cmdexec(pipe, envp, ft_split(pipe.av[i], ' '), pipe.pid_array);
		wait_child(pipe.pid_array, ac);
		clean(pipe);
		close(pipe.outfile_fd);
	}
	else
		ft_putstr_fd("Please input 5 argumetns\n", 2);
	return (0);
}
