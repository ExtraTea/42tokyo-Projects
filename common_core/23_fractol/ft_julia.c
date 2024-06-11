/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 16:40:43 by dtakamat          #+#    #+#             */
/*   Updated: 2024/04/28 19:13:51 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_julia_reccurence_real(double real, double imaginal, double c_dif)
{
	return (real * real - imaginal * imaginal + C_REAL + c_dif);
}

double	ft_julia_reccurence_imaginal(double real, double imaginal, double c_dif)
{
	return (2 * real * imaginal + C_IMAGINAL + c_dif);
}

int	ft_julia_calculate_divergence(double real, double imaginal)
{
	size_t	i;
	double	temp[2];

	i = 0;
	while (i < MAX_CALCULATION)
	{
		temp[0] = ft_julia_reccurence_real(real, imaginal, 0.0);
		temp[1] = ft_julia_reccurence_imaginal(real, imaginal, 0.0);
		if (temp[0] * temp[0] + temp[1] * temp[1] > 4)
			return (i);
		real = temp[0];
		imaginal = temp[1];
		i++;
	}
	return (i);
}

int	ft_julia_calculate_divergence2(double real, double imaginal)
{
	size_t	i;
	double	temp[2];

	i = 0;
	while (i < MAX_CALCULATION)
	{
		temp[0] = ft_julia_reccurence_real(real, imaginal, 0.15);
		temp[1] = ft_julia_reccurence_imaginal(real, imaginal, 0.24);
		if (temp[0] * temp[0] + temp[1] * temp[1] > 4)
			return (i);
		real = temp[0];
		imaginal = temp[1];
		i++;
	}
	return (i);
}
