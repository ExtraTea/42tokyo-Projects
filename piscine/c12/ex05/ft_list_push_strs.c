/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 23:26:55 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/27 23:26:56 by dtakamat         ###   ########.fr       */
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

t_list	*ft_list_push_strs(int size, char**strs)
{
	int		index;
	t_list	*result;

	index = 0;
	result = NULL;
	while (index < size)
	{
		ft_list_push_front(&result, strs[index]);
		index++;
	}
	return (result);
}
/* 
#include <stdio.h>
int main() {
    char *strs[] = {"Hello", "World", "This", "Is", "A", "Test"};
    int size = sizeof(strs) / sizeof(strs[0]);

    t_list *list = ft_list_push_strs(size, strs);
    int index = 0;
    while (list != NULL) {
        printf("List node %d: %s\n", size - index, (char *)list->data);
        list = list->next;
        index++;
    }
    return 0;
} */
