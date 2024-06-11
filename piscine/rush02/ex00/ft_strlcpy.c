/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:05:32 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/10 15:05:36 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str);

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	index;

	index = 0;
	while (src[index] != '\0' && index < size -1)
	{
		dest[index] = src[index];
		index++;
	}
	if (src[index] == '\0')
		dest[index] = '\0';
	else if (index == size - 1)
		dest[index] = '\0';
	return (ft_strlen(src));
}
