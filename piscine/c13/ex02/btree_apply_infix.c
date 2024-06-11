/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_infix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 23:25:19 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/28 23:25:20 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_apply_infix(t_btree *root, void (*applyf)(void *))
{
	if (root == NULL)
		return ;
	btree_apply_infix(root->left, applyf);
	applyf(root->item);
	btree_apply_infix(root->right, applyf);
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
    int items[] = {4, 2, 6, 1, 3, 5, 7}; // ノードの値
    t_btree *root = btree_create_node(&items[0]);
    
    // 手動で木を構築
    root->left = btree_create_node(&items[1]);
    root->right = btree_create_node(&items[2]);
    root->left->left = btree_create_node(&items[3]);
    root->left->right = btree_create_node(&items[4]);
    root->right->left = btree_create_node(&items[5]);
    root->right->right = btree_create_node(&items[6]);

    // 中順走査の実行
    printf("Infix traversal: ");
    btree_apply_infix(root, print_int);
    printf("\n");

    // メモリ解放（省略）
    
    return 0;
} */
