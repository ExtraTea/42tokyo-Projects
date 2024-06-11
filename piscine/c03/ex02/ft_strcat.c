/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:02:42 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/12 17:55:28 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	index;
	int	srcindex;

	index = 0;
	while (dest[index] != '\0')
		index++;
	srcindex = 0;
	while (src[srcindex] != '\0')
	{
		dest[index] = src[srcindex];
		index++;
		srcindex++;
	}
	dest[index] = '\0';
	return (dest);
}
