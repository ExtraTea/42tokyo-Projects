/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_pointer_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 22:06:19 by dtakamat          #+#    #+#             */
/*   Updated: 2024/04/18 13:14:45 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

#include "libft.h"

void	putnbr_hexd(unsigned long long n, char large_first,
		char plmi, int suf_zero)
{
	const char	lib16[] = "0123456789abcdef";
	const char	lib16l[] = "0123456789ABCDEF";

	if ((large_first & 0b01) == 1)
	{
		if (plmi == 1)
			write(1, " ", 1);
		else if (plmi >= 2)
			write(1, "+", 1);
		if ((large_first & 0b10) == 0b00)
			write(1, "0x", 2);
		else
			write(1, "0X", 2);
	}
	while (suf_zero-- > 0)
		ft_putchar_fd('0', 1);
	if (n >= 16)
		putnbr_hexd(n / 16, large_first & 0b10, 0, 0);
	if ((large_first & 0b10) == 0b00)
		write(1, &lib16[n % 16], 1);
	else
		write(1, &lib16l[n % 16], 1);
	return ;
}

int	case_pointer(t_flags flag, va_list *args)
{
	uintptr_t	p;
	int			i;
	int			width;

	p = (uintptr_t)va_arg(*args, void *);
	width = count_digits_u(p, 16) + 2;
	if (flag.five_flags[3] == 1 || flag.five_flags[4] == 1)
		width++;
	flag.width = ft_max(width, flag.width);
	i = 0;
	if (flag.five_flags[0] == 0)
		while (i++ < flag.width - width)
			ft_putchar_fd(' ', 1);
	putnbr_hexd(p, 0b01, flag.five_flags[3] + flag.five_flags[2] * 2, 0);
	if (flag.five_flags[0] == 1)
		while (i++ < flag.width - width)
			ft_putchar_fd(' ', 1);
	return (i + width - 1);
}
