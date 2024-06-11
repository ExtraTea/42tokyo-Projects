/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:48:09 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/28 18:59:00 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*newdata;
	t_list	*now;

	newdata = ft_create_elem(data);
	now = *begin_list;
	if (*begin_list == NULL || cmp(now->data, newdata->data) > 0)
	{
		newdata->next = now;
		*begin_list = newdata;
		return ;
	}
	while (now->next != NULL && cmp(now->next->data, data) < 0)
	{
		now = now->next;
	}
	newdata->next = now->next;
	now->next = newdata;
}

/* #include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>

// 整数を比較する関数
int cmp(void *a, void *b) {
    int *ia = (int *)a;
    int *ib = (int *)b;
    return (*ia - *ib);
}

// リストの内容を表示する関数
void print_list(t_list *list) {
    while (list != NULL) {
        printf("%d ", *(int *)list->data);
        list = list->next;
    }
    printf("\n");
}

int main() {
    t_list *list = NULL;
    int vals[] = {5, 3, 9, 1, 40, 6, 10, 3, 4, 5 , 50}; // テストデータ
    int n = sizeof(vals) / sizeof(vals[0]);

    // テストデータをリストに挿入
    for (int i = 0; i < n; i++) {
        ft_sorted_list_insert(&list, &vals[i], cmp);
    }

    // ソートされたリストを表示
    printf("Sorted list: ");
    print_list(list);

    // メモリ解放（この例では省略）

    return 0;
} */
