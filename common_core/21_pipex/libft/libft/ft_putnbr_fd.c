#include "libft.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n < 0)
		write(fd, "-", 1);
	if (-9 <= n && n <= 9)
		write(fd, " ", 0);
	else
		ft_putnbr_fd(ft_abs(n / 10), fd);
	c = '0' + ft_abs(n % 10);
	write(fd, &c, 1);
	return ;
}
