/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 22:06:24 by dtakamat          #+#    #+#             */
/*   Updated: 2024/04/18 13:12:55 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		ret;

	va_start(args, s);
	ret = vft_printf(s, &args);
	va_end(args);
	return (ret);
}

void	print_with_flag(t_flags *flag, va_list *args, int *count)
{
	va_list	arg_tmp;

	if (flag->width_location != -1)
	{
		va_copy(arg_tmp, *args);
		flag->width = get_width(flag->width_location, arg_tmp);
		va_arg(*args, int);
		va_end(arg_tmp);
	}
	if ((flag->type & 0b111) == 0b100)
		flag->type -= 1;
	if ((flag->type & 0b111) == 0b000)
		*count += case_char(*flag, args);
	else if ((flag->type & 0b111) == 0b001)
		*count += case_string(*flag, args, NULL);
	else if ((flag->type & 0b111) == 0b010)
		*count += case_pointer(*flag, args);
	else if ((flag->type & 0b100) == 0b100)
		*count += case_unsigned(*flag, args);
	else if ((flag->type & 0b111) == 0b011)
		*count += case_signed(*flag, args);
	else
		ft_putendl_fd("Not Implemented Error", 0);
}

void	error_with_par(const char **s, int *count)
{
	*count += write(1, "%", 1);
	(*s)++;
}

int	vft_printf(const char *s, va_list *args)
{
	t_flags	flag;
	int		count;

	count = 0;
	while (*s != 0)
	{
		if (*s != '%')
			count += write(1, s, 1);
		else if (*(s + 1) == '%')
			error_with_par(&s, &count);
		else
		{
			flag = get_format(s);
			if (flag.is_valid == 0)
			{
				error_with_par(&s, &count);
				continue ;
			}
			print_with_flag(&flag, args, &count);
			s += flag.count;
		}
		s++;
	}
	return (count);
}
