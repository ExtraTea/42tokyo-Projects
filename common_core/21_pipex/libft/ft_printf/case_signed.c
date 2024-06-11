#include "ft_printf.h"

int	case_signed_d(t_flags flag, long long d, int width)
{
	int	i;
	int	suf_zero;

	suf_zero = ft_max(flag.precision - width, 0);
	if (flag.five_flags[3] == 1 || flag.five_flags[4] == 1 || d < 0)
		width++;
	flag.width = ft_max(width, flag.width);
	i = -1;
	if (flag.five_flags[0] == 0)
	{
		if (flag.five_flags[1] == 1)
			suf_zero += flag.width - width;
		else
			while (++i < flag.width - width - suf_zero)
				ft_putchar_fd(' ', 1);
	}
	ft_putllnbr(d, 1, flag.five_flags[3] + flag.five_flags[4] * 2, suf_zero);
	if (flag.five_flags[0] == 1)
		while (++i < flag.width - width - suf_zero)
			ft_putchar_fd(' ', 1);
	if (flag.five_flags[1] == 1)
		i++;
	return (i + width + suf_zero);
}

int	case_signed(t_flags flag, va_list args)
{
	long long	d;
	int			width;

	if ((flag.type & 0b111000) == 0b001000)
		d = (char)va_arg(args, int);
	else if ((flag.type & 0b111000) == 0b010000)
		d = (short)va_arg(args, int);
	else if ((flag.type & 0b111000) == 0b011000)
		d = va_arg(args, int);
	else if ((flag.type & 0b111000) == 0b100000)
		d = va_arg(args, long);
	else if ((flag.type & 0b111000) == 0b101000)
		d = va_arg(args, long long);
	if (flag.precision == 0 && d == 0)
	{
		flag.five_flags[1] = 0;
		return (case_string(flag, args, " "));
	}
	if (flag.precision != -1)
		flag.five_flags[1] = 0;
	width = count_digits(d, 10);
	return (case_signed_d(flag, d, width));
}
