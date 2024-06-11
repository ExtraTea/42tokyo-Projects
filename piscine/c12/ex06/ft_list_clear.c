/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:08:38 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/28 13:08:39 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*now;
	t_list	*tmp;

	if (begin_list == NULL)
		return ;
	now = begin_list;
	while (now != NULL)
	{
		free_fct(now->data);
		tmp = now->next;
		free(now);
		now = tmp;
	}
}
