/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmachida <mmachida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 10:16:37 by mmachida          #+#    #+#             */
/*   Updated: 2024/02/25 16:02:12 by mmachida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_atoa(char *str, int start, int end)
{
	char	*ret;
	int		i;
	int		j;

	ret = (char *)malloc(sizeof(char) * (end - start + 1));
	i = start;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i++;
	j = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if ((str[i] == '-')
			&& ('0' <= str[i + 1] && str[i + 1] <= '9'))
			ret[j++] = '-';
		i++;
	}
	while ('0' == str[i])
		i++;
	while ('0' <= str[i] && str[i] <= '9' && i < end)
		ret[j++] = str[i++];
	if (j == 0)
		ret[j++] = '0';
	ret[j] = '\0';
	free(str);
	return (ret);
}
