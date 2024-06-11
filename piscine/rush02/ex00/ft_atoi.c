/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:28:43 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/13 12:20:54 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	index;
	int	sign;
	int	num;

	index = 0;
	sign = 1;
	num = 0;
	while (str[index] == ' ' || (9 <= str[index] && str[index] <= 13))
		index++;
	while (str[index] == '+' || str[index] == '-')
	{
		if (str[index] == '-')
			sign *= -1;
		index++;
	}
	while ('0' <= str[index] && str[index] <= '9')
	{
		num *= 10;
		num += sign * (str[index] - '0');
		index++;
	}
	return (num);
}
