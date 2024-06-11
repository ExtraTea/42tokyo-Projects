#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	skyscrapers(int *up, int *down, int *right, int *left);

int	validate_format(const char *str);

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

int	main(int argc, char *argv[])
{
	int result;

	if (argc != 2)
	{
		write(1, "ERROR\n", 6);
		return (0);
	}

	result = validate_format(argv[1]);

	if (result == 0)
	{
		printf("Format is correct.\n");
	}
	else
	{
		printf("Format error.\n");
	}
	return (0);
}
