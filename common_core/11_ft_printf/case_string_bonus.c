/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_string_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 22:06:21 by dtakamat          #+#    #+#             */
/*   Updated: 2024/04/18 13:12:37 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	case_string_print(t_flags flag, char *s)
{
	int	width;
	int	i;

	width = ft_strlen(s);
	if (flag.precision != -1)
		width = ft_min(flag.precision, width);
	flag.width = ft_max(width, flag.width);
	i = 0;
	if (flag.five_flags[0] == 0)
	{
		while (i++ < flag.width - width)
		{
			if (flag.five_flags[1] == 1)
				ft_putchar_fd('0', 1);
			else
				ft_putchar_fd(' ', 1);
		}
	}
	write(1, s, width);
	if (flag.five_flags[0] == 1)
		while (i++ < flag.width - width)
			ft_putchar_fd(' ', 1);
	return (width + i - 1);
}

int	case_string(t_flags flag, va_list *args, char *other_s)
{
	char		*s;
	const char	*s_null = "(null)";

	if (other_s == NULL)
		s = va_arg(*args, char *);
	else
		s = other_s;
	if (s == NULL)
	{
		if (flag.precision >= 0 || flag.precision == -1)
			s = (char *)s_null;
		else
			return (0);
	}
	return (case_string_print(flag, s));
}
