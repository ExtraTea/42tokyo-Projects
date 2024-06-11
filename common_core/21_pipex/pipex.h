#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
# include <errno.h>
# include "./libft/libft/libft.h"
# include "./libft/ft_printf/ft_printf.h"
# include "./libft/get_next_line/get_next_line.h"

int execute_command_and_get_output(char *execname, char **envp, char *std_in, int *exit_code, int fd);
int execute_command_with_input(char **command, char *std_in, int *exit_code, int fd);

char	*read_stdin_to_string(char *limiter);
char	*read_file_to_string(int fd, char *filename);
int	open_file_readonly(char *filename);

void free_string_array(void **array);

void	*handle_error_and_free(char *err_msg, void *alloc_mem, char *filename);
void *handle_error_array(char *err_msg, void **alloc_mem);

char **extract_path_from_env(char **envp);
char *find_executable_path(char **path, char *command);


char	**ft_split_mod(char const *s, char c);

#endif