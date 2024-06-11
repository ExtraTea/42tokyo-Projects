/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 22:13:34 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/27 22:13:35 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*newdata;

	newdata = ft_create_elem(data);
	newdata->next = *begin_list;
	*begin_list = newdata;
}

/* #include <stdio.h>
#include <stdlib.h>
void print_list(t_list *list)
{
    while (list != NULL)
    {
        printf("%s\n", (char *)list->data);
        list = list->next;
    }
}

int main(void)
{
    t_list *list = NULL;

    ft_list_push_front(&list, "World!");
    ft_list_push_front(&list, "Hello");
    print_list(list);
    return 0;
}
 */
