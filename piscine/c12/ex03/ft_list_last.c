/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 22:39:48 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/27 22:39:49 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
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

/* #include <stdio.h>
#include <stdlib.h> // mallocのため

// ここにft_list_size関数を含める

t_list *ft_create_elem(void *data)
{
    t_list *new = malloc(sizeof(t_list));
    if (new)
    {
        new->data = data;
        new->next = NULL;
    }
    return new;
}

void ft_list_push_front(t_list **begin_list, void *data)
{
    t_list *new = ft_create_elem(data);
    if (new)
    {
        new->next = *begin_list;
        *begin_list = new;
    }
}

int main()
{
    t_list *list = NULL;
    t_list *last;

    // リストにいくつかの要素を追加
    ft_list_push_front(&list, "Element 3");
    ft_list_push_front(&list, "Element 2");
    ft_list_push_front(&list, "Element 1");

    // リストの最後の要素を取得
    last = ft_list_last(list);

    // 最後の要素のデータを出力
    if (last != NULL)
        printf("Last element data: %s\n", (char *)last->data);
    else
        printf("The list is empty.\n");

    // メモリ解放は省略（実際には各要素とリスト全体のために適切なメモリ解放を行う必要があります）

    return 0;
} */
