/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:30:09 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/29 17:30:10 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

int	btree_level_count(t_btree *root)
{
	if (root == NULL)
		return (0);
	return (ft_max(btree_level_count(root->left) + 1
			, btree_level_count(root->right) + 1));
}

/* #include "ft_btree.h"
#include <stdio.h>
#include <stdlib.h>

// 以前定義された ft_max 関数と btree_level_count 関数をここに含める

t_btree *btree_create_node(void *item) {
    t_btree *node = malloc(sizeof(t_btree));
    if (node) {
        node->item = item;
        node->left = NULL;
        node->right = NULL;
    }
    return node;
}

void btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *)) {
    if (*root == NULL) {
        *root = btree_create_node(item);
    } else if (cmpf((*root)->item, item) > 0) {
        btree_insert_data(&((*root)->left), item, cmpf);
    } else {
        btree_insert_data(&((*root)->right), item, cmpf);
    }
}

int cmp_int(void *a, void *b) {
    return (*(int *)a - *(int *)b);
}

void test_tree(t_btree *root) {
    printf("Tree level count: %d\n", btree_level_count(root));
}

int main() {
    t_btree *root = NULL;

    // 空の木
    printf("Test empty tree:\n");
    test_tree(root);

    // 単一ノードのみの木
    printf("Test single node tree:\n");
    int value1 = 42;
    root = btree_create_node(&value1);
    test_tree(root);

    // 左に偏った木
    printf("Test left-skewed tree:\n");
    int value2 = 21;
    btree_insert_data(&root, &value2, cmp_int);
    int value3 = 10;
    btree_insert_data(&root, &value3, cmp_int);
    test_tree(root);

    // 右に偏った木
    printf("Test right-skewed tree:\n");
    int value4 = 84;
    btree_insert_data(&root, &value4, cmp_int);
    int value5 = 105;
    btree_insert_data(&root, &value5, cmp_int);
    test_tree(root);

    // より複雑な構造を持つ木
    printf("Test more complex tree:\n");
    int values[] = {30, 15, 60, 45, 75, 55};
    for (int i = 0; i < 6; i++) {
        btree_insert_data(&root, &values[i], cmp_int);
    }
    test_tree(root);

    // ここで木を解放する処理が必要ですが、解放のための関数は省略されています

    return 0;
} */