/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 22:50:53 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/25 22:50:54 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_colon_not_one(char **entry)
{
	int	colon;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (entry[i] != 0)
	{
		colon = 0;
		j = 0;
		while (entry[i][j] != '\0')
		{
			if (entry[i][j] == ':')
				colon++;
			j++;
		}
		if (colon != 1)
			return (1);
		i++;
	}
	return (0);
}

void	ft_clean_value(char *value)
{
	char	*tmp;

	tmp = value;
	while (*value == ' ')
		value++;
	if (tmp == value)
		return ;
	while (*value)
	{
		*tmp = *value;
		tmp++;
		value++;
	}
	*tmp = '\0';
	return ;
}

char	*read_file(char *dictname)
{
	int		len_i_fd[3];
	char	*dict;

	len_i_fd[0] = count_file_len(dictname);
	dict = (char *)malloc(sizeof (char) * len_i_fd[0] + 1);
	if (dict == NULL)
		return (NULL);
	len_i_fd[2] = open(dictname, O_RDONLY);
	read(len_i_fd[2], dict, len_i_fd[0]);
	close(len_i_fd[2]);
	dict[len_i_fd[0]] = '\0';
	return (dict);
}

int	check_result2(char **result1)
{
	int		index;
	char	**result2;
	int		count;

	index = 0;
	count = 0;
	while (result1[index] != NULL)
	{
		result2 = ft_split(result1[index++], ":");
		ft_clean_value(result2[1]);
		if (ft_error_value(result2[1]))
			count++;
		strong_free(result2[0], result2[1], result2);
	}
	if (count > 0)
	{
		index = 0;
		while (result1[index] != NULL)
			free(result1[index++]);
		free(result1);
		return (1);
	}
	else
		return (0);
}
