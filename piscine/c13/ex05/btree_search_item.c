/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:07:18 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/29 13:07:19 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root
		, void *data_ref, int (*cmpf)(void *, void*))
{
	void	*found;

	if (root == NULL)
		return (NULL);
	found = btree_search_item(root->left, data_ref, cmpf);
	if (found != NULL)
		return (found);
	if (cmpf(root->item, data_ref) == 0)
		return (root->item);
	found = btree_search_item(root->right, data_ref, cmpf);
	if (found != NULL)
		return (found);
	return (NULL);
}

/* t_btree	*btree_create_node(void *item)
{
	t_btree	*result;

	result = (t_btree *)malloc(sizeof (t_btree));
	if (result == NULL)
		return (NULL);
	result->item = item;
	result->left = NULL;
	result->right = NULL;
	return (result);
}

void	btree_insert_data(t_btree **root
		, void *item, int (*cmpf)(void *, void *))
{
	if (*root == NULL)
	{
		*root = btree_create_node(item);
		return ;
	}
	if (cmpf((*root)->item, item) < 0)
		btree_insert_data(&((*root)->right), item, cmpf);
	else if (cmpf((*root)->item, item) >= 0)
		btree_insert_data(&((*root)->left), item, cmpf);
}

#include "ft_btree.h"
#include <stdio.h>

// 比較関数。整数を比較する。
int cmpf(void *item1, void *item2) {
    int i1 = *(int *)item1;
    int i2 = *(int *)item2;
    if (i1 < i2) return -1;
    else if (i1 == i2) return 0;
    else return 1;
}

// 整数を表示する関数
void print_int(void *item) {
    printf("%d\n", *(int *)item);
}

// 主なテスト関数
int main(void) {
    t_btree *root = NULL;
    int items[] = {42, 21, 45, 30, 50, 25, 75};
    int search_item = 42;
    void *found_item;

    // 二分木に整数を挿入
    for (int i = 0; i < 7; i++) {
        btree_insert_data(&root, &items[i], cmpf);
    }

    // 特定のアイテムを探索
    found_item = btree_search_item(root, &search_item, cmpf);

    // 結果を表示
    if (found_item != NULL) {
        printf("Item found: ");
        print_int(found_item);
    } else {
        printf("Item not found.\n");
    }

    return 0;
} */
