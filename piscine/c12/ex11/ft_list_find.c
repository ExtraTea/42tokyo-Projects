/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:58:39 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/28 14:58:40 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	t_list	*now;

	if (begin_list == NULL)
		return (NULL);
	now = begin_list;
	while (now != NULL)
	{
		if (cmp(data_ref, now->data) == 0)
			return (now);
		now = now->next;
	}
	return (NULL);
}

/* #include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>

t_list *ft_create_elem(void *data) {
    t_list *new_elem = (t_list *)malloc(sizeof(t_list));
    if (new_elem) {
        new_elem->data = data;
        new_elem->next = NULL;
    }
    return new_elem;
}

// 整数を比較する関数
int compare_int(void *data1, void *data2) {
    return (*(int *)data1 - *(int *)data2);
}

int main() {
    t_list *list = NULL;
    int data[] = {10, 20, 30, 40, 50};
    int find = 30; // この値をリスト内で検索します
    t_list *found;

    // リストの作成
    for (int i = 4; i >= 0; i--) {
        t_list *new_elem = ft_create_elem(&data[i]);
        new_elem->next = list;
        list = new_elem;
    }

    // ft_list_find を使用して値を検索
    found = ft_list_find(list, &find, compare_int);

    if (found) {
        printf("Found: %d\n", *(int *)(found->data));
    } else {
        printf("Not found.\n");
    }

    // メモリ解放（この例では省略）

    return 0;
} */
