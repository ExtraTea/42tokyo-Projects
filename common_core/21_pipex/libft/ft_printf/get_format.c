#include "ft_printf.h"

void	init_format(t_flags *flag, const char **temp, const char **s)
{
	int	j;

	j = 0;
	*temp = *s;
	(*s)++;
	flag->width = 0;
	flag->precision = -1;
	flag->type = 0;
	flag->is_valid = 1;
	flag->width_location = -1;
	while (j < 5)
		flag->five_flags[j++] = 0;
}

void	get_format_flags(t_flags *ret, const char **s)
{
	char		*result;
	const char	*fset = "-0# +";

	while (**s != 0)
	{
		result = ft_strchr(fset, (int)(**s));
		if (result != NULL)
			ret->five_flags[(uint64_t)result - (uint64_t)fset] = 1;
		else
			break ;
		(*s)++;
	}
}

void	get_format_width_precision(t_flags *ret, const char **s)
{
	if (ft_isdigit(**s))
	{
		ret->width = 0;
		while (ft_isdigit(**s))
		{
			ret->width = ret->width * 10 + (**s - '0');
			(*s)++;
		}
	}
	else if (**s == '*')
	{
		s++;
		ret->width_location = 1;
	}
	if (**s == '.')
	{
		(*s)++;
		ret->precision = 0;
		while (ft_isdigit(**s))
		{
			ret->precision = ret->precision * 10 + (**s - '0');
			(*s)++;
		}
	}
}

void	get_format_length(t_flags *ret, const char **s)
{
	if (**s == 'h')
	{
		(*s)++;
		if (**s == 'h')
		{
			ret->type += 0b001000;
			(*s)++;
		}
		else
			ret->type += 0b010000;
	}
	else if (**s == 'l')
	{
		(*s)++;
		if (**s == 'l')
		{
			ret->type += 0b100000;
			(*s)++;
		}
		else
			ret->type += 0b101000;
	}
	else
		ret->type += 0b011000;
}

t_flags	get_format(const char *s)
{
	t_flags		ret;
	char		*result;
	const char	cset[] = "cspdiuxX";
	const char	*temp;

	init_format(&ret, &temp, &s);
	get_format_flags(&ret, &s);
	get_format_width_precision(&ret, &s);
	get_format_length(&ret, &s);
	result = ft_strchr(cset, (int)*s);
	if (result != NULL)
		ret.type += (int)((uint64_t)result - (uint64_t)cset);
	else
	{
		ret.is_valid = 0;
		return (ret);
	}
	ret.count = (int)((uint64_t)s - (uint64_t)temp);
	return (ret);
}
