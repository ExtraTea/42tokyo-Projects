/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:39:27 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/28 13:39:28 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*now;
	t_list	*temp;
	t_list	*temp2;

	if (*begin_list == NULL)
		return ;
	now = *begin_list;
	temp = now->next;
	now->next = NULL;
	while (now != NULL)
	{
		temp2 = now;
		now = temp;
		if (now == NULL)
			break ;
		temp = temp->next;
		now->next = temp2;
	}
	*begin_list = temp2;
	return ;
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

// ft_create_elemとft_list_reverseは前述の通りです。

int main(void) {
    t_list *list = NULL;
    int data1 = 1;
    int data2 = 2;
    int data3 = 3;

    // リストに要素を追加
    list = ft_create_elem(&data1);
    list->next = ft_create_elem(&data2);
    list->next->next = ft_create_elem(&data3);

    // リストの逆転前の要素を表示
    printf("Before reverse:\n");
    for (t_list *iter = list; iter != NULL; iter = iter->next) {
        printf("%d ", *(int *)(iter->data));
    }
    printf("\n");

    // リストの逆転
    ft_list_reverse(&list);

    // リストの逆転後の要素を表示
    printf("After reverse:\n");
    for (t_list *iter = list; iter != NULL; iter = iter->next) {
        printf("%d ", *(int *)(iter->data));
    }
    printf("\n");
    return 0;
} */
