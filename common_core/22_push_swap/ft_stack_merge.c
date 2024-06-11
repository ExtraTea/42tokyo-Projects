/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_merge.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinkpad-wsl <thinkpad-wsl@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 19:54:36 by dtakamat          #+#    #+#             */
/*   Updated: 2024/05/06 19:32:40 by thinkpad-ws      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_util_write_free(char *str, char **prev_str)
{
	if (str != NULL)
		write(1, str, ft_strlen(str));
	free(*prev_str);
	*prev_str = NULL;
}

void	ft_stack_print_merge_4(char **str, char **prev_str)
{
	if (ft_strncmp(*prev_str, "rrb\n", 5) == 0
		&& ft_strncmp(*str, "rb\n", 4) == 0)
		ft_util_write_free(NULL, prev_str);
	else if (ft_strncmp(*prev_str, "rra\n", 5) == 0
		&& ft_strncmp(*str, "rrb\n", 5) == 0)
		ft_util_write_free("rrr\n", prev_str);
	else if (ft_strncmp(*prev_str, "rrb\n", 5) == 0
		&& ft_strncmp(*str, "rra\n", 5) == 0)
		ft_util_write_free("rrr\n", prev_str);
	else
	{
		write(1, *prev_str, ft_strlen(*prev_str));
		free(*prev_str);
		*prev_str = ft_strdup(*str);
		if (*prev_str == NULL)
			exit(-1);
	}
}

void	ft_stack_print_merge_3(char **str, char **prev_str)
{
	if (ft_strncmp(*prev_str, "rb\n", 4) == 0
		&& ft_strncmp(*str, "ra\n", 4) == 0)
		ft_util_write_free("rr\n", prev_str);
	else if (ft_strncmp(*prev_str, "ra\n", 4) == 0
		&& ft_strncmp(*str, "rra\n", 5) == 0)
		ft_util_write_free(NULL, prev_str);
	else if (ft_strncmp(*prev_str, "rra", 4) == 0
		&& ft_strncmp(*str, "ra\n", 4) == 0)
		ft_util_write_free(NULL, prev_str);
	else if (ft_strncmp(*prev_str, "rb\n", 4) == 0
		&& ft_strncmp(*str, "rrb\n", 5) == 0)
		ft_util_write_free(NULL, prev_str);
	else
		ft_stack_print_merge_4(str, prev_str);
}

void	ft_stack_print_merge_2(char **str, char **prev_str)
{
	if (ft_strncmp(*prev_str, "sa\n", 4) == 0
		&& ft_strncmp(*str, "sb\n", 4) == 0)
		ft_util_write_free("ss\n", prev_str);
	else if (ft_strncmp(*prev_str, "sb\n", 4) == 0
		&& ft_strncmp(*str, "sa\n", 4) == 0)
		ft_util_write_free("ss\n", prev_str);
	else if (ft_strncmp(*prev_str, "ra\n", 4) == 0
		&& ft_strncmp(*str, "rb\n", 4) == 0)
		ft_util_write_free("rr\n", prev_str);
	else
		ft_stack_print_merge_3(str, prev_str);
}

void	ft_stack_print_merge(char *str)
{
	static char	*prev_str;

	if (prev_str == NULL)
	{
		if (str != NULL)
		{
			prev_str = ft_strdup(str);
			if (prev_str == NULL)
				exit(1);
		}
		return ;
	}
	if (str == NULL)
	{
		write(1, prev_str, ft_strlen(prev_str));
		free(prev_str);
		return ;
	}
	else
	{
		ft_stack_print_merge_2(&str, &prev_str);
	}
}
