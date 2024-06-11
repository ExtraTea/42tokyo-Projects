/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   rush01.c										   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: dtakamat <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/02/18 10:04:11 by dtakamat		  #+#	#+#			 */
/*   Updated: 2024/02/18 11:02:06 by dtakamat         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ftutil.h"

int		factorial(int n);
void	swap(int *x, int *y);
void	permute_util(t_PermuteData *data);
int		**permute(int n, int *return_size);
int		val_col(int *nums, int top, int bottom, int dim);
void	swap2(int **a, int **b);
int		partition(int **array, int low, int high);
void	quick_sort(int **array, int low, int high);
int		***make_permutation(int dim, int *top, int *bottom);
void	print_2darray(int **array, int size);
int		val_col(int *nums, int top, int bottom, int dim);
int		validate_rows(t_RowValidationData *data);
int		check_column_for_unique(int **array, int rows, int col);
int		**r_co(int **array, int size, int n, int *newColumn);
int		**recursive(t_RecursiveData *data);

int	val_mat(int **c_mat, int *left, int *right, int dim)
{
	int					i;
	t_RowValidationData	data;

	i = 0;
	while (i < dim)
	{
		data = (t_RowValidationData){c_mat, left[i],
			right[i], dim + 1, i};
		if (!validate_rows(&data))
			return (0);
		i++;
	}
	return (1);
}

int	**process_perm(t_RecursiveData *d)
{
	int				**n_mat;
	int				**result;
	t_RecursiveData	newdata;
	int				i;

	i = 0;
	result = NULL;
	while (i < factorial(d->dim + 1))
	{
		if (d->perm[d->c_di][i][0] != -1)
		{
			n_mat = r_co(d->c_mat, d->dim + 1, d->c_di, d->perm[d->c_di][i++]);
			if (!check_column_for_unique(n_mat, d->dim + 1, d->c_di))
				continue ;
			newdata = *d;
			newdata.c_mat = n_mat;
			newdata.c_di += 1;
			result = recursive(&newdata);
			if (result != NULL)
				return (result);
		}
		else
			break ;
	}
	return (NULL);
}

int	**recursive(t_RecursiveData *data)
{
	if (data->c_di == data->dim + 1)
	{
		if (val_mat(data->c_mat, data->left, data->right, data->dim+1))
			return (data->c_mat);
		else
			return (NULL);
	}
	else
	{
		return (process_perm(data));
	}
	return (NULL);
}

int main() {
	int dim = 6;
	int return_size = factorial(dim);
	int top[] = {3,3,2,2,1,2};
	int bottom[] = {1,2,2,3,4,3};
	int left[] = {4,2,2,2,2,1};
	int right[] = {2,1,2,3,4,3};
	int ***perm = make_permutation(dim, top, bottom);
	int **array = (int**)malloc(dim * sizeof(int*));
	for (int i = 0; i < dim; i++) {
		array[i] = (int*)malloc(dim * sizeof(int));
		for (int j = 0; j < dim; j++) {
			array[i][j] = 0;
		}
	}
	t_RecursiveData data = {array, perm, left, right, dim-1, 0};
	array = recursive(&data);
	print_2darray(array, dim);
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < return_size; j++) {
			free(perm[i][j]);
		}
		free(perm[i]);
	}
	free(perm);
}
