/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 22:29:48 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/27 22:29:49 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int		size;
	t_list	*now;

	if (begin_list == NULL)
		return (0);
	size = 0;
	now = begin_list;
	while (1)
	{
		size++;
		if (now->next == NULL)
			break ;
		now = now->next;
	}
	return (size);
}

/* #include "ft_list.h"
#include <stdio.h>
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

    // リストにいくつかの要素を追加
    ft_list_push_front(&list, "Element 3");
    ft_list_push_front(&list, "Element 2");
    ft_list_push_front(&list, "Element 1");

    // リストのサイズを計算して出力
    printf("List size: %d\n", ft_list_size(list));

    // メモリ解放は省略（実際には各要素とリスト全体のために適切なメモリ解放を行う必要があります）

    return 0;
} */
