/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:54:41 by dtakamat          #+#    #+#             */
/*   Updated: 2024/05/04 12:25:39 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_stack{
	int				num;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

t_stack	*ft_stack_create_elem(int num);
int		ft_stack_add(t_stack **stack, int num);
int		ft_stack_remove(t_stack **stack);
int		ft_stack_count_elem(t_stack *stack);

int		ft_stack_swap(t_stack *stack, char *str);
int		ft_stack_swap_dual(t_stack *stack1, t_stack *stack2, char *str);

t_stack	*ft_stack_get_bottom(t_stack *stack);
int		ft_stack_rotate(t_stack **stack, char *str);
int		ft_stack_rotate_dual(t_stack **stack1, t_stack **stack2, char *str);
int		ft_stack_rev_rotate(t_stack **stack, char *str);
int		ft_stack_rev_rotate_dual(t_stack **stack1, t_stack **stack2, char *str);
int		ft_stack_push(t_stack **stack_to, t_stack **stack_from, char *str);
int		ft_stack_push_dual(t_stack **stack1, t_stack **stack2, char *str);

long	ft_atol(const char *nptr);
t_stack	*ft_stack_free(t_stack **stack);
t_stack	*ft_get_stack(int ac, char **av);

int		ft_is_all_digit(int ac, char **av);
int		ft_abs(int a);
int		ft_max(int a, int b);
int		ft_min(int a, int b);

void	ft_sort_int_tab(int *tab, int size,
			int (*compare)(const void *, const void *));

void	ft_sort_large(t_stack **stack_a, t_stack **stack_b, int elem_num);
void	ft_sort_middle(t_stack **stack_a, t_stack **stack_b, int elem_num);
void	ft_sort_small(t_stack **stack_a, t_stack **stack_b, int elem_num);

void	find_one_third_two_thirds_sorted(t_stack *head,
			int num_elements, int *one_third_value, int *two_thirds_value);
void	find_median_sorted(t_stack *head, int elem_num, int *median);
void	find_median_sorted_from_end(t_stack *last, int elem_num, int *median);

void	ft_sort_case_just_3a(t_stack **stack);
void	ft_sort_case_3a(t_stack **stack);
void	ft_sort_case_3b(t_stack **stack);
void	ft_sort_case_5(t_stack **stack_a, t_stack **stack_b);

int		ft_is_sorted(t_stack *stack);
int		compare_ints(const void *a, const void *b);
void	ft_stack_print_merge(char *str);
#endif
