/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:34:53 by dtakamat          #+#    #+#             */
/*   Updated: 2024/05/06 18:34:53 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phi.h"

void	clean_uni(t_uni **uni)
{
	if (*uni == NULL)
		return ;
	pthread_mutex_destroy(&((*uni)->print_lock));
	pthread_mutex_destroy(&((*uni)->rw_lock));
	free((*uni)->fork);
	free(*uni);
	return ;
}

void	cleanup_all(t_phi **phi_info, pthread_t **phis)
{
	pthread_mutex_unlock(&((*phi_info)[0].uni->print_lock));
	pthread_mutex_destroy(&((*phi_info)[0].uni->print_lock));
	pthread_mutex_unlock(&((*phi_info)[0].uni->rw_lock));
	pthread_mutex_destroy(&((*phi_info)[0].uni->rw_lock));
	destroy_fork((*phi_info)[0].uni->fork, (*phi_info)[0].uni->n_phi);
	destroy_rw_lock(phi_info, (*phi_info)[0].uni->n_phi);
	free((*phi_info)[0].uni->fork);
	free((*phi_info)[0].uni);
	free(*phi_info);
	free(*phis);
}

void	destroy_fork(pthread_mutex_t *thread, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		pthread_mutex_unlock(&(thread[i]));
		pthread_mutex_destroy(&(thread[i]));
		i++;
	}
}

void	destroy_rw_lock(t_phi **phi_info, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		pthread_mutex_unlock(&((*phi_info)[i].ind_rw_lock));
		pthread_mutex_destroy(&((*phi_info)[i].ind_rw_lock));
		i++;
	}
}
