/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_util2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:52:48 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/25 14:52:49 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	strong_free(char *a, char *b, char **c)
{
	free(a);
	free(b);
	free(c);
}

t_node	*strong_deep_free(char **a, t_node *head)
{
	int	index;

	index = 0;
	while (a[index] != NULL)
		free(a[index++]);
	free(a);
	return (head);
}

t_node	*parse_and_insert(char *data)
{
	char	**result1;
	char	**result2;
	int		len_i_fd[3];
	t_node	*head;

	head = NULL;
	result1 = ft_split(data, "\n");
	if (ft_colon_not_one(result1))
		return (NULL);
	len_i_fd[1] = 0;
	if (check_result2(result1) == 1)
		return (NULL);
	while (result1[len_i_fd[1]] != NULL)
	{
		result2 = ft_split(result1[len_i_fd[1]++], ":");
		ft_clean_value(result2[1]);
		result2[0] = ft_atoa(result2[0], 0, ft_strlen(result2[0]));
		len_i_fd[2] = insert(&head, result2[0], result2[1]);
		strong_free(result2[0], result2[1], result2);
		if (len_i_fd[2] == 1)
			return (strong_deep_free(result1, head));
	}
	strong_deep_free(result1, head);
	return (head);
}

t_node	*read_n_insert(char *dictname)
{
	char	*dict;
	t_node	*head;

	dict = read_file(dictname);
	if (!dict)
		return (NULL);
	head = parse_and_insert(dict);
	if (head == NULL)
	{
		free (dict);
		return (NULL);
	}
	free (dict);
	return (head);
}
