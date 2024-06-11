#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		i;
	int		fd;
	int exit_code;
	pid_t last_child;
	char	*std_input;

	if (argc < 5)
		return (write(1, "gimme more", 10));
	i = 2;
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
	{
		std_input = read_stdin_to_string(argv[2]);
		i++;
	}
	else
		std_input = read_file_to_string(open_file_readonly(argv[1]), argv[1]);
	if (std_input == NULL)
		std_input = ft_strdup("");
	while (i < argc - 1){
		fd = execute_command_and_get_output(argv[i++], envp, std_input, &last_child, fd);
		free(std_input);
		std_input = NULL;
	}
	std_input = read_file_to_string(fd, argv[argc - 1]);
	waitpid(last_child, &exit_code, WUNTRACED);
	fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_putstr_fd(std_input, fd);
	free(std_input);
	close(fd);
	return (WEXITSTATUS(exit_code));
}
