/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkusama <tkusama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:59:08 by tkusama           #+#    #+#             */
/*   Updated: 2024/02/17 21:18:05 by tkusama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int validate_format(const char *str)
{
	int i = 0;
	int has_number = 0;
	while (str[i] != '\0') {
		if ('1' <= str[i] && str[i] <= '9')
		{
			if (has_number) {
				return (-1);
			}
			has_number = 1;
		} else if (str[i] == ' ')
		{
			if (!has_number)
				return (-1);
		}
			has_number = 0;
		} else
		{
			return (-1);
		}
		i++;
	}

	if (!has_number)
	{
		return (-1);
	}
	return (0);
}


