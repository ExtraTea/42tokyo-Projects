/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_action.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:52:29 by dtakamat          #+#    #+#             */
/*   Updated: 2024/05/07 20:32:13 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phi.h"

long	get_elspsed_time_us(struct timeval start, struct timeval now)
{
	return ((now.tv_sec - start.tv_sec) * 1000000L
		+ (now.tv_usec - start.tv_usec));
}

void	philosophers_sleep(t_phi *phi_info)
{
	struct timeval	now;

	gettimeofday(&(now), NULL);
	philosophers_print(phi_info, "is sleeping", 0);
	gettimeofday(&(now), NULL);
	usleep(phi_info->tts * 1000);
	gettimeofday(&(now), NULL);
	phi_info->last_action = now;
}

void	philosophers_think(t_phi *phi_info)
{
	struct timeval	now;

	philosophers_print(phi_info, "is thinking", 0);
	gettimeofday(&(now), NULL);
	phi_info->last_action = now;
}

void	philosophers_eat2(t_phi *phi_info, int fork[2])
{
	struct timeval	now;

	if (((t_phi *)phi_info)->n_tpme != -1 && ++((t_phi *)phi_info)->n_eat
		== ((t_phi *)phi_info)->n_tpme)
		((t_phi *)phi_info)->uni->finished_eating++;
	if (((t_phi *)phi_info)->uni->finished_eating
		== ((t_phi *)phi_info)->uni->n_phi)
		philosophers_print(phi_info, "is eating", 1);
	else
		philosophers_print(phi_info, "is eating", 0);
	gettimeofday(&now, NULL);
	philosophers_rw_time(phi_info, 'w', &now);
	if (philosophers_rw_end(phi_info, 'r') != 1)
	{
		usleep(phi_info->tte * 1000);
		gettimeofday(&(now), NULL);
		phi_info->last_action = now;
	}
	pthread_mutex_unlock(&((phi_info->uni->fork)[fork[0]]));
	pthread_mutex_unlock(&((phi_info->uni->fork)[fork[1]]));
}

void	philosophers_eat(t_phi *phi_info, int fork[2])
{
	if (phi_info->name % 2 == 1)
		usleep(300);
	pthread_mutex_lock(&((phi_info->uni->fork)[fork[0]]));
	if (philosophers_rw_end(((t_phi *)phi_info), 'r') == 1)
		return ;
	philosophers_print(phi_info, "has taken a fork", 0);
	pthread_mutex_lock(&((phi_info->uni->fork)[fork[1]]));
	if (philosophers_rw_end(((t_phi *)phi_info), 'r') == 1)
		return ;
	philosophers_print(phi_info, "has taken a fork", 0);
	philosophers_eat2(phi_info, fork);
}
