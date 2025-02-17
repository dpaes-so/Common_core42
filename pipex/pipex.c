#include "pipex.h"

void	pprocess(t_pipe pipe, char *envp[])
{
	int		i;
	char	*exec;
	char	**argument_list;

	if (!*pipe.av[2])
		exit(0);
	argument_list = ft_split(pipe.av[2], ' ');
	i = 0;
	close(pipe.outfile_fd);
	close(pipe.pipefd[0]);
	dup2(pipe.infile_fd,0);
	close(pipe.infile_fd);
	dup2(pipe.pipefd[1], 1);
	close(pipe.pipefd[1]);
	while (pipe.path[i])
	{
		exec = ft_strjoin(pipe.path[i], argument_list[0]);
		execve(exec, argument_list, envp);
		free(exec);
		i++;
	}
	freetrix(argument_list);
	perror("Command not found");
	exit(1);
}
void	cprocess(t_pipe pipe, char *envp[])
{
	int		i;
	char	*exec;
	char	**argument_list;

	if (!*pipe.av[3])
		exit(0);
	argument_list = ft_split(pipe.av[3], ' ');
	i = 0;
	close(pipe.infile_fd);
	close(pipe.pipefd[1]);
	dup2(pipe.pipefd[0], 0);
	close(pipe.pipefd[0]);
	dup2(pipe.outfile_fd, 1);
	close(pipe.outfile_fd);
	while (pipe.path[i])
	{
		exec = ft_strjoin(pipe.path[i], argument_list[0]);
		execve(exec, argument_list, envp);
		free(exec);
		i++;
	}
	freetrix(argument_list);
	perror("Command not found");
	exit(1);
}
void	pipex(t_pipe pipet, char *envp[])
{
	int	pid;

	pipet.outfile_fd = open(pipet.av[pipet.ac - 1],
			O_CREAT | O_WRONLY | O_TRUNC, 0644);
	pipet.infile_fd = open(pipet.av[1],O_RDONLY);
	if (pipet.outfile_fd < 0)
	{
		ft_printf("Error\n cant acces outfile");
		exit(0);
	}
	pipe(pipet.pipefd);
	pid = fork();
	if (pid < 0)
		exit(0);
	if (pid == 0)
		cprocess(pipet, envp);
	pid = fork();
	if (pid < 0)
		exit(0);
	if (pid == 0)
		pprocess(pipet, envp);
}
int	main(int ac, char **av, char *envp[])
{
	t_pipe pipe;

	if (ac == 5)
	{
		if (access(av[1], F_OK | R_OK) < 0)
		{
			ft_printf("Cant access file or it does not exist\n");
			exit(0);
		}
		pipe.path = path_finder(envp);
		pipe.ac = ac;
		pipe.av = av;
		pipex(pipe, envp);
		wait(NULL);
		freetrix(pipe.path);
	}
	ft_printf("\n");
}