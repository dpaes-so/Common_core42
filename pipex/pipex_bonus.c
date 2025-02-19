/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:42:15 by dpaes-so          #+#    #+#             */
/*   Updated: 2025/02/19 11:52:57 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	here_doc(t_pipe *pipe)
{
	char	*str;
	int		fd;
	int		i;

	fd = open(pipe->av[1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	while (1)
	{
		i = 0;
		str = get_next_line(0);
		if (!ft_strncmp(str, pipe->av[2], ft_strlen(pipe->av[2])))
			break ;
		while (str[i])
			write(fd, &str[i++], 1);
		free(str);
	}
	close(fd);
	free(str);
}

void	cmdexec(t_pipe pipe, char *envp[], char **argument_list)
{
	int		i;
	char	*exec;

	i = 0;
	while (pipe.path[i])
	{
		exec = ft_strjoin(pipe.path[i], argument_list[0]);
		execve(exec, argument_list, envp);
		free(exec);
		i++;
	}
	freetrix(argument_list);
	freetrix(pipe.path);
	perror("Command not found\n");
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
		ft_printf("Error\n cant acces outfile");
		exit(0);
	}
	if (!ft_strncmp(pipe->av[1], "here_doc", 8))
	{
		here_doc(pipe);
		i = 2;
	}
	else
		i = 1;
	if (access(av[1], F_OK | R_OK) < 0)
	{
		ft_printf("Cant access file or it does not exist\n");
		exit(0);
	}
	return (i);
}

int	main(int ac, char **av, char *envp[])
{
	t_pipe	pipe;
	int		i;
	int		pid;

	if (ac > 4)
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
		ft_printf("Not enough arguments");
	return (0);
}
