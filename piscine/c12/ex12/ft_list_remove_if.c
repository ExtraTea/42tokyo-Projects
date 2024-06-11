/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:20:44 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/28 19:20:52 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref,
		int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*now;
	t_list	*tmp;

	while (*begin_list && (cmp)((*begin_list)->data, data_ref) == 0)
	{
		tmp = *begin_list;
		*begin_list = (*begin_list)->next;
		(free_fct)(tmp->data);
		free(tmp);
	}
	now = *begin_list;
	while (now != NULL && now->next != NULL)
	{
		if ((cmp)(now->next->data, data_ref) == 0)
		{
			tmp = now->next;
			(free_fct)(now->next->data);
			now->next = now->next->next;
			free(tmp);
		}
		else
			now = now->next;
	}
}
