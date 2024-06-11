/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:10:21 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/28 13:10:22 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	t_list			*now;
	unsigned int	i;

	if (begin_list == NULL)
		return (NULL);
	now = begin_list;
	i = 0;
	while (now != NULL)
	{
		if (i == nbr)
		{
			return (now);
		}
		now = now->next;
		i++;
	}
	return (NULL);
}

/* t_list	*ft_create_elem(void *data)
{
	t_list	*newdata;

	newdata = (t_list *)malloc(sizeof (t_list));
	newdata->data = data;
	newdata->next = NULL;
	return (newdata);
}

#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    t_list *list = NULL;
    t_list *elem;
    int data1 = 42;
    int data2 = 21;
    int data3 = 84;
    unsigned int nbr;

    // リストに要素を追加
    list = ft_create_elem(&data1);
    list->next = ft_create_elem(&data2);
    list->next->next = ft_create_elem(&data3);

    nbr = 0; // 最初の要素
    elem = ft_list_at(list, nbr);
    if (elem != NULL)
        printf("Element at pos %u has data: %d\n", nbr, *(int *)(elem->data));
    else
        printf("No element found at position %u\n", nbr);

    nbr = 1; // 2番目の要素
    elem = ft_list_at(list, nbr);
    if (elem != NULL)
        printf("Element at pos %u has data: %d\n", nbr, *(int *)(elem->data));
    else
        printf("No element found at position %u\n", nbr);

    nbr = 2; // 3番目の要素
    elem = ft_list_at(list, nbr);
    if (elem != NULL)
        printf("Element at pos %u has data: %d\n", nbr, *(int *)(elem->data));
    else
        printf("No element found at position %u\n", nbr);
    return 0;
} */
