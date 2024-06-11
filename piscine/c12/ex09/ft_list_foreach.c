/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:50:25 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/28 13:50:25 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list	*now;

	if (begin_list == NULL)
		return ;
	now = begin_list;
	while (now != NULL)
	{
		f(now->data);
		now = now->next;
	}
	return ;
}

/* #include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>

// リストの新しい要素を作成
t_list *ft_create_elem(void *data) {
    t_list *new_elem = malloc(sizeof(t_list));
    if (!new_elem) return NULL;
    new_elem->data = data;
    new_elem->next = NULL;
    return new_elem;
}

// 整数データを2倍にする関数
void double_value(void *data) {
    int *p = (int *)data;
    *p *= 2;
}

int main(void) {
    t_list *list = NULL;
    int data1 = 1;
    int data2 = 2;
    int data3 = 3;

    // リストに要素を追加
    list = ft_create_elem(&data1);
    list->next = ft_create_elem(&data2);
    list->next->next = ft_create_elem(&data3);

    // 2倍にする前のリストを表示
    printf("Before doubling:\n");
    for (t_list *iter = list; iter != NULL; iter = iter->next) {
        printf("%d ", *(int *)(iter->data));
    }
    printf("\n");

    // リストの各要素を2倍にする
    ft_list_foreach(list, double_value);

    // 2倍にした後のリストを表示
    printf("After doubling:\n");
    for (t_list *iter = list; iter != NULL; iter = iter->next) {
        printf("%d ", *(int *)(iter->data));
    }
    printf("\n");

    // リストのメモリを解放（省略）

    return 0;
} */
