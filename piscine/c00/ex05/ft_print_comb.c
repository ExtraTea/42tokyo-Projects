/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:12:56 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/07 20:26:05 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	int		digits[3];
	int		num;
	char	s[3];

	digits[0] = 2;
	digits[1] = 1;
	digits[2] = 0;
	while (digits[2] * 100 + digits[1] * 10 + digits[0] <= 789)
	{	
		if (digits[2] < digits[1] && digits[1] < digits[0])
		{
			s[2] = digits[0] + '0';
			s[1] = digits[1] + '0';
			s[0] = digits[2] + '0';
			write(1, s, 3);
			if (digits[2] * 100 + digits[1] * 10 + digits[0] != 789)
			{
				write(1, ", ", 2);
			}
		}
		num = digits[2] * 100 + digits[1] * 10 + digits[0] + 1;
		digits[0] = num % 10;
		digits[1] = (num % 100 - digits[0]) / 10;
		digits[2] = (num - digits[0] - digits[1]) / 100;
	}
}
