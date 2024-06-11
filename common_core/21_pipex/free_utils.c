#include "pipex.h"

void	free_string_array(void **array)
{
	void	**temp;

	temp = array;
	while (*temp != NULL)
	{
		free(*temp);
		*temp = NULL;
		temp++;
	}
	free(array);
}
