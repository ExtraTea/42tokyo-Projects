/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:43:05 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/28 17:43:06 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

unsigned int	ft_list_size(t_list *begin_list)
{
	unsigned int	size;
	t_list			*now;

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

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	t_list			*now;
	unsigned int	i;

	if (begin_list == NULL)
		return (NULL);
	now = begin_list;
	i = 0;
	while (now != NULL)
	{
		if (i == nbr)
		{
			return (now);
		}
		now = now->next;
		i++;
	}
	return (NULL);
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	unsigned int	len;
	unsigned int	i;
	void			*tmp;

	len = ft_list_size(begin_list);
	i = 0;
	while (i < len / 2)
	{
		tmp = ft_list_at(begin_list, i)->data;
		(ft_list_at(begin_list
				, i)->data) = ft_list_at(begin_list, (len - i) - 1)->data;
		ft_list_at(begin_list, len - 1 - i)->data = tmp;
		i++;
	}
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

int main() {
    t_list *list = NULL;
    int nums[] = {1, 10, 3, 4, 5, 8};

    // リストの作成
    for (int i = 5; i >= 0; i--) {
        t_list *new_elem = ft_create_elem(&nums[i]);
        new_elem->next = list;
        list = new_elem;
    }

    // 逆転前のリストを表示
    printf("Before reversing:\n");
    ft_print_list(list);

    // リストの逆転
    ft_list_reverse_fun(list);

    // 逆転後のリストを表示
    printf("After reversing:\n");
    ft_print_list(list);

    // メモリの解放 (省略)

    return 0;
} */
