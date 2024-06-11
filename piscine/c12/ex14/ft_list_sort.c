/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:59:59 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/28 17:00:02 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_split_list(t_list *source, t_list **front_ref, t_list **back_ref)
{
	t_list	*fast;
	t_list	*slow;

	slow = source;
	fast = source->next;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*front_ref = source;
	*back_ref = slow->next;
	slow->next = NULL;
}

t_list	*sorted_merge(t_list *a, t_list *b, int (*cmp)())
{
	t_list	*result;

	result = NULL;
	if (a == NULL)
		return (b);
	if (b == NULL)
		return (a);
	if (cmp(a->data, b->data) <= 0)
	{
		result = a;
		result->next = sorted_merge(a->next, b, cmp);
	}
	else
	{
		result = b;
		result->next = sorted_merge(a, b->next, cmp);
	}
	return (result);
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*head;
	t_list	*a;
	t_list	*b;

	head = *begin_list;
	if (head == NULL || head->next == NULL)
		return ;
	ft_split_list(head, &a, &b);
	ft_list_sort(&a, cmp);
	ft_list_sort(&b, cmp);
	*begin_list = sorted_merge(a, b, cmp);
}

/* #include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>

// ヘルパー関数: 新しいリストの要素を作成
t_list *ft_create_elem(void *data) {
    t_list *new_elem = (t_list *)malloc(sizeof(t_list));
    if (!new_elem) return NULL;
    new_elem->data = data;
    new_elem->next = NULL;
    return new_elem;
}

// ヘルパー関数: リストの内容を表示
void ft_print_list(t_list *list) {
    while (list) {
        printf("%d ", *(int *)list->data);
        list = list->next;
    }
    printf("\n");
}

// 比較関数: 整数を比較
int int_cmp(void *a, void *b) {
    return (*(int *)a - *(int *)b);
}

// メイン関数: テストケースを実行
int main() {
    t_list *list = NULL;
    int nums[] = {5,4,3,2,1};

    // リストの作成
    for (int i = 0; i < 5; i++) {
        t_list *new_elem = ft_create_elem(&nums[i]);
        new_elem->next = list;
        list = new_elem;
    }

    // ソート前のリストを表示
    printf("Before sorting: ");
    ft_print_list(list);

    // リストのソート
    ft_list_sort(&list, int_cmp);

    // ソート後のリストを表示
    printf("After sorting: ");
    ft_print_list(list);

    // メモリの解放 (省略)

    return 0;
} */
