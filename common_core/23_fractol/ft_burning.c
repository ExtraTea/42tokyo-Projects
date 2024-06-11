/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_burning.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 16:23:21 by dtakamat          #+#    #+#             */
/*   Updated: 2024/04/28 18:49:09 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_burning_reccurence_real(double real, double imaginal, double c_real)
{
	return (real * real - imaginal * imaginal + c_real);
}

double	ft_burning_reccurence_imaginal(double real,
		double imaginal, double c_imaginal)
{
	return (2 * sqrt(real * real) * sqrt(imaginal * imaginal) + c_imaginal);
}

int	ft_burning_calculate_divergence(double real, double imaginal)
{
	size_t	i;
	double	temp[3];

	i = 0;
	temp[0] = 0;
	temp[1] = 0;
	while (i < MAX_CALCULATION)
	{
		temp[2] = ft_burning_reccurence_real(temp[0], temp[1], real);
		temp[1] = ft_burning_reccurence_imaginal(temp[0], temp[1], imaginal);
		temp[0] = temp[2];
		if (temp[0] * temp[0] + temp[1] * temp[1] > 4)
			return (i);
		i++;
	}
	return (i);
}
