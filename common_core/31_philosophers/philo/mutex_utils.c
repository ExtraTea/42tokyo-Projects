/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinkpad-wsl <thinkpad-wsl@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:49:03 by dtakamat          #+#    #+#             */
/*   Updated: 2024/05/07 15:10:11 by thinkpad-ws      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phi.h"

void	philosophers_rw_time(t_phi *phi_info, char mode, struct timeval *time)
{
	pthread_mutex_lock(&(phi_info->ind_rw_lock));
	if (mode == 'r')
	{
		*time = phi_info->last_meal;
	}
	else if (mode == 'w')
	{
		phi_info->last_meal = *time;
	}
	else
		printf("ERROR");
	pthread_mutex_unlock(&(phi_info->ind_rw_lock));
}

int	philosophers_rw_end(t_phi *phi_info, char mode)
{
	int	ret;

	ret = 0;
	pthread_mutex_lock(&(phi_info->uni->rw_lock));
	if (mode == 'r')
	{
		ret = phi_info->uni->end;
	}
	else if (mode == 'w')
		phi_info->uni->end = 1;
	else
		printf("ERROR");
	pthread_mutex_unlock(&(phi_info->uni->rw_lock));
	return (ret);
}

void	philosophers_print(t_phi *phi_info, char *str, int end)
{
	struct timeval	time;

	pthread_mutex_lock(&(phi_info->uni->print_lock));
	if (philosophers_rw_end(((t_phi *)phi_info), 'r') == 1)
	{
		pthread_mutex_unlock(&(phi_info->uni->print_lock));
		return ;
	}
	gettimeofday(&(time), NULL);
	printf("%ld ", (time.tv_sec - phi_info->uni->start.tv_sec) * 1000
		+ (time.tv_usec - phi_info->uni->start.tv_usec) / 1000);
	printf("%d %s\n", phi_info->name + 1, str);
	if (end)
		philosophers_rw_end((phi_info), 'w');
	pthread_mutex_unlock(&(phi_info->uni->print_lock));
}

long	get_elspsed_time(struct timeval start, struct timeval now)
{
	return ((now.tv_sec - start.tv_sec) * 1000L
		+ (now.tv_usec - start.tv_usec) / 1000L);
}
