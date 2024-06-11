/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:52:27 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/25 14:52:29 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	count_digit(int num)
{
	int	len;

	len = 0;
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int num)
{
	int		len;
	char	*result;

	len = count_digit(num);
	result = (char *)malloc(sizeof (char *) * (len + 1));
	if (result == NULL)
		return (NULL);
	result[len--] = '\0';
	while (len >= 0)
	{
		result[len--] = num % 10 + '0';
		num /= 10;
	}
	return (result);
}
