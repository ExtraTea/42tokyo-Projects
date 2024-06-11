/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:21:27 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/28 19:21:28 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
{
	t_list	*now;

	if (begin_list == NULL)
		return (NULL);
	now = begin_list;
	while (1)
	{
		if (now->next == NULL)
			return (now);
		now = now->next;
	}
	return (NULL);
}

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*end;

	if (*begin_list1 == NULL)
		*begin_list1 = begin_list2;
	else
	{
		end = ft_list_last(*begin_list1);
		if (end != NULL)
			end->next = begin_list2;
	}
}
