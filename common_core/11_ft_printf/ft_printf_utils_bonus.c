/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 22:06:23 by dtakamat          #+#    #+#             */
/*   Updated: 2024/04/18 13:12:51 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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
