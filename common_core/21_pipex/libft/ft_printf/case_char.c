#include "ft_printf.h"

int	case_char(t_flags flag, va_list args)
{
	char	c;
	int		width;
	int		i;

	c = va_arg(args, int);
	width = 1;
	flag.width = ft_max(width, flag.width);
	i = 0;
	if (flag.five_flags[0] == 0)
	{
		while (i++ < flag.width - width)
			ft_putchar_fd(' ', 1);
		ft_putchar_fd(c, 1);
	}
	else
	{
		ft_putchar_fd(c, 1);
		while (i++ < flag.width - width)
			ft_putchar_fd(' ', 1);
	}
	return (i);
}
