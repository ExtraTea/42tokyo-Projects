/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_prefix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 23:20:58 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/28 23:20:59 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
	if (root == NULL)
		return ;
	applyf(root->item);
	btree_apply_prefix(root->left, applyf);
	btree_apply_prefix(root->right, applyf);
}

/* #include "ft_btree.h"
#include <stdio.h>
#include <stdlib.h>

// ノードの値を印刷する関数
void print_int(void *item)
{
    printf("%d ", *(int *)item);
}

// ノードを作成する関数
t_btree *btree_create_node(void *item)
{
    t_btree *node = (t_btree *)malloc(sizeof(t_btree));
    if (node)
    {
        node->item = item;
        node->left = NULL;
        node->right = NULL;
    }
    return node;
}

int main(void)
{
    // 二分木の作成
    int items[] = {1, 2, 3, 4, 5}; // ノードの値
    t_btree *root = btree_create_node(&items[0]);
    root->left = btree_create_node(&items[1]);
    root->right = btree_create_node(&items[2]);
    root->left->left = btree_create_node(&items[3]);
    root->left->right = btree_create_node(&items[4]);

    // 前順走査の実行
    printf("Prefix traversal: ");
    btree_apply_prefix(root, print_int);
    printf("\n");

    // メモリ解放（ここでは省略されていますが、実際の使用では必要です）

    return 0;
} */
