/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:53:22 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/25 14:53:24 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	write_all(char *num, t_node *head)
{
	int	len;

	if (ft_strcmp(num, "0") == 0)
	{
		write(1, search(head, "0"), ft_strlen(search(head, "0")));
		write(1, "\n", 1);
		return ;
	}
	len = ft_strlen(num);
	write_rec(num, len, head, 1);
	write(1, "\n", 1);
}
