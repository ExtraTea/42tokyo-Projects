/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftutil.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 05:55:04 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/18 05:55:05 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTUTIL_H
# define FTUTIL_H

typedef struct s_PermuteData{
	int	*a;
	int	**result;
	int	*index;
	int	l;
	int	r;
}	t_PermuteData;

typedef struct s_RowValidationData{
	int	**nums;
	int	left;
	int	right;
	int	dim;
	int	depth;
}	t_RowValidationData;

typedef struct s_RecursiveData
{
	int	**c_mat;
	int	***perm;
	int	*left;
	int	*right;
	int	dim;
	int	c_di;
}	t_RecursiveData;

#endif // PERMUTE_H
