/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:31:40 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/28 19:31:41 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*fftt_list_last(t_list *begin_list)
{
	t_list	*now;

	if (begin_list == NULL)
		return (NULL);
	now = begin_list;
	while (1)
	{
		if (now->next == NULL)
			return (now);
		now = now->next;
	}
	return (NULL);
}

void	fftt_split_list(t_list *source, t_list **front_ref, t_list **back_ref)
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

t_list	*fftt_sorted_merge(t_list *a, t_list *b, int (*cmp)())
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
		result->next = fftt_sorted_merge(a->next, b, cmp);
	}
	else
	{
		result = b;
		result->next = fftt_sorted_merge(a, b->next, cmp);
	}
	return (result);
}

void	fftt_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*head;
	t_list	*a;
	t_list	*b;

	head = *begin_list;
	if (head == NULL || head->next == NULL)
		return ;
	fftt_split_list(head, &a, &b);
	fftt_list_sort(&a, cmp);
	fftt_list_sort(&b, cmp);
	*begin_list = fftt_sorted_merge(a, b, cmp);
}

void	ft_sorted_list_merge(t_list **begin_list1
		, t_list *begin_list2, int (*cmp)())
{
	t_list	*end;

	if (*begin_list1 == NULL)
		*begin_list1 = begin_list2;
	else
	{
		end = fftt_list_last(*begin_list1);
		if (end != NULL)
			end->next = begin_list2;
	}
	fftt_list_sort(begin_list1, cmp);
}

/* #include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>
t_list	*ft_create_elem(void *data);
// 整数の比較関数
int int_cmp(void *a, void *b) {
    return (*(int*)a - *(int*)b);
}

// リストの要素を作成する関数
t_list *ft_create_elem(void *data) {
    t_list *elem = (t_list *)malloc(sizeof(t_list));
    if (!elem) return NULL;
    elem->data = data;
    elem->next = NULL;
    return elem;
}

// リストの内容を表示する関数
void print_list(t_list *list) {
    while (list != NULL) {
        printf("%d ", *(int *)(list->data));
        list = list->next;
    }
    printf("\n");
}

// メイン関数: ft_sorted_list_mergeのテスト
int main(void) {
    t_list *list1 = NULL;
    t_list *list2 = NULL;
    int nums1[] = {9, 7, 3};
    int nums2[] = {8, 4, 2};

    // list1の作成
    for (int i = 0; i < 3; i++) {
        t_list *new_elem = ft_create_elem(&nums1[i]);
        new_elem->next = list1;
        list1 = new_elem;
    }

    // list2の作成
    for (int i = 0; i < 3; i++) {
        t_list *new_elem = ft_create_elem(&nums2[i]);
        new_elem->next = list2;
        list2 = new_elem;
    }

    // マージとソート前のリストを表示
    printf("List 1 before merge: ");
    print_list(list1);
    printf("List 2 before merge: ");
    print_list(list2);

    // リストのマージとソート
    fftt_sorted_list_merge(&list1, list2, int_cmp);

    // マージとソート後のリストを表示
    printf("List 1 after merge and sort: ");
    print_list(list1);

    // メモリ解放（省略）
    
    return 0;
} */