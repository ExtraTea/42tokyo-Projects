/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 21:49:06 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/28 21:49:07 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

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
