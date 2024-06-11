/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:48:16 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/28 14:48:16 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach_if(t_list *begin_list,
		void (*f)(void *), void *data_ref, int (*cmp)())
{
	t_list	*now;

	if (begin_list == NULL)
		return ;
	now = begin_list;
	while (now != NULL)
	{
		if (cmp(now->data, data_ref) == 0)
			f(now->data);
		now = now->next;
	}
	return ;
}

/* 
#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>

t_list	*ft_create_elem(void *data) {
    t_list	*elem;

    elem = (t_list *)malloc(sizeof(t_list));
    if (!elem)
        return (NULL);
    elem->data = data;
    elem->next = NULL;
    return (elem);
}

void	double_value(void *data) {
    int *p = (int *)data;
    *p *= 2;
}

int	compare_integers(void *data1, void *data_ref) {
    return (*(int *)data1 - *(int *)data_ref);
}

int main(void) {
    t_list *list = NULL;
    int values[] = {1, 2, 3, 4, 2};
    int to_double = 2;

    for (int i = 0; i < 5; i++) {
        t_list *elem = ft_create_elem(&values[i]);
        elem->next = list;
        list = elem;
    }

    ft_list_foreach_if(list, double_value, &to_double, compare_integers);

    // 結果を表示
    for (t_list *tmp = list; tmp != NULL; tmp = tmp->next) {
        printf("%d ", *(int *)(tmp->data));
    }
    printf("\n");

    // ここでリストのメモリを解放する
    while (list != NULL) {
        t_list *next = list->next;
        free(list);
        list = next;
    }

    return 0;
} */
