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
	dup2(pipe.infile_fd,0);
	close(pipe.pipefd[0]);
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
	close(pipe.pipefd[1]);
	dup2(pipe.pipefd[0], 0);
	close(pipe.pipefd[0]);
	dup2(pipe.outfile_fd, 1);
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
void here_doc(t_pipe pipe)
{
	char *str;
	int fd;
	int i;

	fd = open(pipe.av[1],O_CREAT | O_RDWR,0644);
	write(fd,"HEY",3);
	while(1)
	{
		i = 0;
		str = get_next_line(0);
		if(!ft_strncmp(str,pipe.av[2],ft_strlen(pipe.av[2])))
			break;
		while(str[i])
			write(fd,&str[i++],1);
		free(str);
	}
	close(fd);
	free(str);
}
int	main(int ac, char **av, char *envp[])
{
	t_pipe pipe;

	if (ac > 4)
	{
		pipe.ac = ac;
		pipe.av = av;
		if(!ft_strncmp(pipe.av[1],"here_doc",8))
			here_doc(pipe);
		if (access(av[1], F_OK | R_OK) < 0)
		{
			ft_printf("Cant access file or it does not exist\n");
			exit(0);
		}
		pipe.path = path_finder(envp);
		pipex(pipe, envp);
		freetrix(pipe.path);
	}
	else
		ft_printf("Not enough arguments");
	ft_printf("\n");
}
