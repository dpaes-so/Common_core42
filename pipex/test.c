#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int	main(int ac, char *av[], char *env[])
{
	int		pipefd[2];
	int		pid;
	char	*cat_args[] = {"/bin/cat", "infile", NULL};
	char	*grep_args[] = {"/usr/bin/grep", "Lausanne", NULL};

	(void)ac;
	(void)av;
	// Create the pipe
	if (pipe(pipefd) == -1)
	{
		perror("pipe failed");
		return (1);
	}
	// Fork the process
	pid = fork();
	if (pid < 0)
	{
		perror("fork failed");
		return (1);
	}
	if (pid == 0)
	{
		// Child process: grep Lausanne
		close(pipefd[1]); // Close the write end of the pipe
		// Redirect stdin to read from the pipe
		if (dup2(pipefd[0], STDIN_FILENO) == -1)
		{
			perror("dup2 failed");
			return (1);
		}
		close(pipefd[0]); // Close after duplication
		// Execute grep
		execve("/usr/bin/grep", grep_args, env);
		perror("execve grep failed");
		return (1);
	}
	else
	{
		// Parent process: cat infile
		close(pipefd[0]); // Close the read end of the pipe
		// Redirect stdout to write into the pipe
		if (dup2(pipefd[1], STDOUT_FILENO) == -1)
		{
			perror("dup2 failed");
			return (1);
		}
		close(pipefd[1]); // Close after duplication
		// Execute cat
		execve("/bin/cat", cat_args, env);
		perror("execve cat failed");
		return (1);
	}
	return (0);
}
