/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 23:10:55 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/27 23:10:56 by dtakamat         ###   ########.fr       */
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

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*last;
	t_list	*newdata;

	newdata = ft_create_elem (data);
	if (*begin_list == NULL)
		*begin_list = newdata;
	else
	{
		last = ft_list_last(*begin_list);
		last->next = newdata;
	}
}

/* #include <stdio.h>
#include <stdlib.h>

// ここにft_list_last, ft_create_elem, ft_list_push_back関数の定義を含める

int main() {
    t_list *list = NULL;

    // リストに要素を追加
    ft_list_push_back(&list, "Element 1");
    ft_list_push_back(&list, "Element 2");
    ft_list_push_back(&list, "Element 3");

    // リストを走査して要素を表示
    t_list *current = list;
    while (current != NULL) {
        printf("%s\n", (char *)current->data);
        current = current->next;
    }

    // メモリ解放は省略（実際には各要素とリスト全体のために適切なメモリ解放を行う必要があります）

    return 0;
} */
