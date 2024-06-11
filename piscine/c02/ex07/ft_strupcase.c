/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:48:59 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/10 15:49:04 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	index;

	index = 0;
	while (str[index] != 0)
	{
		if ('a' <= str[index] && str[index] <= 'z')
			str[index] += ('A' - 'a');
		index++;
	}
	return (str);
}
