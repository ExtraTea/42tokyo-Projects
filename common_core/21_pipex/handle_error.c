#include "pipex.h"

void	*handle_error_and_free(char *err_msg, void *alloc_mem, char *filename)
{
	free(alloc_mem);
	write(2, "pipex: line 1: ", 15);
	ft_putstr_fd(filename, 2);
	write(2, ": ", 2);
	ft_putstr_fd(err_msg, 2);
	write(2, "\n", 1);
	return (NULL);
}

void	*handle_error_array(char *err_msg, void **alloc_mem)
{
	write(2, "pipex: line 1: ", 15);
	ft_putstr_fd(((char **)alloc_mem)[0], 2);
	write(2, ": ", 2);
	ft_putstr_fd(err_msg, 2);
	write(2, "\n", 1);
	free_string_array(alloc_mem);
	return (NULL);
}
