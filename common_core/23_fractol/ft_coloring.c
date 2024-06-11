/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coloring.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:12:35 by dtakamat          #+#    #+#             */
/*   Updated: 2024/04/28 19:12:36 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	assign_color(double rgb_prime[3], double one, double two, double three)
{
	rgb_prime[0] = one;
	rgb_prime[1] = two;
	rgb_prime[2] = three;
}

int	hsv_to_rgb(double h, double s, double v)
{
	double	cxm[3];
	double	rgb_prime[3];
	int		rgb[3];

	cxm[0] = v * s;
	cxm[1] = cxm[0] * (1 - fabs(fmod(h / 60.0, 2) - 1));
	cxm[2] = v - cxm[0];
	if (h >= 0 && h < 60)
		assign_color(rgb_prime, cxm[0], cxm[1], 0);
	else if (h >= 60 && h < 120)
		assign_color(rgb_prime, cxm[1], cxm[0], 0);
	else if (h >= 120 && h < 180)
		assign_color(rgb_prime, 0, cxm[0], cxm[1]);
	else if (h >= 180 && h < 240)
		assign_color(rgb_prime, 0, cxm[1], cxm[0]);
	else if (h >= 240 && h < 300)
		assign_color(rgb_prime, cxm[1], 0, cxm[0]);
	else
		assign_color(rgb_prime, cxm[0], 0, cxm[1]);
	rgb[0] = (int)((rgb_prime[0] + cxm[2]) * 255);
	rgb[1] = (int)((rgb_prime[1] + cxm[2]) * 255);
	rgb[2] = (int)((rgb_prime[2] + cxm[2]) * 255);
	return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}

int	ft_get_color(int i, int num)
{
	double	hue;
	int		rgb;

	if (i == MAX_CALCULATION)
		return (0x00000000);
	hue = (double)i / MAX_CALCULATION * 360 + (double)num;
	while (hue > 360.0)
		hue -= 360.0;
	rgb = hsv_to_rgb(hue, 0.5, 1.0);
	return (rgb);
}
