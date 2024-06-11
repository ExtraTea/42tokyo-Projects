/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:43:45 by dtakamat          #+#    #+#             */
/*   Updated: 2024/05/07 21:19:56 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phi.h"

int	pmu(pthread_mutex_t *p)
{
	return (pthread_mutex_unlock(p));
}

void	*grim(void *p_info)
{
	struct timeval	now;
	struct timeval	lastmeal;
	int				i;

	while (1)
	{
		i = 0;
		while (i < (*(t_phi **)p_info)[0].uni->n_phi)
		{
			if (philosophers_rw_end((*(t_phi **)p_info), 'r') == 1)
				return (NULL);
			philosophers_rw_time(&((*(t_phi **)p_info)[i]), 'r', &lastmeal);
			gettimeofday(&(now), NULL);
			if (get_elspsed_time(lastmeal, now) > (*(t_phi **)p_info)[i].ttd)
			{
				philosophers_print(&((*(t_phi **)p_info)[i]), "died", 1);
				i = -1;
				while (++i < (*(t_phi **)p_info)[0].uni->n_phi)
					pmu(&(((*(t_phi **)p_info)->uni->fork)[i]));
				return (NULL);
			}
			i++;
		}
		usleep(10);
	}
}
