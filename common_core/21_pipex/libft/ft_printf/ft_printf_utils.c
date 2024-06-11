#include "ft_printf.h"

int	get_width(int widthloc, va_list arg)
{
	int	i;
	int	ret;

	i = 0;
	while (i < widthloc)
	{
		ret = va_arg(arg, int);
		i++;
	}
	return (ret);
}

int	count_digits_u(unsigned long long n, unsigned int base)
{
	if (n < base)
		return (1);
	else
		return (count_digits_u(n / base, base) + 1);
}

int	count_digits(long long n, int base)
{
	if (-base < n && n < base)
		return (1);
	else
		return (count_digits(n / base, base) + 1);
}

int	ft_max(int a, int b)
{
	if (b < a)
		return (a);
	else
		return (b);
}

int	ft_min(int a, int b)
{
	if (b > a)
		return (a);
	else
		return (b);
}
