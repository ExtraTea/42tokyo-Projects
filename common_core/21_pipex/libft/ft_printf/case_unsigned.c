#include "ft_printf.h"

int	case_unsigned_u(t_flags flag, unsigned long long u)
{
	int	width;
	int	i;
	int	suf_zero;

	width = count_digits_u(u, 10);
	suf_zero = ft_max(flag.precision - width, 0);
	if (flag.five_flags[3] == 1 || flag.five_flags[4] == 1)
		width ++;
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
	ft_putllunbr(u, 1, flag.five_flags[3] + flag.five_flags[4] * 2, suf_zero);
	if (flag.five_flags[0] == 1)
		while (++i < flag.width - width - suf_zero)
			ft_putchar_fd(' ', 1);
	if (flag.five_flags[1] == 1)
		i++;
	return (i + width + suf_zero);
}

void	ftpd(unsigned long long n, char large_first, char plmi, int suf_zero)
{
	putnbr_hexd(n, large_first, plmi, suf_zero);
}

int	case_unsigned_x(t_flags f, unsigned long long u, char x, int width)
{
	int	i;
	int	s0;

	s0 = ft_max(f.precision - width, 0);
	if (f.five_flags[3] == 1 || f.five_flags[4] == 1)
		width ++;
	if (f.five_flags[2] == 1)
		width += 2;
	f.width = ft_max(width, f.width);
	i = -1;
	if (f.five_flags[0] == 0)
	{
		if (f.five_flags[1] == 1)
			s0 += f.width - width;
		else
			while (++i < f.width - width - s0)
				ft_putchar_fd(' ', 1);
	}
	ftpd(u, x + f.five_flags[2], f.five_flags[3] + f.five_flags[4] * 2, s0);
	if (f.five_flags[0] == 1)
		while (++i < f.width - width - s0)
			ft_putchar_fd(' ', 1);
	if (f.five_flags[1] == 1)
		i++;
	return (i + width + s0);
}

void	case_unsigned_flagmod(t_flags *flag, unsigned long long u)
{
	if (flag->precision != -1)
		flag->five_flags[1] = 0;
	if (u == 0)
		flag->five_flags[2] = 0;
}

int	case_unsigned(t_flags flag, va_list args)
{
	unsigned long long	u;

	if ((flag.type & 0b111000) == 0b001000)
		u = (unsigned char)va_arg(args, unsigned int);
	else if ((flag.type & 0b111000) == 0b010000)
		u = (unsigned short)va_arg(args, unsigned int);
	else if ((flag.type & 0b111000) == 0b011000)
		u = (unsigned int)va_arg(args, unsigned int);
	else if ((flag.type & 0b111000) == 0b100000)
		u = va_arg(args, unsigned long);
	else if ((flag.type & 0b111000) == 0b101000)
		u = va_arg(args, unsigned long long);
	if (flag.precision == 0 && u == 0)
	{
		flag.five_flags[1] = 0;
		return (case_string(flag, args, " "));
	}
	case_unsigned_flagmod(&flag, u);
	if ((flag.type & 0b111) == 0b101)
		return (case_unsigned_u(flag, u));
	else if ((flag.type & 0b111) == 0b110)
		return (case_unsigned_x(flag, u, 0, count_digits_u(u, 16)));
	else
		return (case_unsigned_x(flag, u, 2, count_digits_u(u, 16)));
}
