#include "pipex.h"

void	multiple_close(int *a, int *b, int *c, int *d)
{
	if (a != NULL)
		close(*a);
	if (b != NULL)
		close(*b);
	if (c != NULL)
		close(*c);
	if (d != NULL)
		close(*d);
}

int	execute_command_with_input(char **command, char *std_in, pid_t *last_child, int fd)
{
	int		a;
	int		pipefd1[2];
	int		pipefd2[2];

	if (pipe(pipefd1) == -1 || pipe(pipefd2) == -1)
		return ((int)(uintptr_t)handle_error_array(strerror(errno), (void **)command));
	if (std_in == NULL)
		dup2(fd, pipefd1[1]);
	*last_child = fork();
	if (*last_child == 0)
	{
		if (std_in == NULL)
            dup2(fd, 0);
        else
            dup2(pipefd1[0], 0);
		dup2(pipefd2[1], 1);
		multiple_close(&pipefd1[1], &pipefd2[0], &pipefd1[0], &pipefd2[1]);
		a = execve(command[0], command, NULL);
		if (a == -1)
		{
			if (errno == ENOENT)
				exit(127 + (int)(uintptr_t)handle_error_array("command not found", (void **)command));
			else
				exit(1 + (int)(uintptr_t)handle_error_array(strerror(errno), (void **)command));
		}
	}
	ft_putstr_fd(std_in, pipefd1[1]);
	multiple_close(&pipefd1[0], &pipefd2[1], &pipefd1[1], NULL);
	return (pipefd2[0]);
}

int	execute_command_and_get_output(char *execname,
			char **envp, char *std_in, pid_t *last_child, int fd)
{
	char	**path;
	char	**command;
	char	*full_command;
	int ret;

	path = extract_path_from_env(envp);
	if (path == NULL)
		return (0);
	command = ft_split_mod(execname, ' ');
	full_command = find_executable_path(path, command[0]);
	free(command[0]);
	command[0] = full_command;
	ret = execute_command_with_input(command, std_in, last_child, fd);
	free_string_array((void **)path);
	free_string_array((void **)command);
	if (ret == 0)
		return (0);
	return (ret);
}
