/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:10:50 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/29 17:10:51 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	enqueue(t_queue *queue, t_btree *node, int level)
{
	t_queue_node	*new_node;

	new_node = (t_queue_node *)malloc(sizeof (t_queue_node));
	new_node->node = node;
	new_node->level = level;
	new_node->next = NULL;
	if (queue->rear == NULL)
	{
		queue->front = new_node;
		queue->rear = new_node;
	}
	else
	{
		queue->rear->next = new_node;
		queue->rear = new_node;
	}
}

t_queue_node	*dequeue(t_queue *queue)
{
	t_queue_node	*tmp;

	if (queue->front == NULL)
		return (NULL);
	tmp = queue->front;
	queue->front = queue->front->next;
	if (queue->front == NULL)
		queue->rear = NULL;
	return (tmp);
}

void	init_queue(t_queue *queue)
{
	queue->front = NULL;
	queue->rear = NULL;
}

void	btree_apply_by_level(t_btree *root,
		void (*applyf)(void *item, int current_level, int is_first_elem))
{
	t_queue			queue;
	t_queue_node	*node;
	int				current_level;
	int				is_first_elem;

	init_queue(&queue);
	enqueue(&queue, root, 0);
	current_level = -1;
	is_first_elem = 1;
	while (queue.front != NULL)
	{
		node = dequeue(&queue);
		if (node->node->left != NULL)
			enqueue(&queue, node->node->left, node->level + 1);
		if (node->node->right != NULL)
			enqueue(&queue, node->node->right, node->level + 1);
		if (node->level != current_level)
		{
			current_level = node->level;
			is_first_elem = 1;
		}
		else
			is_first_elem = 0;
		applyf(node->node->item, node->level, is_first_elem);
	}
}

/* #include <stdio.h>
#include <stdlib.h>
void print_node(void *item, int current_level, int is_first_elem) {
    printf("Item: %d, Level: %d, Is first elem: %s\n", *(int*)item,
	 current_level, is_first_elem ? "Yes" : "No");
}

t_btree *btree_create_node(void *item) {
    t_btree *node = malloc(sizeof(t_btree));
    if (!node) return NULL;
    node->item = item;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main() {
    t_btree *root = btree_create_node((void*)&(int){42});
    root->left = btree_create_node((void*)&(int){21});
    root->right = btree_create_node((void*)&(int){105});
    root->left->left = btree_create_node((void*)&(int){11});
    root->left->right = btree_create_node((void*)&(int){32});
    root->right->left = btree_create_node((void*)&(int){90});
	root->right->right = btree_create_node((void*)&(int){80});
	root->left->left->left = btree_create_node((void*)&(int){10});
    root->left->left->right = btree_create_node((void*)&(int){25});
    root->right->right->left = btree_create_node((void*)&(int){75});
    root->right->right->right = btree_create_node((void*)&(int){90});
	root->right->right->right->right = btree_create_node((void*)&(int){130});

    btree_apply_by_level(root, print_node);

    return 0;
} */
