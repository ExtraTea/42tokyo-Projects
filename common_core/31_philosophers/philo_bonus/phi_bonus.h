/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:50:34 by dtakamat          #+#    #+#             */
/*   Updated: 2024/05/07 16:53:25 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHI_BONUS_H
# define PHI_BONUS_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>
# include <stdio.h>
# include <limits.h>
# include <sys/time.h>
# include <semaphore.h>

typedef struct s_phi
{
	int				ttd;
	int				tte;
	int				tts;
	int				n_tpme;
	int				n_eat;
	int				name;
	struct timeval	last_meal;
	sem_t			*sem;
	
}	t_phi;

int		ft_atoi(const char *nptr);
long	ft_atol(const char *nptr);

#endif