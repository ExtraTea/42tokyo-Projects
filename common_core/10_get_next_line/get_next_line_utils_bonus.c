/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 22:05:29 by dtakamat          #+#    #+#             */
/*   Updated: 2024/04/15 22:05:40 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_strlcpycat(char *dst, const char *src1,
		const char *src2, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < dstsize - 1 && src1[i] != 0)
	{
		dst[i] = src1[i];
		i++;
	}
	j = 0;
	while (src2[j] != 0 && i < dstsize - 1)
	{
		dst[i++] = src2[j++];
	}
	if (i < dstsize)
		dst[i] = 0;
}

void	*ft_mve(void *dest, const void *src, size_t n)
{
	uint8_t			*d;
	const uint8_t	*s;
	size_t			i;

	d = dest;
	s = src;
	if (d < s)
	{
		i = 0;
		while (i < n && ((const unsigned char *)src)[i] != 0)
		{
			d[i] = s[i];
			i++;
		}
		if (i != n)
			d[i] = s[i];
	}
	return (dest);
}
