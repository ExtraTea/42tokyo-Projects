/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:52:42 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/25 14:52:43 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	key_exists(t_node *head, char *key)
{
	while (head != NULL)
	{
		if (ft_strcmp(head->kvp.key, key) == 0)
			return (1);
		head = head->next;
	}
	return (0);
}

t_node	*create_node(char *key, char *value)
{
	t_node	*newnode;

	newnode = (t_node *)malloc(sizeof (t_node));
	if (newnode == NULL)
		return (NULL);
	newnode->kvp.key = ft_strdup(key);
	newnode->kvp.value = ft_strdup(value);
	if (!newnode->kvp.key || !newnode->kvp.value)
	{
		free(newnode->kvp.key);
		free(newnode->kvp.value);
		free(newnode);
		return (NULL);
	}
	newnode ->next = NULL;
	return (newnode);
}

int	insert(t_node **head, char *key, char *value)
{
	t_node	*newnode;

	if (key_exists(*head, key))
		return (1);
	newnode = create_node(key, value);
	if (newnode == NULL)
		return (1);
	newnode->next = *head;
	*head = newnode;
	return (0);
}

char	*search(t_node *head, char *key)
{
	t_node	*current;

	current = head;
	while (current != NULL)
	{
		if (ft_strcmp(current->kvp.key, key) == 0)
			return (current->kvp.value);
		current = current->next;
	}
	return (NULL);
}

void	free_list(t_node **head)
{
	t_node	*current;
	t_node	*next;

	if (head == NULL || *head == NULL)
		return ;
	current = *head;
	while (current != NULL)
	{
		next = current->next;
		free(current->kvp.key);
		free(current->kvp.value);
		free(current);
		current = next;
	}
	*head = NULL;
}
