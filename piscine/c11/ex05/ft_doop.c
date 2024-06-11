/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:30:39 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/27 19:30:40 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_add(int a, int b);
int		ft_subtract(int a, int b);
int		ft_division(int a, int b);
int		ft_multiplication(int a, int b);
int		ft_remainder(int a, int b);
void	ft_putnbr(int nbr);
int		ft_atoi(char *str);
int		ft_strcmp(char *s1, char*s2);
int		ft_strlen(char *str);

void	calc(char *a, char *b, int (*f)(int, int))
{
	ft_putnbr(f(ft_atoi(a), ft_atoi(b)));
	write(1, "\n", 1);
}

int	val(char *c)
{
	if (ft_strlen(c) != 1)
		return (0);
	else if (c[0] == '+')
		return (1);
	else if (c[0] == '-')
		return (1);
	else if (c[0] == '*')
		return (1);
	else if (c[0] == '/')
		return (1);
	else if (c[0] == '%')
		return (1);
	else
		return (0);
}

int	sub(char **av)
{
	if (av[2][0] == '+')
		calc(av[1], av[3], ft_add);
	else if (av[2][0] == '-')
		calc(av[1], av[3], ft_subtract);
	else if (av[2][0] == '*')
		calc(av[1], av[3], ft_multiplication);
	else if (av[2][0] == '/')
	{
		if (ft_atoi(av[3]) == 0)
		{
			write(1, "Stop : division by zero\n", 24);
			return (1);
		}
		calc(av[1], av[3], ft_division);
	}
	else if (av[2][0] == '%')
	{
		if (ft_atoi(av[3]) == 0)
		{
			write(1, "Stop : moduro by zero\n", 22);
			return (1);
		}
		calc(av[1], av[3], ft_remainder);
	}
	return (0);
}

int	main(int ac, char **av)
{
	if (ac != 4)
		return (1);
	if (val(av[2]) == 0)
	{
		write(1, "0\n", 2);
		return (1);
	}
	sub(av);
}
