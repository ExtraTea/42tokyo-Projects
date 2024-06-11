/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:10:58 by yyamasak          #+#    #+#             */
/*   Updated: 2024/02/18 14:11:00 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*small_box(char *str, int start, int end)
{
	int		size;
	char	*dep;
	int		i;

	i = 0;
	size = end - start;
	dep = (char *)malloc(sizeof(char) * (size + 1));
	while (i < size)
	{
		dep[i] = str[start + i];
		i++;
	}
	dep[i] = '\0';
	return (dep);
}

int	sepcmp(char str, char charset[])
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (str == charset[i])
			return (1);
		i++;
	}	
	return (0);
}

int	total_elements(char *str, char *charset)
{
	int	elements;
	int	i;
	int	flg;

	i = 0;
	flg = 0;
	elements = 0;
	while (str[i])
	{
		if (flg == 0 && !(sepcmp(str[i], charset)))
		{
			flg = 1;
			elements++;
		}
		else if (sepcmp(str[i], charset))
			flg = 0;
		i++;
	}
	return (elements);
}

void	assignment(char **dep, char *str, char *charset, int elm)
{
	int	comp[4];

	comp[0] = 0;
	comp[1] = 0;
	comp[2] = 0;
	comp[3] = 0;
	while (str[comp[0]])
	{
		if (comp[1] == 0 && !(sepcmp(str[comp[0]], charset)))
		{
			comp[1] = 1;
			comp[3] = comp[0];
		}
		else if ((comp[1] == 1) && sepcmp(str[comp[0]], charset))
		{
			comp[1] = 0;
			dep[comp[2]] = small_box(str, comp[3], comp[0]);
			comp[2]++;
		}
		comp[0]++;
	}
	if (comp[2] < elm)
		dep[comp[2]] = small_box(str, comp[3], comp[0]);
}

char	**ft_split(char *str, char *charset)
{
	int		elm;
	char	**dep;

	elm = total_elements(str, charset);
	dep = (char **)malloc(sizeof(char *) * (elm + 1));
	if (dep == NULL)
		return (NULL);
	assignment(dep, str, charset, elm);
	dep[elm] = 0;
	return (dep);
}
