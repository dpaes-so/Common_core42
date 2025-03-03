/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:42:15 by dpaes-so          #+#    #+#             */
/*   Updated: 2025/03/03 18:56:33 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
		{
			free(str);
			break ;
		}
		while (str[i])
			write(fd, &str[i++], 1);
		free(str);
	}
	close(fd);
}

void	cmdexec(t_pipe pipe, char *envp[], char **argument_list, int *pid_array)
{
	int		i;
	char	*exec;

	i = 0;
	while (pipe.path[i] && argument_list[0])
	{
		exec = ft_strjoin(pipe.path[i], argument_list[0]);
		close(pipe.outfile_fd);
		execve(exec, argument_list, envp);
		free(exec);
		i++;
	}
	freetrix(argument_list);
	freetrix(pipe.path);
	free(pid_array);
	ft_putstr_fd("Command not found\n", 2);
	exit(127);
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
		close(pipet.pipefd[1]);
		cmdexec(pipet, envp, ft_arg_split(pipet.av[i], ' '), pid_array);
	}
	else
	{
		close(pipet.pipefd[1]);
		dup2(pipet.pipefd[0], 0);
		close(pipet.pipefd[0]);
	}
}

void here_doc_check(t_pipe *pipe,int *i)
{
		if (pipe->ac < 6)
		{
			ft_putstr_fd("Please input at least 2 commands with here_doc", 2);
			close(pipe->outfile_fd);
			free(pipe->pid_array);
			exit(0);
		}
		here_doc(pipe);
		*i = 2;
}
void	file_parse(t_pipe *pipe, char **av, int *i, int ac)
{
	pipe->ac = ac;
	pipe->av = av;
	*i = 1;
	pipe->outfile_fd = open(pipe->av[pipe->ac - 1],
			O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (pipe->outfile_fd < 0)
		return (perror("Error"), free(pipe->pid_array), close(pipe->outfile_fd),
			exit(0));
	if (!ft_strncmp(pipe->av[1], "here_doc", 8))
		here_doc_check(pipe,i);
	if (access(av[1], F_OK | R_OK) < 0)
	{
		free(pipe->pid_array);
		perror("Cant access file or it does not exist");
		close(pipe->outfile_fd);
		exit(0);
	}
}

void	last_fork(t_pipe pipe, char **envp, int i)
{
	int	pid;

	pid = fork();
	if (pid == 0)
		cmdexec(pipe, envp, ft_arg_split(pipe.av[i], ' '), pipe.pid_array);
	else
		pipe.pid_array[pipe.ac - 4] = pid;
}

int	main(int ac, char **av, char *envp[])
{
	t_pipe	pipe;
	int		i;

	if (ac > 4)
	{
		pipe.pid_array = malloc(sizeof(int) * (ac - 3));
		file_parse(&pipe, av, &i, ac);
		pipe.infile_fd = open(pipe.av[1], O_RDONLY);
		if (pipe.infile_fd < 0)
			return (perror(""), free(pipe.pid_array), close(pipe.outfile_fd));
		dup2(pipe.infile_fd, 0);
		close(pipe.infile_fd);
		pipe.path = path_finder(envp, pipe);
		while (++i < pipe.ac - 2)
			pipex(pipe, envp, i, pipe.pid_array);
		dup2(pipe.outfile_fd, 1);
		close(pipe.outfile_fd);
		last_fork(pipe, envp, i);
		close(0);
		wait_child(pipe.pid_array, pipe.ac, pipe);
		clean(pipe);
	}
	else
		ft_putstr_fd("Not enough arguments ", 2);
	return (0);
}
