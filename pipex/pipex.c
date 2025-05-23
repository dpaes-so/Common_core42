/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:42:15 by dpaes-so          #+#    #+#             */
/*   Updated: 2025/04/08 18:47:30 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd_exit(char *exec, t_pipe pipe, int *pid_array, char **argument_list)
{
	if (access(exec, F_OK) < 0)
	{
		ft_putstr_fd("Pipex: Command not found\n", 2);
		freetrix(argument_list);
		freetrix(pipe.path);
		free(pid_array);
		close(pipe.outfile_fd);
		if (exec)
			free(exec);
		pipe.status = 127;
		exit(127);
	}
	if (access(exec, X_OK) < 0)
	{
		ft_putstr_fd("Permission denied\n", 2);
		freetrix(argument_list);
		freetrix(pipe.path);
		free(pid_array);
		close(pipe.outfile_fd);
		if (exec)
			free(exec);
		pipe.status = 126;
		exit(126);
	}
}

void	cmdexec(t_pipe pipe, char *envp[], char *str, int *pid_array)
{
	int		i;
	char	*exec;
	char	**argument_list;
	int		flag;

	flag = 0;
	i = 0;
	argument_list = ft_arg_split(str, ' ');
	while (flag == 0 && argument_list[0])
	{
		if (i > 0)
			free(exec);
		if (pipe.path != NULL  && pipe.path[i] && access(str, F_OK) < 0)
			exec = ft_strjoin(pipe.path[i], argument_list[0]);
		else
		{
			exec = ft_strdup(argument_list[0]);
			flag = 1;
		}
		if(access (exec, F_OK) == 0)
		{
			dprintf(2,"ASDADASDASDA\n");
			execve(exec, argument_list, envp);
		}
		i++;
	}
	cmd_exit(exec, pipe, pid_array, argument_list);
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
		if (j == 1)
			if (access(pipet.av[1], F_OK | R_OK) < 0)
				return (close(pipet.outfile_fd), freetrix(pipet.path),
					free(pid_array), exit(0));
		cmdexec(pipet, envp, pipet.av[i], pid_array);
	}
	else
	{
		close(pipet.pipefd[1]);
		dup2(pipet.pipefd[0], 0);
		close(pipet.pipefd[0]);
	}
}

void	file_parse(t_pipe *pipe, char **av, int *i, int ac)
{
	pipe->ac = ac;
	pipe->av = av;
	*i = 2;
	pipe->status = 0;
	pipe->outfile_fd = open(pipe->av[pipe->ac - 1],
			O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (pipe->outfile_fd < 0)
		return (perror("Error"), free(pipe->pid_array), close(pipe->outfile_fd),
			exit(0));
}

void	first_cmd(t_pipe pipet, char **envp, int i)
{
	int pid;
	
	pipe(pipet.pipefd);
	pid = fork();
	if (pid == 0)
	{
		close(pipet.pipefd[0]);
		dup2(pipet.pipefd[1], 1);
		close(pipet.pipefd[1]);
		
		pipet.infile_fd = open(pipet.av[1], O_RDONLY);
		dup2(pipet.infile_fd, STDIN_FILENO);
		close(pipet.infile_fd);
		close(pipet.outfile_fd);
		if (access(pipet.av[1], F_OK | R_OK) < 0)
			return (close(pipet.outfile_fd), freetrix(pipet.path),
				free(pipet.pid_array), exit(0));
		cmdexec(pipet, envp, pipet.av[i], pipet.pid_array);
	}
	else
	{
		close(pipet.pipefd[1]);
		dup2(pipet.pipefd[0], 0);
		close(pipet.pipefd[0]);
	}
}
int	main(int ac, char **av, char *envp[])
{
	t_pipe	pipe;
	int		i;

	if (ac == 5)
	{
		pipe.infile_fd = 0;
		pipe.pid_array = ft_calloc((ac - 3), sizeof(int));
		file_parse(&pipe, av, &i, ac);
		pipe.path = path_finder(envp, pipe);
		first_cmd(pipe,envp,i);
		while (++i < pipe.ac - 2)
		{
			ft_printf("IM HERE the pipe loop\n");
			pipex(pipe, envp, i, pipe.pid_array);
		}
		ft_printf("i = %d\n",i);
		last_fork(pipe, envp, i);
		close(pipe.outfile_fd);
		wait_child(pipe.pid_array, pipe.ac, &pipe.status);
		ft_printf("DEAD MAIN\n");
		clean(pipe);
	}
	else
		ft_putstr_fd("Please input 5 arguments ", 2);
	return (0);
}
