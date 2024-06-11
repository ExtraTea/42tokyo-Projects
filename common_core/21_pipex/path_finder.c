#include "pipex.h"

char	**extract_path_from_env(char **envp)
{
	char	**ret;

	if (envp == NULL)
	{
		ret = ft_split("", ':');
		return (ret);
	}
	ret = NULL;
	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
		{
			ret = ft_split((*envp) + 5, ':');
			return (ret);
		}
		envp++;
	}
	if (ret == NULL)
		ret = ft_split("", ':');
	return (ret);
}

char	*find_executable_path(char **path, char *command)
{
	char	*c;
	char	*command_w_slash;

	command_w_slash = ft_strjoin("/", command);
	while (*path != NULL)
	{
		if ((*path)[ft_strlen(*path) - 1] == '/')
			c = ft_strjoin(*path, command);
		else
			c = ft_strjoin(*path, command_w_slash);
		if (access(c, X_OK) == 0)
		{
			free(command_w_slash);
			return (c);
		}
		else
		{
			free(c);
			path++;
		}
	}
	free(command_w_slash);
	return (ft_strdup(command));
}
