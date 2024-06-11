/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:28:38 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/29 11:28:40 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_insert_data(t_btree **root
		, void *item, int (*cmpf)(void *, void *))
{
	if (*root == NULL)
	{
		*root = btree_create_node(item);
		return ;
	}
	if (cmpf(item, (*root)->item) < 0)
		btree_insert_data(&((*root)->left), item, cmpf);
	else
		btree_insert_data(&((*root)->right), item, cmpf);
}

/* #include "ft_btree.h"
#include <stdio.h>

t_btree	*btree_create_node(void *item)
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

// 比較関数
int cmpf(void *item1, void *item2) {
    return (*(int *)item1 - *(int *)item2);
}

// 二分木を前順（preorder）で走査し、要素を表示
void btree_apply_preorder(t_btree *root, void (*applyf)(void *)) {
    if (root) {
        applyf(root->item);
        btree_apply_preorder(root->left, applyf);
        btree_apply_preorder(root->right, applyf);
    }
}

// 整数を表示する関数
void print_int(void *item) {
    printf("%d ", *(int *)item);
}

int main(void) {
    t_btree *root = NULL;
    int items[] = {42, 21, 21, 50, 21, 75, 42}; // 二分木に挿入する整数

    // 二分木に整数を挿入
    for (unsigned long i = 0; i < sizeof(items)/sizeof(*items); i++) {
        btree_insert_data(&root, &items[i], cmpf);
    }

    // 二分木を前順で走査し、要素を表示
    printf("Preorder traversal: ");
    btree_apply_preorder(root, print_int);
    printf("\n");

    return 0;
}
 */