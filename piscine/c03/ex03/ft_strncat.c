/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:14:29 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/12 11:15:09 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	d_ind;
	unsigned int	src_ind;

	d_ind = 0;
	while (dest[d_ind] != '\0')
		d_ind++;
	src_ind = 0;
	while (src[src_ind] != '\0' && src_ind < nb)
	{
		dest[d_ind] = src[src_ind];
		d_ind++;
		src_ind++;
	}
	dest[d_ind] = '\0';
	return (dest);
}
